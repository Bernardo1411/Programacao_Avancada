#include <iostream>
#include "vetor.h"
#include <cmath>


void Vetor::destruir(){
    if(p!=NULL){
    delete[] p;
    p=NULL;
    }
    n=0;
}

void Vetor::criar(int num){
   n = num;
   p = (n>0? new double[n]:NULL);
}

void Vetor::copiar(const Vetor &v){
    criar(v.n);
    for(int i=0; i<n; i++) p[i] = v.p[i];
}

Vetor::Vetor(int num){
    criar(num);
    for(int i=0; i<num; i++) p[i]=0.0;
}

 void Vetor::operator=(const Vetor &v){
    if(this != &v){

        if(this->n == v.n){
                for (int i=0; i<n; i++) p[i] = v.p[i];
        }
        else{
        destruir();
        copiar(v);
        }
    }
 }

double Vetor::operator[](int i) const{

    if(i>n){
        cerr << "Indice incompativel\n";
        return 0.0;
    }

    return p[i];
}

 double &Vetor::operator[](const int i){

    static double prov = 0.0;
    if(i>n){
        cerr << "Indice incompativel\n";
        return prov;
    }
    return p[i];
}

 ostream &operator<<(ostream &saida, const Vetor &v){
      saida << '[';

      for(int i=0; i<v.n; i++) saida << v.p[i] << (i+1==v.n?']':';');

      saida << "\n";

      return saida;
 }

 istream &operator>>(istream &entrada, Vetor &v){
      for(int i=0; i<v.n; i++) entrada >> v.p[i];

      return entrada;
 }

Vetor Vetor::operator+(const Vetor &v)const{

    Vetor prov(n);

    if(n!=v.n){
        cerr << "Vetores de tamanhos diferentes /n";
        return Vetor();
    }

    for(int i=0; i<n; i++) prov[i] = p[i]+v.p[i];

    return prov;
    }

Vetor Vetor::operator-(const Vetor &v)const{
    Vetor prov(n);

    if(n!=v.n){
        cerr << "Vetores de tamanhos diferentes /n";
        return Vetor();
    }

    for(int i=0; i<n; i++) prov[i] = p[i]-v.p[i];

    return prov;
    }

Vetor Vetor::operator-()const{
    Vetor prov(n);

    for(int i=0; i<n; i++) prov.p[i] = -p[i];

    return prov;
    }
