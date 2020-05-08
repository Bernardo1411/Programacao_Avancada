#ifndef PONTO_H
#define PONTO_H

#include<iostream>

using namespace std;

class retangulo;

class ponto{
private:
    double x,y;
public:
    inline ponto(double eixoX=0.0, double eixoY=0.0): x(eixoX), y(eixoY){}
    ponto(const ponto &p);

    void imprimir(ostream &saida);
    friend ostream &operator<<(ostream &saida, ponto &p);

    double distancia(const ponto &p) const;

    friend class retangulo;

    bool operator<(retangulo &r);
};

class retangulo{
private:
    ponto inf;
    ponto sup;
public:
    retangulo();
    retangulo(double xinf, double xsup, double yinf, double ysup);

    double area() const;

    bool pontoInterno(const ponto &p) const;

};

#endif // PONTO_H

