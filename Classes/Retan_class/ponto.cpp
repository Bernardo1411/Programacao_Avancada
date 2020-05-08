#include <iostream>
#include <cmath>
#include "ponto.h"

using namespace std;

double ponto::dist(const ponto &p2) const
{
    return sqrt(pow((x-p2.x),2) + pow((y-p2.y),2));
}

double ponto::area(const ponto &p2) const
{
    return (x-p2.x)*(y-p2.y);
}

ostream &operator<<(ostream &saida, const ponto &p) {

return saida << p.x << 'x' << '-' << p.y << 'y' << endl;

}
