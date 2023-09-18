#ifndef Nodo_h
#define Nodo_h

class Nodo
{
private:
    Nodo *next;
    Nodo *prev;
    char letra;
    int quantidade;
public:
    Nodo();
    Nodo(char letra);
    Nodo *getNext();
    Nodo *getPrev();
    char getLetra();
    void setNext(Nodo *next);
    void setPrev(Nodo *prev);
    int getQuantidade();
    void setQuantidade(int quantidade);
    void QuantidadeMais();
};

#endif