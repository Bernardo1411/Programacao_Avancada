#include <iostream>
#include <string>
#include <limits>
#include "loja_heranca.h"
#include <fstream>

bool Produto::ler(istream &I){

    I.ignore(numeric_limits<streamsize>::max(), '"');
    getline(I,nome, '"');
    I.ignore(numeric_limits<streamsize>::max(), '$');
    I >> preco;
    I.ignore(numeric_limits<streamsize>::max(), ';');

    if(nome == "" || preco <= 0.0){
        return false;
    }
    else{
        return true;
    }
}

void Produto::salvar(ostream &O) const{

    O << '"' << nome << '"' << ';' << '$' << preco;

}

void Produto::digitar(){

    cout << "nome: ";
    getline(cin,nome,'\n');

    cout << "preco: ";
    cin >> preco;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

}

void Livro::ler(istream &I){

    Produto::ler(I);

    I.ignore(numeric_limits<streamsize>::max(), '"');
    getline(I, autor, '"');
    I.ignore(numeric_limits<streamsize>::max(), '\n');
}

void Livro::salvar(ostream &O) const{

    O << 'L' << ':' << ' ';
    Produto::salvar(O);
    O <<';' << '"' << autor << '"' << '\n';

}

void Livro::digitar(void){

    Produto::digitar();

    cout << "Autor: ";
    getline(cin,autor,'\n');

}

void CD::ler(istream &I){

    Produto::ler(I);

    I.ignore(numeric_limits<streamsize>::max(), '"');
    I >> nf;
    I.ignore(numeric_limits<streamsize>::max(), '\n');
}

void CD::salvar(ostream &O) const{

    O << 'C' << ':' << ' ';
    Produto::salvar(O);
    O <<';' << '"' << nf << '"'<<'\n';

}

void CD::digitar(void){

    Produto::digitar();

    cout << "Numero de faixas: ";
    cin >> nf;

}

void DVD::ler(istream &I){

    Produto::ler(I);

    I.ignore(numeric_limits<streamsize>::max(), '"');
    I >> dc;
    I.ignore(numeric_limits<streamsize>::max(), '\n');

}

void DVD::salvar(ostream &O) const{

    O << 'D' << ':' << ' ';
    Produto::salvar(O);
    O <<';' << '"' << dc << '"'<<'\n';

}

void DVD::digitar(void){

    Produto::digitar();

    cout << "Duracao (min): ";
    cin >> dc;

}

ListaLivro::ListaLivro(unsigned num){
    if(N>0){
        N = num;
        x = new Livro[N];
    }
    else{
        N = 0;
        x=NULL;
    }
}

ListaLivro::ListaLivro(const ListaLivro& LV){
    if(N<0){
        N = LV.N;
        x = new Livro[N];

        for(unsigned i=0; i<N; i++) x[i] = LV.x[i];
    }
    else{
        x = NULL;
    }
}

ListaLivro::~ListaLivro(){

    if(x!=NULL) delete[] x;

    x = NULL;
    N = 0;

}

void ListaLivro::operator=(const ListaLivro &LV){

    if(this!=&LV){
        if(N==LV.N){
            N = LV.N;
            for(unsigned i=0; i<N; i++) x[i] = LV.x[i];
        }
        else{
            if(x!=NULL) delete[] x;
            N = LV.N;
            x = new Livro[N];
            for(unsigned i=0; i<N; i++) x[i] = LV.x[i];
        }
    }

}

void ListaLivro::incluir(const Livro &L){

    Livro *prov = new Livro[N+1];
    for(unsigned i=0; i<N; i++) prov[i] = x[i];
    if(x!=NULL) delete[] x;
    prov[N] = L;
    x = new Livro[N+1];
    N = N+1;
    for(unsigned i=0; i<N; i++) x[i] = prov[i];
    if(prov!=NULL) delete[] prov;
    prov = NULL;

}

