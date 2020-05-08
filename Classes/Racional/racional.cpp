#include <iostream>
#include "racional.h"

using namespace std;

racional racional::operator+(const racional &r){

    racional prov;

    prov.n = n*r.d + r.n*d;
    prov.d = d*r.d;

    return prov;
}

racional racional::operator-(const racional &r){

    racional prov;

    prov.n = n*r.d - r.n*d;
    prov.d = d*r.d;

    return prov;
}

racional racional::operator-(){

    racional prov;

    prov.n = -n;
    prov.d = d;

    return prov;
}

racional racional::operator*(const racional &r){

    racional prov;

    prov.n = n*r.n;
    prov.d = d*r.d;

    return prov;
}

racional racional::operator/(const racional &r){

    racional prov;

    prov.n = n*r.d;
    prov.d = d*r.n;

    return prov;
}

ostream &operator<<(ostream &saida, racional &r){

        saida << r.n << "/" << r.d << "\n";
        return saida;
}

istream &operator>>(istream &entrada, racional &r){
    cout << "Numerador: ";
    entrada >> r.n;

    cout << "Denominador: ";
    entrada >> r.d;

    return entrada;

}
