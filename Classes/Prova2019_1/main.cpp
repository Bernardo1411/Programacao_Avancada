#include <iostream>
#include "prova2019_1.h"

using namespace std;

int main(void)
{
 linha L1,L2,L3;
 ponto P;
 unsigned NPt, NPtAdic, i;
 do
 {
 cout << "Numero de pontos da 1a linha (>0): ";
 cin >> NPt;
 } while (NPt<=0);
 for (i=0; i<NPt; i++)
 {
 cout << "Digite o ponto indice " << i << ": ";
 cin >> P;
 L1.adicionar(P);
 }
 L2 = L1;
 do
 {
 cout << "Numero de pontos adicionais da 2a linha (>0): ";
 cin >> NPtAdic;
 } while (NPtAdic<=0);
 for (i=0; i<NPtAdic; i++)
 {
 cout << "Digite o ponto indice " << i+NPt << ": ";
 cin >> P;
 L2.adicionar(P);
 }
 L3 = L1+L2;
 cout << "1a linha: " << L1 << endl;
 cout << "2a linha: " << L2 << endl;
 cout << "3a linha: " << L3 << endl;
 return 0;
}
