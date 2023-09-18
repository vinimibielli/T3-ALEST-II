#ifndef Nodo_h
#define Nodo_h

class Nodo
{
private:
    Nodo *next;
    Nodo *prev;
    char letra;
public:
    Nodo();
    Nodo(char letra);
    Nodo *getNext();
    Nodo *getPrev();
    char getLetra();
    void setNext(Nodo *next);
    void setPrev(Nodo *prev);
};

#endif