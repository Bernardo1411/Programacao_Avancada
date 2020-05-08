#include <iostream>
#include "poly.h"
#include<cmath>

using namespace std;

poly::poly(int num){
    n = (num<0?0:num+1);
    p = (num<0?NULL:new double[n]);
    for(int i=0; i<n; i++) p[i] = 0.0;
}

poly::poly(const poly &pol){
    delete[] p;
    p = NULL;
    n = pol.n;
    p = new double[n];
    for(int i=0; i<n; i++) p[i] = pol.p[i];
}

poly::~poly(){
    if(p!=NULL){
        delete[] p;
        p = NULL;
        n=0.0;
    }
}

void poly::operator=(const poly &pol){
    if(this!=&pol){
        if(n!=pol.n){
            delete[] p;
            n = pol.n;
            p = new double[n];
        }
    for(int i=0; i<n; i++) p[i] = pol.p[i];
    }
}

double poly::operator()(int num)const{
    double soma = 0.0;
    for(int i=0; i<n; i++) soma += pow(num,i)*p[i];

    return soma;
}

poly poly::operator+(const poly &pol) const
{
  poly prov(max(n,pol.n));
  for (int i=0; i<prov.n; i++)
  {
    prov.p[i] = (i<n ? p[i] : 0.0) + (i<=pol.n ? pol.p[i] : 0.0);
  }
  while (prov.p[prov.n]==0.0 && prov.n>0)
  {
    prov.n--;
  }
  return prov;
}

poly poly::operator*(const poly &pol) const{

    poly prov(max(n,pol.n));
    for(int i=0; i<prov.n; i++){
        for(int j=0; j<pol.n; j++) prov.p[i] += p[i]*pol.p[j];
    }

    return prov;
}

ostream &operator<<(ostream &saida, poly &pol){
    saida << pol.p[0] << (pol.n>0?'+':' ');
    for(int i=1; i<pol.n; i++) saida << pol.p[i] << "x^" << i <<(i==(pol.n)-1?' ':'+');

    return saida;
}

istream &operator>>(istream &entrada, poly &pol){
    for(int i=0; i<pol.n;i++) entrada >> pol.p[i];

    return entrada;
}
