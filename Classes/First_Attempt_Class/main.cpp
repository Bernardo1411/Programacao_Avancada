#include <iostream>
#include "classe_complex.h"

using namespace std;

int main()
{   complexo C1, C2, S, P;

    cout << "Insira o complexo 1:";
    C1.ler();
    cout << "Insira o complexo 2:";
    C2.ler();

    S = C1+C2;
    P = C1.operator*(C2);

    S.imprimir();
    P.imprimir();

    return 0;
}
