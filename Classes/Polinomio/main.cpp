#include <iostream>
#include "poly.h"

using namespace std;

int main()
{  int n1, n2;

    cout << "Insira o grau de P1: ";
    cin >> n1;

    cout << "Insira o grau de P2: ";
    cin >> n2;

    poly P1(n1), P2(n2), S, P;

    cout << "P1: " << endl;
    cin >> P1;

    cout << "P2: " << endl;
    cin >> P2;

    cout << P1 << endl;
    cout << P2 << endl;

    S = P1+P2;

    cout << S(-3) << endl;

    P = P1*P2;

    cout << P << endl;

    return 0;
}
