#include <iostream>

using namespace std;

class complexo{
private:
    double real, imag;
public:
    inline complexo(double R=0.0, double I=0.0): real(R), imag(I){};

    inline double getReal() const {return real;}
    inline double getImag() const {return imag;}

    friend istream &operator>>(istream &ent, complexo &C);
    friend ostream &operator<<(ostream &said, const complexo &C);

    complexo operator+(const complexo &c2) ;
    complexo operator*(const complexo &c2);

};
