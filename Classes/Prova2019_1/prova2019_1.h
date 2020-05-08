#ifndef PONTO_RETA_H
#define PONTO_RETA_H

#include <iostream>

using namespace std;

class linha;

class ponto{
private:
    double x,y;
public:
    ponto(int eixoX=0, int eixoY=0): x(eixoX), y(eixoY){}

    inline double getX(){return x;}
    inline double getY(){return y;}

    friend ostream &operator<<(ostream &saida, ponto &p);
    friend istream &operator>>(istream &entrada, ponto &p);

    friend class linha;
};

class linha{
private:
    int n;
    ponto *point;
    void criar(int num);
    void limpar();
    void copiar(const linha &l);
public:
    inline linha(): n(0), point(NULL){}
    inline explicit linha(int num){criar(num);}
    inline linha(const linha &l){copiar(l);}
    inline ~linha(){limpar();}
    void operator=(const linha &l);

    inline int getSize(){return n;}

    friend ostream &operator<<(ostream &saida, linha &l);
    friend istream &operator>>(istream &entrada, linha &l);

    void adicionar(ponto &p);

    linha operator+(const linha &l) const;

};

#endif // PONTO_RETA_H
