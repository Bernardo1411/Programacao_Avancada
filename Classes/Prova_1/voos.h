#ifndef VOO_H
#define VOO_H

#include <iostream>

using namespace std;

class ListaVoos;

class voo{
private:
    int nvoo, hsaida, hcheg;
    string strO;
    string strD;
public:
    inline voo():nvoo(0),hsaida(0), hcheg(0), strO("NaN"),strD("NaN"){}
    voo(const voo &v);

    voo getVoo(){return *this;}

    friend ostream &operator<<(ostream &saida, voo &v);
    friend istream &operator>>(istream &entrada, voo &v);

    friend class ListaVoos;

};

class ListaVoos{
private:
    int n;
    voo *p;
public:
    ListaVoos():n(0), p(NULL) {};
    explicit ListaVoos(int num);
    ListaVoos(const ListaVoos &lv);
    ~ListaVoos();
    void operator=(ListaVoos &lv);

    void inserir(voo &v);
    friend ostream &operator<<(ostream &saida, const ListaVoos &lv);
    inline void imprimir() const {cout << *this << endl;}
    void imprimir(string aero_o1);

};

#endif // VOO_H
