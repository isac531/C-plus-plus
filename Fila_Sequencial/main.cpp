#include <iostream>
#include "fila.hpp"

int main() {
    Fila minhaFila; 
    int valor;

    std::cout << "--- Iniciando Testes da Fila (C++) ---" << std::endl;


    std::cout << "Fila inicializada." << std::endl;
    minhaFila.imprimirFila();


    std::cout << "A fila esta vazia? " << (minhaFila.estaVazia() ? "Sim" : "Nao") << std::endl;
    std::cout << "A fila esta cheia? " << (minhaFila.estaCheia() ? "Sim" : "Nao") << std::endl << std::endl;


    std::cout << "--- Inserindo elementos ---" << std::endl;
    for (int i = 1; i <= 5; ++i) {
        std::cout << "Inserindo " << i * 10 << "..." << std::endl;
        minhaFila.inserir(i * 10);
        minhaFila.imprimirFila();
    }
    std::cout << std::endl;


    if (minhaFila.consultarInicio(valor)) {
        std::cout << "Valor no inicio da fila: " << valor << std::endl;
    }
    std::cout << "A fila esta vazia? " << (minhaFila.estaVazia() ? "Sim" : "Nao") << std::endl << std::endl;


    std::cout << "--- Removendo 2 elementos ---" << std::endl;
    if (minhaFila.remover(valor)) {
        std::cout << "Valor removido: " << valor << std::endl;
    }
    minhaFila.imprimirFila();
    if (minhaFila.remover(valor)) {
        std::cout << "Valor removido: " << valor << std::endl;
    }
    minhaFila.imprimirFila();
    std::cout << std::endl;


    if (minhaFila.consultarInicio(valor)) {
        std::cout << "Novo valor no inicio da fila: " << valor << std::endl << std::endl;
    }


    std::cout << "--- Testando o comportamento circular ---" << std::endl;
    std::cout << "Inserindo mais 7 elementos para encher a fila..." << std::endl;
    for (int i = 6; i <= 12; ++i) {
        minhaFila.inserir(i * 10);
    }
    minhaFila.imprimirFila();
    std::cout << "A fila esta cheia? " << (minhaFila.estaCheia() ? "Sim" : "Nao") << std::endl << std::endl;


    std::cout << "Tentando inserir 130 na fila cheia..." << std::endl;
    if (!minhaFila.inserir(130)) {
        std::cout << "Falha ao inserir, como esperado." << std::endl << std::endl;
    }


    std::cout << "--- Esvaziando a fila ---" << std::endl;
    while (!minhaFila.estaVazia()) {
        minhaFila.remover(valor);
        std::cout << "Valor removido: " << valor << std::endl;
        minhaFila.imprimirFila();
    }
    std::cout << "A fila esta vazia? " << (minhaFila.estaVazia() ? "Sim" : "Nao") << std::endl << std::endl;

    std::cout << "Tentando remover da fila vazia..." << std::endl;
    if (!minhaFila.remover(valor)) {
        std::cout << "Falha ao remover, como esperado." << std::endl;
    }

    std::cout << std::endl << "--- Testes Concluidos ---" << std::endl;

    return 0;
}