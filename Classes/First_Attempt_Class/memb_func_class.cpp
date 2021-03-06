#include <iostream>
#include <cmath>
#include "classe_complex.h"

using namespace std;

complexo::complexo(): real(0.0), imag(0.0)
{
}

complexo::complexo(double R): real(R), imag(0.0)
{
}

complexo::complexo(double R, double I): real(R), imag(I)
{
}

void complexo::ler(){

cout << "Insira a parte real:";
cin>> real;

cout << "Insira a parte imaginaria:";
cin>> imag;

}

complexo complexo::operator+(complexo C2) const{

    complexo prov;
    prov.real = real+C2.real;
    prov.imag = imag+C2.imag;

    return prov;

}

complexo complexo::operator*(complexo C2) const{

  complexo prov;
  prov.real = real*C2.real - imag*C2.imag;
  prov.imag = real*C2.imag + C2.real*imag;
  return prov;

}

void complexo::imprimir() const{

    cout << real << (imag < 0.0 ? "-" : "+") << "j" << imag <<  endl;

}
