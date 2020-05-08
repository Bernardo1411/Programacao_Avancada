#include <iostream>

using namespace std;

struct complexo{
    double real;
    double imaginario;
};

complexo ler(complexo &c);
void imprimir(const complexo &s, const complexo &p);
complexo soma(const complexo &c1, const complexo &c2);
complexo produto(const complexo &c1, const complexo &c2);

int main(){
    complexo c1, c2, s, p;

    cout << "Numero Complexo 1:" << endl;
    ler(c1);
    cout << "Numero Complexo 2:" << endl;
    ler(c2);

    s = soma(c1, c2);

    p = produto(c1, c2);

    imprimir(s, p);

    return 0;
}

complexo ler(complexo &c){

    cout << "Insira um valor para a parte REAL: " << endl;
    cin >> c.real;
    cout << "Insira um valor para a parte IMAGINARIA: " << endl;
    cin >> c.imaginario;

    return c;
}

complexo soma(const complexo &c1, const complexo &c2){

    complexo soma;
    soma.real = c1.real+c2.real;
    soma.imaginario = c1.imaginario+c2.imaginario;

    return soma;
}

complexo produto(const complexo &c1, const complexo &c2){

    complexo prod;

    prod.real = (c1.real*c2.real - c1.imaginario*c2.imaginario);
    prod.imaginario = (c1.real*c2.imaginario+c1.imaginario*c2.real);

    return prod;
}

void imprimir(const complexo &s, const complexo &p){

    cout << s.real << "+" << s.imaginario << "i" << endl;
    cout << p.real << "+" << p.imaginario << "i" << endl;

}
