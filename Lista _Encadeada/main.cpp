#include <iostream>
#include <map>
#include <cstdlib>
#include <ctime>
#include <windows.h>
#include "lista.h"

using namespace std;

bool idEncontrado(const map<int, ListaEncadeada>& listas, int id) {
    return listas.find(id) != listas.end();
}

int main() {
    SetConsoleOutputCP(CP_UTF8);
    srand(time(nullptr));
    map<int, ListaEncadeada> listas;
    int entrada = -1;

    while (entrada != 0) {
        cout << "\nSelecione a Opção Desejada:\n"
             << "1. Criar Lista\n"
             << "2. Listar Listas\n"
             << "3. Verificar se a Lista Está Vazia\n"
             << "4. Obter Tamanho da Lista\n"
             << "5. Obter Elemento da Lista\n"
             << "6. Modificar Elemento da Lista\n"
             << "7. Inserir Elemento\n"
             << "8. Remover Elemento\n"
             << "9. Criar Lista Aleatória Para Teste\n"
             << "0. Sair\n> ";
        cin >> entrada;

        int id, pos, valor;

        switch (entrada) {
        case 1:
            cout << "Insira um ID para a nova lista: ";
            cin >> id;
            if (idEncontrado(listas, id)) {
                cout << "Lista com ID " << id << " já existe!\n";
            } else {
                ListaEncadeada nova;
                nova.setId(id);
                listas[id] = nova;
                cout << "Lista criada com sucesso.\n";
            }
            break;

        case 2:
            cout << "Quantidade de Listas Criadas: " << listas.size() << "\n";
            for (const auto& par : listas) {
                cout << "ID: " << par.first << " | Elementos: ";
                par.second.exibir();
            }
            break;

        case 3:
            cout << "Digite o ID da Lista: ";
            cin >> id;
            if (!idEncontrado(listas, id)) {
                cout << "Lista não encontrada.\n";
                break;
            }
            cout << (listas[id].estaVazia() ? "A Lista está vazia.\n" : "A Lista não está vazia.\n");
            break;

        case 4:
            cout << "Digite o ID da Lista: ";
            cin >> id;
            if (!idEncontrado(listas, id)) {
                cout << "Lista não encontrada.\n";
                break;
            }
            cout << "Tamanho: " << listas[id].obterTamanho() << "\n";
            break;

        case 5:
            cout << "Digite o ID da Lista: ";
            cin >> id;
            if (!idEncontrado(listas, id)) {
                cout << "Lista não encontrada.\n";
                break;
            }
            cout << "Digite a posição: ";
            cin >> pos;
            cout << "Elemento: " << listas[id].obterElemento(pos) << "\n";
            break;

        case 6:
            cout << "Digite o ID da Lista: ";
            cin >> id;
            if (!idEncontrado(listas, id)) {
                cout << "Lista não encontrada.\n";
                break;
            }
            cout << "Digite a posição: ";
            cin >> pos;
            cout << "Digite o novo valor: ";
            cin >> valor;
            if (listas[id].modificarElemento(pos, valor))
                cout << "Elemento modificado com sucesso.\n";
            else
                cout << "Falha na modificação.\n";
            break;

        case 7:
            cout << "Digite o ID da Lista: ";
            cin >> id;
            if (!idEncontrado(listas, id)) {
                cout << "Lista não encontrada.\n";
                break;
            }
            cout << "Digite a posição: ";
            cin >> pos;
            cout << "Digite o valor: ";
            cin >> valor;
            if (listas[id].inserir(pos, valor))
                cout << "Elemento inserido com sucesso.\n";
            else
                cout << "Falha ao inserir.\n";
            break;

        case 8:
            cout << "Digite o ID da Lista: ";
            cin >> id;
            if (!idEncontrado(listas, id)) {
                cout << "Lista não encontrada.\n";
                break;
            }
            cout << "Digite a posição a ser removida: ";
            cin >> pos;
            if (listas[id].remover(pos))
                cout << "Elemento removido com sucesso.\n";
            else
                cout << "Falha ao remover.\n";
            break;

        case 9: {

            int tentativas = 0;
            do {
                id = rand() % 100;
                tentativas++;
            } while (idEncontrado(listas, id) && tentativas < 100);

            if (idEncontrado(listas, id)) {
                cout << "Não foi possível gerar um ID único.\n";
                break;
            }

            ListaEncadeada nova;
            nova.setId(id);

            int qtdInicial = 5 + rand() % 6; 
            for (int i = 1; i <= qtdInicial; ++i) {
                nova.inserir(i, rand() % 100);
            }
            listas[id] = nova;

            cout << "\nCriada lista aleatória de ID: " << id << "\n";
            listas[id].exibir();

            int tam = listas[id].obterTamanho();
            cout << "Tamanho atual: " << tam << "\n";

            if (tam > 0) {
                int posAleatoria = 1 + rand() % tam;
                cout << "Elemento na posição " << posAleatoria << ": "
                     << listas[id].obterElemento(posAleatoria) << "\n";

                int posMod = 1 + rand() % tam;
                int novoValor = rand() % 200;
                listas[id].modificarElemento(posMod, novoValor);
                cout << "Modificado elemento na posição " << posMod << " para " << novoValor << "\n";
            }


            {
                int tamanhoAtual = listas[id].obterTamanho();
                int novaPos = 1 + rand() % (tamanhoAtual + 1);
                int novoValor = rand() % 100;

                if (listas[id].inserir(novaPos, novoValor)) {
                    cout << "Inserido valor " << novoValor << " na posição " << novaPos << "\n";
                }
            }

            int tamanhoAtual = listas[id].obterTamanho();
            if (tamanhoAtual > 0) {
                int posRemover = 1 + rand() % tamanhoAtual;
                listas[id].remover(posRemover);
                cout << "Removido elemento da posição " << posRemover << "\n";
            }

            cout << "Lista final: ";
            listas[id].exibir();

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
