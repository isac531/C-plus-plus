#include "lista.h"
#include <iostream>

ListaSeq::ListaSeq() {
    tamMax = 100;
    tamAtual = 0;
    dados = new int[tamMax];
}

ListaSeq::~ListaSeq() {
    delete[] dados;
}

bool ListaSeq::estaVazia() const {
    return tamAtual == 0;
}

bool ListaSeq::estaCheia() const {
    return tamAtual == tamMax;
}

int ListaSeq::obterTamanho() const {
    return tamAtual;
}

int ListaSeq::obterElemento(int pos) const {
    if (pos < 1 || pos > tamAtual) {
        std::cout << "Posição inválida\n";
        return -1;
    }
    return dados[pos - 1];
}

bool ListaSeq::modificarElemento(int pos, int valor) {
    if (pos < 1 || pos > tamAtual) {
        std::cout << "Posição inválida\n";
        return false;
    }
    dados[pos - 1] = valor;
    return true;
}

bool ListaSeq::inserir(int pos, int valor) {
    if (estaCheia()) {
        std::cout << "Lista cheia\n";
        return false;
    }
    if (pos < 1 || pos > tamAtual + 1) {
        std::cout << "Posição inválida\n";
        return false;
    }

    for (int i = tamAtual - 1; i >= pos - 1; --i) {
        dados[i + 1] = dados[i];
    }

    dados[pos - 1] = valor;
    ++tamAtual;
    return true;
}

bool ListaSeq::remover(int pos) {
    if (estaVazia()) {
        std::cout << "Lista vazia\n";
        return false;
    }
    if (pos < 1 || pos > tamAtual) {
        std::cout << "Posição inválida\n";
        return false;
    }
    for (int i = pos - 1; i < tamAtual - 1; ++i) {
        dados[i] = dados[i + 1];
    }
    --tamAtual;
    return true;
}

void ListaSeq::exibir() const {
    if (tamAtual == 0) {
        std::cout << "lista vazia\n";
    } else {
        for (int i = 0; i < tamAtual; ++i) {
            std::cout << dados[i] << " ";
        }
        std::cout << "\n";
    }
}

void ListaSeq::setId(int in_id) {
    id = in_id;
}

int ListaSeq::getId() const {
    return id;
}