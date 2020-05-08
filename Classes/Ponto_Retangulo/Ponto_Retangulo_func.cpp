#include <iostream>
#include "PontoRetangulo.h"
#include <cmath>

using namespace std;

ponto::ponto(const ponto &p){
x=p.x;
y=p.y;
}

void ponto::imprimir(ostream &saida){

    saida << x << "x, " << y << "y \n";

}

ostream &operator<<(ostream &saida, ponto &p){

     p.imprimir(saida);

    return saida;
}

double ponto::distancia(const ponto &p) const{

     return sqrt(pow(x+p.x,2) + pow(y+p.y,2));
}


retangulo::retangulo(){
inf.x = 0.0;
inf.y = 0.0;
sup.x = 0.0;
sup.y = 0.0;
}

retangulo::retangulo(double xinf, double xsup, double yinf, double ysup){

    if(xinf>xsup){
        double prov = xinf;
        xinf = xsup;
        xsup = prov;
    }
    if(yinf>ysup){
        double prov = yinf;
        yinf = ysup;
        ysup = prov;
    }

    inf.x = xinf;
    inf.y = yinf;
    sup.x = xsup;
    sup.y = ysup;
}

double retangulo::area() const{

    return sqrt(pow(sup.x-inf.x,2))*sqrt(pow(sup.y-inf.y,2));

}

bool retangulo::pontoInterno(const ponto &p)const{

    return (p.x>=inf.x && p.x<=sup.x && p.y>=inf.y && p.y<=sup.y);

}

bool ponto::operator<(retangulo &r) {

    return r.pontoInterno(*this);

}

