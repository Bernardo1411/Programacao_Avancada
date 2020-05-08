#ifndef Vetor_H
#define Vetor_H

#include <iostream>

using namespace std;

class Vetor{
private:
    int n;
    double *p;
    void destruir();
    void criar(int);
    void copiar(const Vetor &v);
public:
    inline Vetor(): n(0), p(NULL){}
    explicit Vetor(int num);
    inline Vetor(const Vetor &v) {copiar(v);}
    inline ~Vetor(){destruir();}
    void operator=(const Vetor &v);

    inline int getn() const{return n;}
    double operator[](int) const;
    double &operator[](const int);

    friend ostream &operator<<(ostream &saida, const Vetor &v);
    friend istream &operator>>(istream &entrada, Vetor &v);

    Vetor operator+(const Vetor &v) const;
    Vetor operator-(const Vetor &v) const;
    Vetor operator-()const;

    //double norma();
    //double escalar(const Vetor &v);
};

#endif // Vetor_H
