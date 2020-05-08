#ifndef VETOR_BOOL_H
#define VETOR_BOOL_H

#include <iostream>

using namespace std;

class vbool{
private:
    int n;
    bool *p;
    void criar(int num);
    void copiar(const vbool &v);
    void limpar();
public:
    inline vbool(): n(0), p(NULL){}
    explicit inline vbool(int num){criar(num);}
    inline vbool(const vbool &v){copiar(v);}
    inline ~vbool(){limpar();}
    void operator=(vbool &v);

    inline int getN() const {return n;}
    bool operator[](int num) const;
    bool &operator[](int num);

    friend ostream &operator<<(ostream &saida, vbool &v);
    friend istream &operator>>(istream &entrada, vbool &v);

};

#endif // VETOR_BOOL_H
