#include <iostream>
#include "Vetores.h"

using namespace std;

int main(){
    cout << "-----------Vetores------------" << endl;

    vetor A(3), B(3), C;

    cout << "A:" << endl;
    cin >> A;

    cout << "B:" << endl;
    cin >> B;

    cout << A[1] << endl;
    A[1] = 7;
    cout << A << endl;

    C = A+B;
    cout << C << endl;

    C = A-B;
    cout << C << endl;

    C = -A;
    cout << C << endl;

    cout << A*B << endl;

    cout << C.norma() << endl;

    cout << "-----------Matrizes------------" << endl;

    matriz D(3,3), E(3,3), F;

     cout << "D:" << endl;
     cin >> D;
     cout << D << endl;

    cout << "E:" << endl;
    cin >> E;
    cout << E << endl;

    F = D+E;
    cout << F << endl;

    F = D-E;
    cout << F << endl;

    F = -D;
    cout << F << endl;

    matriz x;
    vetor y;

    x = D*E;
    y = D*A;

    cout << x << endl;
    cout << y << endl;

    cout << D[1][1] << endl;
    D[1][1] = 7;
    cout << D[1][1] << endl;

    return 0;
}
