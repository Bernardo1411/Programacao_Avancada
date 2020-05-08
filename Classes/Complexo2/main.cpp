#include <iostream>
#include "class.h"

using namespace std;

int main()
{
    complexo A, B, soma, mult;

    cout << "Insira o Complexo A: " << endl;
    cin >> A;
    cout << "Insira o Complexo B: " << endl;
    cin >> B;

    soma = A+B;
    mult = A*B;

    cout << soma << endl;
    cout << mult << endl;

    return 0;
}
