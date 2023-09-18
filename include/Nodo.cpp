#include "nodo.h"

Nodo::Nodo()
{
    this->letra = ' ';
    this->next = nullptr;
    this->prev = nullptr;
    this->quantidade = 1;
}

Nodo::Nodo(char letra)
{
    this->letra = letra;
    this->next = nullptr;
    this->prev = nullptr;
    this->quantidade = 1;
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

int Nodo::getQuantidade()
{
    return this->quantidade;
}

void Nodo::setQuantidade(int quantidade)
{
    this->quantidade = quantidade;
}

void Nodo::QuantidadeMais()
{
    this->quantidade++;
}
