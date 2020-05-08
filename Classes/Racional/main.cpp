#include <iostream>
#include "racional.h"

using namespace std;

int main()
{   racional R1(1,2), R2, R3;

    cout << "Racional 2: \n";
    cin >> R2;

    R3 = R1+R2;
    cout << R3;

    R3 = R1-R2;
    cout << R3;

    R3 = -R1;
    cout << R3;

    R3 = R1*R2;
    cout << R3;

    R3 = R1/R2;
    cout << R3;

    return 0;
}
