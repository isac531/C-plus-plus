#ifndef FILA_HPP
#define FILA_HPP


constexpr int MAX_TAMANHO = 10;

class Fila {
private:

    int itens[MAX_TAMANHO];
    int inicio;
    int fim;
    int quantidade;

public:

    Fila();


    bool estaCheia() const;   
    bool estaVazia() const;   
    bool inserir(int valor);  
    bool remover(int& valorRemovido); 
    bool consultarInicio(int& valorInicio) const; 


    void imprimirFila() const;
};

#endif // FILA_HPP