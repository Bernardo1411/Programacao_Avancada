#include <iostream>
#include <cmath>
#include "class.h"

using namespace std;

istream &operator>>(istream &ent, complexo &C){

    cout << "Insira a parte real:";
    ent >> C.real;

    cout << "Insira a parte imaginaria:";
    ent >> C.imag;

    return ent;
}

ostream &operator<<(ostream &said, const complexo &c){

    said << c.real << (c.imag<0.0?'-':'+') << 'j' << c.imag << endl;

    return said;
}

complexo complexo::operator+(const complexo &c2) {

    complexo prov;
    prov.real = real+c2.real;
    prov.imag = imag+c2.imag;

    return prov;
}

complexo complexo::operator*(const complexo &c2){

    complexo prov;
    prov.real = real*c2.real - imag*c2.imag;
    prov.imag = real*c2.imag + c2.real*imag;

    return prov;
}

