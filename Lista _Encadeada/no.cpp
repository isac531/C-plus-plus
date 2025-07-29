#include "No.h"

No::No(int valor) : conteudo(valor), prox(nullptr) {}

int No::getConteudo() const {
    return conteudo;
}

void No::setConteudo(int valor) {
    conteudo = valor;
}

No* No::getProx() const {
    return prox;
}

void No::setProx(No* p) {
    prox = p;
}