#include <iostream>
#include "lista.h"
#include <map>
#include <cstdlib>
#include <ctime>
#include <windows.h>

using namespace std;

bool idEncontrado(const map<int, ListaSeq>& listas, int id) {
    return listas.find(id) != listas.end();
}


int main() {
    SetConsoleOutputCP(CP_UTF8);
    srand(time(nullptr));
    map<int, ListaSeq> listas;
    int entrada = -1;

    while (entrada != 0) {
        cout << "\nSelecione a Opcao Desejada:\n"
             << "1. Criar Lista\n"
             << "2. Listar Listas\n"
             << "3. Verificar Se a Lista Esta Vazia\n"
             << "4. Verificar Se a Lista Esta Cheia\n"
             << "5. Obter o Tamanho da Lista\n"
             << "6. Obter Elemento da Lista\n"
             << "7. Modificar Elemento da Lista\n"
             << "8. Inserir Elemento em Uma Posicao\n"
             << "9. Remover Elemento de Uma Posicao\n"
             << "10. Criar Lista Aleatoria Para Teste\n"
             << "0. Sair\n";
        cin >> entrada;

        int id, pos, valor;

        switch (entrada) {
        case 1:
            cout << "Insira um Id Para a Lista: ";
            cin >> id;
            if (idEncontrado(listas, id)) {
                cout << "Lista com ID " << id << " já existe!\n";
            } else {
                ListaSeq novaLista;
                novaLista.setId(id);
                listas[id] = novaLista;
                cout << "Lista criada com sucesso.\n";
            }
            break;

        case 2:
            cout << "Quantidade de Listas Criadas: " << listas.size() << "\n";
            for (const auto& par : listas) {
                cout << "ID: " << par.first << "\n";
            }
            break;

        case 3:
            cout << "Digite o ID da Lista: ";
            cin >> id;
            if (listas[id].estaVazia()) {
                cout << "A Lista está vazia.\n";
            } else {
                cout << "A Lista não está vazia.\n";
            }
            break;

        case 4:
            cout << "Digite o ID da Lista: ";
            cin >> id;
            if (listas[id].estaCheia()) {
                cout << "A Lista está cheia.\n";
            } else {
                cout << "A Lista não está cheia.\n";
            }
            break;

        case 5:
            cout << "Digite o ID da Lista: ";
            cin >> id;
            cout << "Tamanho: " << listas[id].obterTamanho() << "\n";
            break;

        case 6:
            cout << "Digite o ID da Lista: ";
            cin >> id;
            cout << "Digite a posição: ";
            cin >> pos;
            cout << "Elemento na posição " << pos << ": " << listas[id].obterElemento(pos) << "\n";
            break;

        case 7:
            cout << "Digite o ID da Lista: ";
            cin >> id;
            cout << "Digite a posição: ";
            cin >> pos;
            cout << "Digite o novo valor: ";
            cin >> valor;
            if (listas[id].modificarElemento(pos, valor)) {
                cout << "Elemento modificado com sucesso.\n";
            }
            break;

        case 8:
            cout << "Digite o ID da Lista: ";
            cin >> id;
            cout << "Digite a posição de inserção: ";
            cin >> pos;
            cout << "Digite o valor a ser inserido: ";
            cin >> valor;
            if (listas[id].inserir(pos, valor)) {
                cout << "Elemento inserido com sucesso.\n";
            }
            break;

        case 9:
            cout << "Digite o ID da Lista: ";
            cin >> id;
            cout << "Digite a posição a ser removida: ";
            cin >> pos;
            if (listas[id].remover(pos)) {
                cout << "Elemento removido com sucesso.\n";
            }
            break;

        case 10: {
            while (true) {
            id = rand() % 100;
            if (!idEncontrado(listas, id)) {
                ListaSeq novaLista;
                novaLista.setId(id);
                listas[id] = novaLista;

                int qtdInicial = 5 + rand() % 6; // insere de 5 a 10 elementos
                cout << "\nCriando lista de ID: " << id << " com " << qtdInicial << " elementos iniciais.\n";

                for (int i = 1; i <= qtdInicial; i++) {
                    int valor = rand() % 100;
                    listas[id].inserir(i, valor);
                    }

                cout << "Lista inicial: ";
                listas[id].exibir();


                int tam = listas[id].obterTamanho();
                cout << "Tamanho atual da lista: " << tam << "\n";

                if (tam > 0) {
                    int posAleatoria = 1 + rand() % tam;
                    cout << "Elemento na posição " << posAleatoria << ": " << listas[id].obterElemento(posAleatoria) << "\n";
                }

                if (tam > 0) {
                    int posMod = 1 + rand() % tam;
                    int novoValor = rand() % 200;
                    listas[id].modificarElemento(posMod, novoValor);
                    cout << "Modificado elemento na posição " << posMod << " para " << novoValor << "\n";
                    }

                if (!listas[id].estaCheia()) {
                    int novaPos = 1 + rand() % (listas[id].obterTamanho() + 1);
                    int novoValor = rand() % 100;
                    listas[id].inserir(novaPos, novoValor);
                    cout << "Inserido valor " << novoValor << " na posição " << novaPos << "\n";
                }

                if (!listas[id].estaVazia()) {
                    int tamanhoAtual = listas[id].obterTamanho(); // ← atualizado aqui
                    int posRemover = 1 + rand() % tamanhoAtual;
                    listas[id].remover(posRemover);
                    cout << "Removido elemento da posição " << posRemover << "\n";
                }
                cout << "Lista final: ";
                listas[id].exibir();

                break;
                }
            }
            break;
        }

        case 0:
            cout << "Encerrando...\n";
            break;

        default:
            cout << "Opção inválida.\n";
        }
    }

    return 0;
}