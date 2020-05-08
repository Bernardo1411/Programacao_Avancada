#ifndef POLY_H
#define POLY_H

#include <iostream>

using namespace std;

class poly{
private:
    int n;
    double *p;
public:
    inline poly(): n(0), p(NULL){}
    explicit poly(int num);
    poly(const poly &pol);
    ~poly();

    void operator=(const poly &pol);

    double operator()(int num) const;
    poly operator+(const poly &pol)const;
    poly operator*(const poly &pol)const;

    friend ostream &operator<<(ostream &saida,poly &pol);
    friend istream &operator>>(istream &entrada, poly &pol);
};

#endif // POLY_H
