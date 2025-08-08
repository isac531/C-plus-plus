#include <iostream>
#include "fila.hpp"


Fila::Fila() {
    inicio = 0;
    fim = -1;
    quantidade = 0;
}


bool Fila::estaCheia() const {
    return quantidade == MAX_TAMANHO;
}


bool Fila::estaVazia() const {
    return quantidade == 0;
}


bool Fila::inserir(int valor) {
    if (estaCheia()) {
        std::cout << "Erro: A fila esta cheia!" << std::endl;
        return false;
    }

    fim = (fim + 1) % MAX_TAMANHO;
    itens[fim] = valor;
    quantidade++;
    return true;
}


bool Fila::remover(int& valorRemovido) {
    if (estaVazia()) {
        std::cout << "Erro: A fila esta vazia!" << std::endl;
        return false;
    }
    valorRemovido = itens[inicio];

    inicio = (inicio + 1) % MAX_TAMANHO;
    quantidade--;
    return true;
}


bool Fila::consultarInicio(int& valorInicio) const {
    if (estaVazia()) {
        std::cout << "Erro: A fila esta vazia!" << std::endl;
        return false;
    }
    valorInicio = itens[inicio];
    return true;
}


void Fila::imprimirFila() const {
    if (estaVazia()) {
        std::cout << "Fila: [] (Vazia)" << std::endl;
        return;
    }
    std::cout << "Fila: [ ";
    int i = inicio;
    for (int count = 0; count < quantidade; ++count) {
        std::cout << itens[i] << " ";
        i = (i + 1) % MAX_TAMANHO;
    }
    std::cout << "]" << std::endl;
    std::cout << " (Inicio: " << inicio << ", Fim: " << fim << ", Quantidade: " << quantidade << ")" << std::endl;
}