#ifndef ListaDuplamenteEncadeada_h
#define ListaDuplamenteEncadeada_h

#include "Nodo.h"

class ListaDuplamenteEncadeada
{
private:
    Nodo *head;
    Nodo *tail;
    int size;

public:
    ListaDuplamenteEncadeada();
    void addTail(char letra);
    void addHead(char letra);
    void addMiddle(int posicao, char letra);
    void removeTail();
    void removeHead();
    void remove(Nodo *nodo);
    void print();
    char getHeadChar();
    char getTailChar();
    Nodo *getHead();
    Nodo *getTail();
    bool isEmpty();
    int getSize();
    void editTail(int quantidade);
    void editHead(int quantidade);
    void editTailSoma();
};

#endif