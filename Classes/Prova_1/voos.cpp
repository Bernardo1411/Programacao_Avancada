#include <iostream>
#include "voos.h"

using namespace std;

voo::voo(const voo &v){
    nvoo = v.nvoo;
    hsaida = v.hsaida;
    hcheg = v.hcheg;

   strO = v.strO;
   strD = v.strD;
};

ostream &operator<<(ostream &saida, voo &v){
    saida << "Codigo: " << v.nvoo << " Horario de saída: " << v.hsaida << " Horario de entrada: " << v.hcheg << " Origem: " << v.strO << " destino: " << v.strD;

    return saida;
};
istream &operator>>(istream &entrada, voo &v){
    cout << "Codigo: ";
    entrada >> v.nvoo;

    cout << "Horario de saida: ";
    entrada >> v.hsaida;

    cout << "Horario de chegada: ";
    entrada >> v.hcheg;

    cout << "Origem: ";
    entrada >> v.strO;

    cout << "Destino: ";
    entrada >> v.strD;

    return entrada;
}

ListaVoos::ListaVoos(const ListaVoos &lv){
    delete[] p;
    n = lv.n;
    p = new voo[n];
    for(int i=0; i<n; i++) p[i] = lv.p[i];
}

ListaVoos::ListaVoos(int num){
    n=num;
    p = new voo[n];
}

ListaVoos::~ListaVoos(){
    if(p!=NULL) delete[] p;
    p=NULL;
    n=0;
}

void ListaVoos::operator=(ListaVoos &lv){
    if(this!=&lv){
    if(p!=NULL) delete[] p;
    n = lv.n;
    p = new voo[n];
    for(int i=0; i<n; i++) p[i] = lv.p[i];

    }
}

void ListaVoos::inserir(voo &v){
    voo *prov = new voo[n+1];
    for(int i=0; i<n; i++) prov[i] = p[i];
    prov[n] = v;
    if(p!=NULL) delete[] p;
    p = prov;
    n++;
}

ostream &operator<<(ostream &saida, const ListaVoos &lv){
    for(int i=0; i<lv.n; i++) saida << lv.p[i];

    return saida;
}

void ListaVoos::imprimir(string aero_o1)
{
    for(int i = 0; i<this->n; i++)
    {
        if(p[i].strO == aero_o1)
        {
            cout << p[i] << endl;
        }
    }
}
