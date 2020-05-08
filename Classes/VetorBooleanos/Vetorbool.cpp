#include <iostream>
#include "vetorbool.h"

using namespace std;

void vbool::criar(int num){

    n = num;
    p = (n<=0?NULL:new bool[n]);
    for(int i=0; i<n; i++) p[i] = 0;
}

void vbool::copiar(const vbool &v){
    limpar();
    criar(v.n);
    for(int i=0; i<n; i++) p[i]= v.p[i];
}

void vbool::limpar(){
    if(n>0){
        delete[] p;
        n=0;
        p=NULL;
    }
}

bool vbool::operator[](int num)const{
    if(num>n){
        cerr << "Indice indisponivel!" << endl;
        return 0;
    }
    else{
        return p[num];
    }
}

bool &vbool::operator[](int num){
    bool static prov=0;
    if(num>n){
        cerr << "Indice indisponivel!" << endl;
        return prov;
    }
    else{
        return p[num];
    }
}

ostream &operator<<(ostream &saida, vbool &v){
    saida << '[';
    for(int i=0; i<v.n; i++) saida << v.p[i] << (i+1==v.n?']':';');

    return saida;
}

istream &operator>>(istream &entrada, vbool &v){

    for(int i=0; i<v.n; i++) entrada >> v.p[i];

    return entrada;
}

void vbool::operator=(vbool &v){

    if(this->p!=v.p){
        if(v.n==n){
            for(int i=0; i<n; i++) p[i] = v.p[i];
        }
        else{
            limpar();
            copiar(v);
        }
    }
}
