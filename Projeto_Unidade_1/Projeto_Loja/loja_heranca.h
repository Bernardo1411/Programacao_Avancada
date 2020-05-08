#ifndef _LOJA_H_
#define _LOJA_H_

#include <iostream>
#include <string>

using namespace std;

class loja;
class ListaLivro;
class ListaCD;
class ListaDVD;

class Produto
{
private:
  string nome;
  unsigned preco;
public:
  inline Produto(const string& N="", unsigned P=0): nome(N), preco(P) {}

  bool ler(istream &I);
  void salvar(ostream &O) const;
  void digitar();
  // Define a funcao imprimir como sendo salvar em cout
  inline void imprimir() const {salvar(cout);}
};

inline istream& operator>>(istream &I, Produto &P) {P.digitar(); return I;}
inline ostream& operator<<(ostream &O, const Produto &P) {P.salvar(O); return O;}

class Livro: public Produto{
private:
    string autor;
public:
    inline Livro(const string aut=""): autor(aut){};

    void ler(istream &I);
    void salvar(ostream &O) const;
    void digitar(void);
    inline void imprimir() const{salvar(cout);};

    friend class ListaLivro;
};

inline istream& operator>>(istream &I, Livro &L) {L.digitar(); return I;}
inline ostream& operator<<(ostream &O, const Livro &L) {L.salvar(O); return O;}


class CD: public Produto{
private:
    unsigned nf;
public:
    inline CD(const unsigned num=0): nf(num){};

    void ler(istream &I);
    void salvar(ostream &O) const;
    void digitar(void);
    inline void imprimir() const{salvar(cout);};

    friend class ListaCD;
};

inline istream& operator>>(istream &I, CD &C) {C.digitar(); return I;}
inline ostream& operator<<(ostream &O, const CD &C) {C.salvar(O); return O;}


class DVD: public Produto{
private:
    unsigned dc;
public:
    inline DVD(const unsigned num=0): dc(num){};

    void ler(istream &I);
    void salvar(ostream &O) const;
    void digitar(void);
    inline void imprimir() const{salvar(cout);};

    friend class ListaDVD;
};

inline istream& operator>>(istream &I, DVD &D) {D.digitar(); return I;}
inline ostream& operator<<(ostream &O, const DVD &D) {D.salvar(O); return O;}

class ListaLivro
{
private:
  Livro *x;
  unsigned N;
public:
  inline ListaLivro(): x(NULL), N(0){};
  explicit ListaLivro(unsigned num);
  ListaLivro(const ListaLivro &LV);
  ~ListaLivro();
  void operator=(const ListaLivro &LV);

  void incluir(const Livro &L);
  bool excluir(unsigned id);

  bool ler(istream &I);
  void salvar(ostream &O) const;
  void imprimir() const;

  friend class loja;
};

class ListaCD
{
private:
  CD *x;
  unsigned N;
public:
  inline ListaCD(): x(NULL), N(0){};
  explicit ListaCD(unsigned num);
  ListaCD(const ListaCD &LC);
  ~ListaCD();
  void operator=(const ListaCD &LC);

  void incluir(const CD &C);
  bool excluir(unsigned id);

  bool ler(istream &I);
  void salvar(ostream &O) const;
  void imprimir() const;

  friend class loja;
};

class ListaDVD
{
private:
  DVD *x;
  unsigned N;
public:
  inline ListaDVD(): x(NULL), N(0){};
  explicit ListaDVD(unsigned num);
  ListaDVD(const ListaDVD &LD);
  ~ListaDVD();
  void operator=(const ListaDVD &LD);

  void incluir(const DVD &D);
  bool excluir(unsigned id);

  bool ler(istream &I);
  void salvar(ostream &O) const;
  void imprimir() const;

  friend class loja;
};

class Loja
{
private:
  ListaLivro LL;
  ListaCD LC;
  ListaDVD LD;
public:
  inline Loja(): LL(), LC(), LD() {}

  inline void incluirLivro(const Livro &X) {LL.incluir(X);}
  inline bool excluirLivro(unsigned id) {return LL.excluir(id);}
  inline void incluirDVD(const DVD &X) {LD.incluir(X);}
  inline bool excluirDVD(unsigned id) {return LD.excluir(id);}
  inline void incluirCD(const CD &X) {LC.incluir(X);}
  inline bool excluirCD(unsigned id) {return LC.excluir(id);}

  bool ler(const string& arq);
  bool salvar(const string& arq) const;
  void imprimir() const;
};
#endif // _LOJA_H_


