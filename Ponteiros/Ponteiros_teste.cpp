#include <iostream>

using namespace std;

int main(){
    int ** p;
    int nl, nc;

    cout << "Insira o numero de linhas: ";
    cin >> nl;

    cout << "Insira o numero de colunas: ";
    cin >> nc;

    p = new int*[nl];

    for(int i=0; i<nl; i++){
        p[i]= new int[nl+i];
        for(int j=0; j<nc+i; j++)
            p[i][j] = i*i+1;
    }

    for(int i=0; i<nl; i++){
        for(int j=0; j<nc+i; j++){
            cout << p[i][j];
        }
        cout << "\n";
    }

    return 0;
}
