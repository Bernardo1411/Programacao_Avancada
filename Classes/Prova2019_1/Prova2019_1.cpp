#include <iostream>
#include "prova2019_1.h"

using namespace std;

ostream &operator<<(ostream &saida, ponto &p){

    saida << '[' << p.x << ';' << p.y << ']' << endl;

    return saida;
}

istream &operator>>(istream &entrada, ponto &p){
    cout << "Eixo x: ";
    entrada >> p.x;

    cout << "Eixo y: ";
    entrada >> p.y;

    return entrada;
}

void linha::criar(int num){
    if(num<=0){
        cerr << "Dimensao Invalida!";
        point = NULL;
        n=0;
    }
    else{
        n = num;
        point = new ponto[n];
        for(int i=0; i<n; i++) point[i]=0.0;
    }
}

void linha::limpar(){
    delete[] point;
    if(point!=NULL && n>0) point=NULL;
    n=0;
}

void linha::copiar(const linha &l){
    criar(l.n);
    for(int i=0; i<n; i++) point[i] = l.point[i];
}

ostream &operator<<(ostream &saida, linha &l){

    for(int i=0; i<l.n; i++) saida << l.point[i];

    return saida;
}

istream &operator>>(istream &entrada, linha &l){

    for(int i=0; i<l.n; i++) entrada >> l.point[i];

    return entrada;
}

void linha::adicionar(ponto &p){
    linha prov(n+1);

    for(int i=0; i<n; i++)prov.point[i] = point[i];

    prov.point[n] = p;

    copiar(prov);
    prov.limpar();

}

linha linha::operator+(const linha &l)const{
    linha prov(n+l.n);

    for(int i=0; i<n; i++) prov.point[i] = point[i];
    for(int i=n; i<l.n+n; i++) prov.point[i] = l.point[i-n];

    return prov;
}

void linha::operator=(const linha &l){
    if(this != &l){
        if(n==l.n){
            for(int i=0; i<n; i++){
                point[i] = l.point[i];
            }
        }
        else{
            limpar();
            copiar(l);
        }
    }
}