bool ListaLivro::excluir(unsigned id){

    if(id<N && id>=0){
        Livro *prov = new Livro[N-1];
        for(unsigned i=0; i<id; i++) prov[i] = x[i];
        for(unsigned i=id; i<N-1; i++) prov[i] = x[i+1];
        if(x!=NULL) delete[] x;
        N--;
        x = new Livro[N];
        for(unsigned i=0; i<N; i++) x[i] = prov[i];
        if(prov!=NULL) delete[] prov;
        prov = NULL;

        return true;
    }
    else{
        return false;
    }
}

bool ListaLivro::ler(istream &I){
string str;
    I >> str;
    I.ignore(numeric_limits<streamsize>::max(), ' ');
    I >> N;
    if(str=="LISTALIVROS" && N>=0){
        for(unsigned i=0; i<N; i++){
            x[i].Livro::ler(I);
        }
        I.ignore(numeric_limits<streamsize>::max(), '\n');
        return true;
    }
    else{
        return false;
    }
}

void ListaLivro::salvar(ostream &O) const{

    O << "LISTALIVROS" << ' ' << N << '\n';
    for(unsigned i=0; i<N; i++) x[i].Livro::salvar(O);
}

void ListaLivro::imprimir() const{
    cout << "Livros: \n";
    for(unsigned i=0; i<N; i++){
        cout << i << ") ";
        x[i].Livro::imprimir();
    }
}

ListaCD::ListaCD(unsigned num){
    if(N>0){
        N = num;
        x = new CD[N];
    }
    else{
        N = 0;
        x=NULL;
    }
}

ListaCD::ListaCD(const ListaCD& LC){
    if(N<0){
        N = LC.N;
        x = new CD[N];

        for(unsigned i=0; i<N; i++) x[i] = LC.x[i];
    }
    else{
        x = NULL;
    }
}

ListaCD::~ListaCD(){

    if(x!=NULL) delete[] x;

    x = NULL;
    N = 0;

}

void ListaCD::operator=(const ListaCD &LC){

    if(this!=&LC){
        if(N==LC.N){
            N = LC.N;
            for(unsigned i=0; i<N; i++) x[i] = LC.x[i];
        }
        else{
            if(x!=NULL) delete[] x;
            N = LC.N;
            x = new CD[N];
            for(unsigned i=0; i<N; i++) x[i] = LC.x[i];
        }
    }

}

void ListaCD::incluir(const CD &C){

    CD *prov = new CD[N+1];
    for(unsigned i=0; i<N; i++) prov[i] = x[i];
    if(x!=NULL) delete[] x;
    prov[N] = C;
    x = new CD[N+1];
    N = N+1;
    for(unsigned i=0; i<N; i++) x[i] = prov[i];
    if(prov!=NULL) delete[] prov;
    prov = NULL;

}

bool ListaCD::excluir(unsigned id){

    if(id<N && id>=0){
        CD *prov = new CD[N-1];
        for(unsigned i=0; i<id; i++) prov[i] = x[i];
        for(unsigned i=id; i<N-1; i++) prov[i] = x[i+1];
        if(x!=NULL) delete[] x;
        N--;
        x = new CD[N];
        for(unsigned i=0; i<N; i++) x[i] = prov[i];
        if(prov!=NULL) delete[] prov;
        prov = NULL;

        return true;
    }
    else{
        return false;
    }
}

bool ListaCD::ler(istream &I){
string str;

    I >> str;
    I.ignore(numeric_limits<streamsize>::max(), ' ');
    I >> N;
    if(str=="LISTACD" && N>=0){
        for(unsigned i=0; i<N; i++){
            x[i].CD::ler(I);
        }
        I.ignore(numeric_limits<streamsize>::max(), '\n');
        return true;
    }
    else{
        return false;
    }
}

void ListaCD::salvar(ostream &O) const{

    O << "LISTACD" << ' ' << N << '\n';
    for(unsigned i=0; i<N; i++) x[i].CD::salvar(O);
}

