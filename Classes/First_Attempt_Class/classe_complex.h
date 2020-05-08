#include<iostream>

class complexo{
private:
    double real, imag;
public:
    complexo();
    complexo(double R);
    complexo(double R, double I);

    inline double getReal() {return real;};
    inline double getImag() {return imag;};

    void ler();
    void imprimir() const;
    complexo operator+(complexo C2) const;
    complexo operator*(complexo C2) const;

};
