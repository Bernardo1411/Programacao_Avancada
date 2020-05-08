#ifndef VETORES_H
#define VETORES_H

#include <iostream>

using namespace std;

class matriz;

class vetor{
private:
    int n;
    double *p;
    void copiar(const vetor &v);
    void limpar();
    void criar(int num);

public:
    inline vetor(): n(0), p(NULL){}
    inline explicit vetor(int num){criar(num);}
    vetor(const vetor &v);
    inline ~vetor(){limpar();}

    double operator[](int num) const;
    double &operator[](int num);

    friend ostream &operator<<(ostream &saida, vetor &v);
    friend istream &operator>>(istream &entrada, vetor &v);

    vetor operator+(const vetor &v) const;
    vetor operator-(const vetor &v) const;
    vetor operator-();
    double operator*(const vetor &v) const;
    void operator=(const vetor &v);

    double norma() const;

    friend class matriz;
};

class matriz{
private:
    int m;
    vetor *ptr;
    void criar(int nl, int nc);
    void copiar(const matriz &M);
    void limpeza();
public:
    inline matriz(): m(0), ptr(NULL) {}
    inline explicit matriz(int nl, int nc){criar(nl, nc);}
    inline explicit matriz(int nl){criar(nl, 0);}
    inline matriz(const matriz &M){copiar(M);}
    inline ~matriz(){limpeza();}
    void operator=(const matriz &M);

    friend ostream &operator<<(ostream &saida, matriz &M);
    friend istream &operator>>(istream &entrada, matriz &M);

    inline int getM(){return m;}
    matriz operator+(const matriz &M) const;
    matriz operator-(const matriz &M) const;
    matriz operator-() const;
    matriz operator*(const matriz &M) const;
    vetor operator*(const vetor &v) const;

    vetor operator[](int nl) const;
    vetor &operator[](int nl);

    matriz transposta() const;
};

#endif // VETORES_H
