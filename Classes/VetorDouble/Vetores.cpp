#include <iostream>
#include "Vetores.h"
#include <cmath>

using namespace std;

void vetor::criar(int num){
    n=num;
    if(num<0){
        cerr << "Valor Incompativel" << endl;
        p = NULL;
    }
    else{
    p = new double[n];
    for(int i = 0; i<n; i++) p[i] = 0.0;
    }
}

void vetor::copiar(const vetor &v){

    criar(v.n);
    for(int i=0; i<n; i++) p[i] = v.p[i];

}

void vetor::limpar(){

    if(p!=NULL){
    delete[] p;
    n=0;
    p=NULL;
    }
}

vetor::vetor(const vetor &v){
    copiar(v);
}

double vetor::operator[](int num)const{

    if(num>n-1){
        cerr << "Indice indisponivel" <<  endl;
        return 0.0;
    }
    else{
        return p[num];
    }
}

double &vetor::operator[](int num){

    double static prov = 0.0;
    if(num>n-1){
        cerr << "Indice indisponivel" <<  endl;
        return prov;
    }
    else{
        return p[num];
    }
}

ostream &operator<<(ostream &saida, vetor &v){

    saida << '[';
    for(int i=0; i<v.n; i++) saida << v.p[i] << (i+1==v.n ? ']':';');

    return saida;
}

istream &operator>>(istream &entrada, vetor &v){

    cout << "Insira os elementos:";
    for(int i=0; i<v.n; i++) entrada >> v.p[i];

    return entrada;
}

vetor vetor::operator+(const vetor &v) const{

    vetor prov(n);

    if(n!=v.n){
        cerr << "Tamanhos nao compativeis" << endl;
        return vetor ();
    }
    else{
      for(int i=0;i<n; i++) prov.p[i] = p[i]+v[i];
      return prov;
    }
}

vetor vetor::operator-(const vetor &v) const{

    if(n!=v.n){
        cerr << "Tamanhos nao compativeis" << endl;
        vetor prov;
        return prov;
    }
    else{
      vetor prov(n);
      for(int i=0;i<n; i++) prov.p[i] = p[i]-v[i];
      return prov;
    }
}

vetor vetor::operator-(){

      vetor prov(n);
      for(int i=0;i<n; i++) prov.p[i] = -p[i];
      return prov;
}

double vetor::operator*(const vetor &v) const{

    double prov = 0.0;

    if(n!=v.n){
        cerr << "Tamanhos nao compativeis" << endl;
        return prov;
    }
    else{
      for(int i=0;i<n; i++) prov = prov + p[i]*v.p[i];
      return prov;
    }
}

void vetor::operator=(const vetor &v){

    if(this!=&v){
        if(v.n == this->n){
            for(int i=0; i<n; i++) p[i] = v.p[i];
        }
        else{
            this->limpar();
            this->copiar(v);
        }
    }
}

double vetor::norma() const{

    double prov = 0.0;

    for(int i=0;i<n; i++) prov = prov + p[i]*p[i];
    return sqrt(prov);
}

void matriz::criar(int nl, int nc){
    if(nl<=0||nc<=0){
        cerr << "Dimensao inadequada" << endl;
        ptr=NULL;
        m=0;
    }
    else{
        m=nl;
        ptr = new vetor[nl];
        for(int i=0; i<nl; i++) ptr[i] = vetor(nc); // Construtor???
    }
}

void matriz::copiar(const matriz &M){
    if(M.m>0){
        criar(M.m,M.ptr->n);
        for(int i=0; i<m; i++) ptr[i] = M.ptr[i];
    }
    else{
        ptr=NULL;
    }
}

void matriz::limpeza(){

    delete[] ptr;
    ptr=NULL;
    m=0;
}

matriz matriz::operator+(const matriz &M) const{
    matriz prov(M.m, M.ptr->n);
    if(M.m!=m){
        cerr << "Dimensoes difenrntes!" << endl;
        return prov;
    }
    else{
        for(int i=0; i<m; i++){
            prov.ptr[i] = this->ptr[i] + M.ptr[i];
            //cout << "i = " << i << endl;
        }
        return prov;
    }
}

matriz matriz::operator-(const matriz &M) const{

    matriz prov(M.m, M.ptr->n);
    if(M.m!=m){
        cerr << "Dimensoes difenrntes!" << endl;
        return prov;
    }
    else{
        for(int i=0; i<m; i++) prov.ptr[i] = ptr[i]-M.ptr[i];
        return prov;
    }
}

matriz matriz::operator-() const{

    matriz prov(m, ptr->n);

        for(int i=0; i<m; i++) prov.ptr[i] = -ptr[i];
        return prov;
}

matriz matriz::operator*(const matriz &M) const{

    matriz prov(ptr->n, M.m);
    if(M.m!=ptr->n){
        cerr << "Dimensoes Incompatíveis!" << endl;
        return prov;
    }
    else{
        for(int i=0; i<m; i++){
            for(int j=0; j<m; j++){
                    prov.ptr[i].p[j] = ptr[i].p[j]*M.ptr[i].p[j];
                }
            }
    return prov;
    }
}

matriz matriz::transposta() const{

    matriz prov(ptr->n, m);
    for(int i=0; i<m; i++){
            for(int j=0; j<m; j++){
                    prov.ptr[i].p[j] = ptr[j].p[i];
                }
            }
    return prov;
}

vetor matriz::operator*(const vetor &v) const{
    vetor prov(v.n);
    if(v.n!=ptr->n){
        cerr << "Dimensoes Incompatíveis!" << endl;
        return prov;
    }
    else{
        for(int i=0; i<m; i++){
            for(int j=0; j<m; j++){
                    prov.p[i] = ptr[i].p[j]*v[i];
                }
            }
    return prov;
    }
}

void matriz::operator=(const matriz &M){
    if(this->ptr != M.ptr){
        if(M.m==m && M.ptr->n==ptr->n){
            for(int i=0; i<m; i++){
                for(int j=0; j<ptr->n; j++){
                    ptr[i].p[j] = M.ptr[i].p[j];
                }
            }
        }
        else{
            limpeza();
            copiar(M);
        }
    }
}

vetor matriz::operator[](int nl)const{
    vetor prov;
    if(nl>m){
        cerr << "Indice indisponivel!"<<endl;
        return prov;
    }

    return ptr[nl];
}

vetor &matriz::operator[](int nl){
    vetor static prov;
    if(nl>m){
        cerr << "Indice indisponivel!"<<endl;
        return prov;
    }

    return ptr[nl];
}

ostream &operator<<(ostream &saida, matriz &M){
    for(int i=0; i<M.m; i++) saida << M.ptr[i] << endl;

    return saida;
}

istream &operator>>(istream &entrada, matriz &M){

    for(int i=0; i<M.m; i++) entrada >> M.ptr[i];

    return entrada;

}
