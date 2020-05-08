#include <iostream>

using namespace std;

struct matriz{
int nl, nc;
double **p;
};

matriz criar(int, int);
void inserir(matriz &M);
matriz mult(const matriz &M1, const matriz &M2);
void exibir(const matriz &M);
void limpar(matriz &M);


int main(){
matriz A, B, C;
int la, ca, lb, cb;

    cout << "Insira o numero de linhas: ";
    cin >> la;
    cout << "Insira o numero de colunas: ";
    cin >> ca;

    cout << "Insira o numero de colunas: ";
    cin >> cb;

    lb = ca;

    A = criar(la, ca);
    B = criar(lb, cb);

    cout << "Matriz A: " << endl;
    inserir(A);
    cout << "Matriz B: " << endl;
    inserir(B);

    C = mult(A, B);

    cout << "Matriz C: " <<  endl;
    exibir(C);

    limpar(A);
    limpar(B);
    limpar(C);

    return 0;
}

matriz criar(int linhas, int colunas){

    matriz M;
    M.nl = linhas;
    M.nc = colunas;
    M.p = new double*[linhas];

    for(int i=0; i<colunas; i++) M.p[i] = new double[colunas];

    return M;

}

void inserir(matriz &M){

    for(int i=0; i<M.nl; i++){
        for(int j=0; j<M.nc; j++){
            cout << i << "x" << j << ": ";
            cin >> M.p[i][j];
        }
    }
}

matriz mult(const matriz &M1, const matriz &M2){

    matriz M;
    M = criar(M2.nl, M1.nc);

    for(int i=0; i<M.nl; i++){
        for(int z=0; z<M.nc; z++){
            for(int j=0; j<M.nc; j++){
                M.p[i][z] = M.p[i][z] + M1.p[i][j] + M2.p[j][z];
            }
        }
    }

    return M;

}

void exibir(const matriz &M){

    for(int i=0; i<M.nl; i++){
        for(int j=0; j<M.nc; j++){
            cout << M.p[i][j] << " ";
        }
        cout << "\n";
    }

}

void limpar(matriz &M){

    for(int i=0; i<M.nl; i++){
        if(M.p[i]!=NULL) delete[] M.p[i];
    }

    if(M.p!=NULL) delete[] M.p;

    M.p = NULL;

}
