#include <iostream>
#include "PontoRetangulo.h"

using namespace std;

int main()
{
    ponto p(1,2), p2(2,3);

    cout << p;

    cout << p.distancia(p2) << endl;

    retangulo r(1.0,2.0,3.0,4.0);

    cout << r.area() << endl;

    cout << (p2<r?"true":"false");

    return 0;
}
