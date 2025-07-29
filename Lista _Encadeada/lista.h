#ifndef LISTA_ENCADEADA_H
#define LISTA_ENCADEADA_H

#include "No.h"

class ListaEncadeada {
private:
    No* cabeca;
    int tamanho;
    int id;

public:
    ListaEncadeada();
    ~ListaEncadeada();

    bool estaVazia() const;
    int obterTamanho() const;
    int obterElemento(int pos) const;
    bool modificarElemento(int pos, int valor);
    bool inserir(int pos, int valor);
    bool remover(int pos);
    void exibir() const;

    void setId(int id);
    int getId() const;
};

#endif