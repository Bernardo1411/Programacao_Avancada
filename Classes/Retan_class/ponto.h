#include <iostream>

using namespace std;

class ponto{
private:
    double x, y;
public:
    ponto(double eixox=0.0, double eixoy=0.0): x(eixox), y(eixoy) {}
    ponto(const ponto &p): x(p.x), y(p.y) {};

    inline double getx() const {return x;}
    inline double gety() const {return y;}

    friend ostream &operator<<(ostream &saida, const ponto &p) ;

    double dist(const ponto &p2) const;
    double area(const ponto &p2) const;

};
