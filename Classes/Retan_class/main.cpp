#include <iostream>
#include "ponto.h"

using namespace std;

int main()
{
    ponto p1(2,3), p2(5,6);

    cout << p1;
    cout << p2;

    cout << "distancia P1 e P2: " << p1.dist(p2) << endl;
    cout << "area P1 e P2: " << p1.area(p2) << endl;

    ponto p3 = p1;

    cout << p3;

    cout << "distancia P3 e P2: " << p3.dist(p2) << endl;
    cout << "area P3 e P2: " << p3.area(p2) << endl;

    cin.get();

    return 0;
}
