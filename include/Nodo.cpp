#include "nodo.h"

Nodo::Nodo()
{
    this->letra = ' ';
    this->next = nullptr;
    this->prev = nullptr;
}

Nodo::Nodo(char letra)
{
    this->letra = letra;
    this->next = nullptr;
    this->prev = nullptr;
}

Nodo *Nodo::getNext()
{
    return this->next;
}

Nodo *Nodo::getPrev()
{
    return this->prev;
}

char Nodo::getLetra()
{
    return this->letra;
}

void Nodo::setNext(Nodo *next)
{
    this->next = next;
}

void Nodo::setPrev(Nodo *prev)
{
    this->prev = prev;
}

char Nodo::getLetra()
{
    return this->letra;
}