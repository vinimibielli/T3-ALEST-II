#include "ListaDuplamenteEncadeada.h"
#include <iostream>

ListaDuplamenteEncadeada::ListaDuplamenteEncadeada()
{
    this->head = nullptr;
    this->tail = nullptr;
    this->size = 0;
}

void ListaDuplamenteEncadeada::addTail(char letra)
{
    Nodo *novoNodo = new Nodo(letra);
    if (this->head == nullptr)
    {
        this->head = novoNodo;
        this->tail = novoNodo;
        this->size++;
    }
    else
    {
        this->tail->setNext(novoNodo);
        novoNodo->setPrev(this->tail);
        this->tail = novoNodo;
        this->size++;
    }
}

void ListaDuplamenteEncadeada::addHead(char letra)
{
    Nodo *novoNodo = new Nodo(letra);
    if (this->head == nullptr)
    {
        this->head = novoNodo;
        this->tail = novoNodo;
        this->size++;
    }
    else
    {
        this->head->setPrev(novoNodo);
        novoNodo->setNext(this->head);
        this->head = novoNodo;
        this->size++;
    }
}

void ListaDuplamenteEncadeada::addMiddle(int posicao, char letra)
{
    Nodo *novoNodo = new Nodo(letra);
    if (this->head == nullptr)
    {
        this->head = novoNodo;
        this->tail = novoNodo;
        this->size++;
    }
    else if (posicao == 0)
    {
        addHead(letra);
    }
    else if (posicao == this->size)
    {
        addTail(letra);
    }
    else
    {
        Nodo *nodoAux = this->head;
        for (int i = 0; i < posicao; i++)
        {
            nodoAux = nodoAux->getNext();
        }
        nodoAux->getPrev()->setNext(novoNodo);
        novoNodo->setPrev(nodoAux->getPrev());
        novoNodo->setNext(nodoAux);
        nodoAux->setPrev(novoNodo);
        this->size++;
    }
}

void ListaDuplamenteEncadeada::removeHead()
{
    if (this->head == nullptr)
    {
        return;
    }
    else if (this->head == this->tail)
    {
        delete this->head;
        this->head = nullptr;
        this->tail = nullptr;
        this->size--;
    }
    else
    {
        Nodo *nodoAux = this->head;
        this->head = this->head->getNext();
        this->head->setPrev(nullptr);
        delete nodoAux;
        this->size--;
    }
}

void ListaDuplamenteEncadeada::removeTail()
{
    if (this->head == nullptr)
    {
        return;
    }
    else if (this->head == this->tail)
    {
        delete this->head;
        this->head = nullptr;
        this->tail = nullptr;
        this->size--;
    }
    else
    {
        Nodo *nodoAux = this->tail;
        this->tail = this->tail->getPrev();
        this->tail->setNext(nullptr);
        delete nodoAux;
        this->size--;
    }
}

void ListaDuplamenteEncadeada::removeMiddle(Nodo *nodo)
{
    if (this->head == nullptr)
    {
        return;
    }
    else if (this->head == this->tail)
    {
        delete this->head;
        this->head = nullptr;
        this->tail = nullptr;
        this->size--;
    }
    else
    {
        Nodo *nodoAux = nodo;
        nodoAux->getPrev()->setNext(nodoAux->getNext());
        nodoAux->getNext()->setPrev(nodoAux->getPrev());
        delete nodoAux;
        this->size--;
    }
}

void ListaDuplamenteEncadeada::print()
{
    Nodo *nodoAux = this->head;
    while (nodoAux != nullptr)
    {
        std::cout << nodoAux->getLetra() << " ";
        nodoAux = nodoAux->getNext();
    }
    std::cout << std::endl;
}

bool ListaDuplamenteEncadeada::isEmpty()
{
    if(getSize() == 0){
        return true;
    }
    else{
        return false;
    }
}

int ListaDuplamenteEncadeada::getSize()
{
    return this->size;
}

char ListaDuplamenteEncadeada::getHead()
{
    return this->head->getLetra();
}

char ListaDuplamenteEncadeada::getTail()
{
    return this->tail->getLetra();
}
