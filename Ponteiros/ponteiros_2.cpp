#include <iostream>

using namespace std;

int main(){
    int** p;
    int nl, nc;

    do{
    cout << "Insira o numero de linhas: ";
    cin >> nl;

    cout << "Insira o numero de colunas: ";
    cin >> nc;
    }while(nl<=0 || nc<=0);

    p = new int*[nl];

    for(int i=0; i<nl; i++){
        p[i] = new int[nl];
        for(int j=0; j<nc; j++){
            p[i][j] = i*i + j;
        }
    }

    if(nc==nl){
    int* arr = new int[nl];

    for(int i=0; i<nl; i++){
        for(int j=0; j<nc; j++){
            *(arr+i) = p[i][i];
        }
    }

    for(int i=0; i<nl; i++){
            cout << "arr[" << i << "]: " << arr[i] << endl;
    }

    for(int i=0; i<nl; i++){
            for(int j=0; j<nc; j++){
              cout << "p[" << i << "]: " << p[i][j];
            }
            cout << "\n";
        }

    delete[] arr;

    }
    else{
        cout << "A array bidimensional nao eh quadrada!" << endl;
        for(int i=0; i<nl; i++){
            for(int j=0; j<nc; j++){
              cout << "p[" << i << "]: " << p[i][j];
            }
            cout << "\n";
        }
    }

    for(int i=0; i<nl; i++){
            for(int j=0; j<nc; j++){
                delete[] p[i];
            }
    }

    delete[] p;

    return 0;
}