void ListaCD::imprimir() const{
    cout << "CD: \n";
    for(unsigned i=0; i<N; i++){
        cout << i << ") ";
        x[i].CD::imprimir();
    }
}

ListaDVD::ListaDVD(unsigned num){
    if(N>0){
        N = num;
        x = new DVD[N];
    }
    else{
        N = 0;
        x=NULL;
    }
}

ListaDVD::ListaDVD(const ListaDVD& LD){
    if(N<0){
        N = LD.N;
        x = new DVD[N];

        for(unsigned i=0; i<N; i++) x[i] = LD.x[i];
    }
    else{
        x = NULL;
    }
}

ListaDVD::~ListaDVD(){

    if(x!=NULL) delete[] x;

    x = NULL;
    N = 0;

}

void ListaDVD::operator=(const ListaDVD &LD){

    if(this!=&LD){
        if(N==LD.N){
            N = LD.N;
            for(unsigned i=0; i<N; i++) x[i] = LD.x[i];
        }
        else{
            if(x!=NULL) delete[] x;
            N = LD.N;
            x = new DVD[N];
            for(unsigned i=0; i<N; i++) x[i] = LD.x[i];
        }
    }
}

void ListaDVD::incluir(const DVD &D){

    DVD *prov = new DVD[N+1];
    for(unsigned i=0; i<N; i++) prov[i] = x[i];
    if(x!=NULL) delete[] x;
    prov[N] = D;
    x = new DVD[N+1];
    N = N+1;
    for(unsigned i=0; i<N; i++) x[i] = prov[i];
    if(prov!=NULL) delete[] prov;
    prov = NULL;

}

bool ListaDVD::excluir(unsigned id){

    if(id<N && id>=0){
        DVD *prov = new DVD[N-1];
        for(unsigned i=0; i<id; i++) prov[i] = x[i];
        for(unsigned i=id; i<N-1; i++) prov[i] = x[i+1];
        if(x!=NULL) delete[] x;
        N--;
        x = new DVD[N];
        for(unsigned i=0; i<N; i++) x[i] = prov[i];
        if(prov!=NULL) delete[] prov;
        prov = NULL;

        return true;
    }
    else{
        return false;
    }
}

bool ListaDVD::ler(istream &I){
string str;
    I >> str;
    I.ignore(numeric_limits<streamsize>::max(), ' ');
    I >> N;
    if(str=="LISTADVD" && N>=0){
        for(unsigned i=0; i<N; i++){
            x[i].DVD::ler(I);
        }
        return true;
    }
    else{
        return false;
    }
}

void ListaDVD::salvar(ostream &O) const{

    O << "LISTADVD" << ' ' << N << '\n';
    for(unsigned i=0; i<N; i++) x[i].DVD::salvar(O);
}

void ListaDVD::imprimir() const{
    cout << "DVD: \n";
    for(unsigned i=0; i<N; i++){
        cout << i << ") ";
        x[i].DVD::imprimir();
    }
}

bool Loja::ler(const string& arq){

    ifstream I;
    I.open(arq,ios::in);

    LL.ListaLivro::ler(I);
    LC.ListaCD::ler(I);
    LD.ListaDVD::ler(I);

    I.close();

    return (LL.ListaLivro::ler(I) && LC.ListaCD::ler(I) && LD.ListaDVD::ler(I));
}

bool Loja::salvar(const string& arq) const{

    ofstream O(arq.c_str());
    if(arq!=""){
        LL.ListaLivro::salvar(O);
        LC.ListaCD::salvar(O);
        LD.ListaDVD::salvar(O);

        O.close();
        return true;
    }
    else{
        return false;
    }

}

void Loja::imprimir() const{

    LL.ListaLivro::imprimir();
    LC.ListaCD::imprimir();
    LD.ListaDVD::imprimir();

}
