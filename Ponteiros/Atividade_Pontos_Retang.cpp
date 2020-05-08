#include <iostream>
#include <cmath>

using namespace std;

struct ponto{
double x;
double y;
};

struct Retangulo{
ponto mini;
ponto maxi;
};

inline void imprimirponto(const ponto &p);
double distPontos(const ponto &p, const ponto &p2);
inline bool pontosIguais(const ponto &p, const ponto &p2);
inline double areaRet(const Retangulo &r);
inline bool pontoDentroRet(const Retangulo &r, const ponto &p);
inline bool retDentroRet(const Retangulo &r, const Retangulo &r2);

int main(){
    ponto p, p2;
    Retangulo r, r2;

    p.x=3;
    p.y=5;
    p2.x=5;
    p2.y=6;
    r.mini.x=2;
    r.maxi.x=4;
    r.mini.y=4;
    r.maxi.y=6;
    r2.mini.x=3;
    r2.maxi.x=4;
    r2.mini.y=4;
    r2.maxi.y=5;

    imprimirponto(p);

    cout << "A distancia eh: " << distPontos(p, p2) << endl;
    cout << (pontosIguais(p, p2)==true ? "Iguais" : "Diferentes") << endl;
    cout << "A area do retangulo eh: " << areaRet(r) << endl;
    cout << (pontoDentroRet(r, p)==true ? "Dentro" : "Fora") << endl;
    cout << (retDentroRet(r, r2)==true ? "Dentro" : "Fora") << endl;

    return 0;
}

inline void imprimirponto(const ponto &p){

    cout << "Eixo x: " << p.x << endl;
    cout << "Eixo y: " << p.y << endl;

}

double distPontos(const ponto &p, const ponto &p2){

double dist = pow(pow(p2.x-p.x,2) + pow(p2.y-p.y,2),0.5);

return dist;

}

inline bool pontosIguais(const ponto &p, const ponto &p2){

    return ((distPontos(p, p2)<=0.000001) ? true : false);

}

inline double areaRet(const Retangulo &r){

return (r.maxi.x-r.mini.x)*(r.maxi.y-r.mini.y);

}

inline bool pontoDentroRet(const Retangulo &r, const ponto &p){

return (p.x>=r.mini.x && p.x<=r.maxi.x && p.y>=r.mini.y && p.y<=r.maxi.y)?true:false;

}

inline bool retDentroRet(const Retangulo &r, const Retangulo &r2){

    return (pontoDentroRet(r,r2.mini) && pontoDentroRet(r,r2.maxi))?true:false;

}

