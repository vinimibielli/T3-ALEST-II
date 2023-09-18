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
    void removeMiddle(Nodo *nodo);
    void print();
    char getHead();
    char getTail();
    bool isEmpty();
    int getSize();

};

#endif