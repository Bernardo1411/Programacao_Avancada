#include <iostream>
#include "vetor.h"

using namespace std;

int main()
{
    Vetor A(3),B(3),C;

    cout << "Vetor A: /n";
    cin >> A;
    cout << "Vetor B: /n";
    cin >> B;

    cout << A[2]<< endl;
    A[2] = 4.5;
    cout << A[2]<< endl;

    cout << B;
    B=A;
    cout << B;

    C = A+B;

    cout << C;

    cout << A-B;
    cout << -A;



    return 0;
}
