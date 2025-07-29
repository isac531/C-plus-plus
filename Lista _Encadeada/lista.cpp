#include "lista.h"
#include <iostream>

ListaEncadeada::ListaEncadeada() : cabeca(nullptr), tamanho(0), id(-1) {}

ListaEncadeada::~ListaEncadeada() {
    while (!estaVazia()) {
        remover(1);
    }
}

bool ListaEncadeada::estaVazia() const {
    return tamanho == 0;
}

int ListaEncadeada::obterTamanho() const {
    return tamanho;
}

int ListaEncadeada::obterElemento(int pos) const {
    if (pos < 1 || pos > tamanho) {
        std::cout << "Posição inválida\n";
        return -1;
    }

    No* aux = cabeca;
    for (int i = 1; i < pos; ++i) {
        aux = aux->getProx();
    }

    return aux->getConteudo();
}

bool ListaEncadeada::modificarElemento(int pos, int valor) {
    if (pos < 1 || pos > tamanho) {
        std::cout << "Posição inválida\n";
        return false;
    }

    No* aux = cabeca;
    for (int i = 1; i < pos; ++i) {
        aux = aux->getProx();
    }

    aux->setConteudo(valor);
    return true;
}

bool ListaEncadeada::inserir(int pos, int valor) {
    if (pos < 1 || pos > tamanho + 1) {
        std::cout << "Posição inválida\n";
        return false;
    }

    No* novo = new No(valor);

    if (pos == 1) {
        novo->setProx(cabeca);
        cabeca = novo;
    } else {
        No* aux = cabeca;
        for (int i = 1; i < pos - 1; ++i) {
            aux = aux->getProx();
        }
        novo->setProx(aux->getProx());
        aux->setProx(novo);
    }

    tamanho++;
    return true;
}

bool ListaEncadeada::remover(int pos) {
    if (pos < 1 || pos > tamanho) {
        std::cout << "Posição inválida\n";
        return false;
    }

    No* removido;

    if (pos == 1) {
        removido = cabeca;
        cabeca = cabeca->getProx();
    } else {
        No* aux = cabeca;
        for (int i = 1; i < pos - 1; ++i) {
            aux = aux->getProx();
        }
        removido = aux->getProx();
        aux->setProx(removido->getProx());
    }

    delete removido;
    tamanho--;
    return true;
}

void ListaEncadeada::exibir() const {
    if (estaVazia()) {
        std::cout << "lista vazia\n";
        return;
    }

    No* aux = cabeca;
    while (aux != nullptr) {
        std::cout << aux->getConteudo() << " ";
        aux = aux->getProx();
    }
    std::cout << "\n";
}

void ListaEncadeada::setId(int id_) {
    id = id_;
}

int ListaEncadeada::getId() const {
    return id;
}