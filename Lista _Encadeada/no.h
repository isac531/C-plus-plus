#ifndef NO_H
#define NO_H

class No {
private:
    int conteudo;
    No* prox;

public:
    No(int valor);
    int getConteudo() const;
    void setConteudo(int valor);
    No* getProx() const;
    void setProx(No* p);
};

#endif