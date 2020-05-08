#include <iostream>
#include "vetorbool.h"

using namespace std;

int main()
{
    vbool A(4);

    cout << "A: " << endl;
    cin >> A;

    cout << A << endl;
    cout << A[1] << endl;
    A[1] = 0;

    cout << A << endl;

    vbool B(3);
    cin >> B;
    cout << B << endl;

    A = B;

    cout << A << endl;

    return 0;
}
