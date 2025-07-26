#ifndef LISTA_SEQ_H
#define LISTA_SEQ_H

class ListaSeq {
private:
    int* dados;
    int tamAtual;
    int tamMax;
    int id;

public:
    ListaSeq();
    ~ListaSeq(); // destrutor
    bool estaVazia() const;
    bool estaCheia() const;
    int obterTamanho() const;
    int obterElemento(int pos) const;
    bool modificarElemento(int pos, int valor);
    bool inserir(int pos, int valor);
    bool remover(int pos);
    void exibir() const;

    void setId(int in_id);
    int getId() const;
};

#endif