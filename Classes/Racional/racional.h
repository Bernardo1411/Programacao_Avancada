#ifndef RACIONAL_H
#define RACIONAL_H

#include <iostream>

using namespace std;

class racional{
private:
    int n, d;
public:
    inline racional(): n(0), d(0){}
    inline racional(int num, int den): n(num), d(den){}
    inline racional(const racional &r): n(r.n), d(r.d){}

    inline int getN() {return n;}
    inline int getD() {return d;}

    racional operator+(const racional &r);
    racional operator-(const racional &r);
    racional operator-();
    racional operator*(const racional &r);
    racional operator/(const racional &r);

    friend ostream &operator<<(ostream &saida, racional &r);
    friend istream &operator>>(istream &entrada, racional &r);
};
#endif // RACIONAL_H
