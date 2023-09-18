#include <iostream>
#include <chrono>
#include <fstream>
#include "ListaDuplamenteEncadeada.cpp"
#include "Nodo.cpp"
#define caso "data\\caso30000k.txt"

int main()
{
    auto inicio = std::chrono::high_resolution_clock::now();
    std::ifstream casos;
    ListaDuplamenteEncadeada lista;
    char letra1;
    char letra2;
    char caractere;
    char caractereAux = ' ';
    int quant = 0;

    casos.open(caso); // Abre o arquivo para leitura

    if (!casos.is_open())
    { // verifica se o arquivo foi aberto

        std::cout << "nao foi possivel abrir o arquivo" << std::endl;
        return 1;
    }
    while (casos.get(caractere))
    { // pega cada carctere do arquivo
        if (caractere == 'A' || caractere == 'D' || caractere == 'N')
        {
            lista.addTail(caractere);
    }
    }

    casos.close();

    auto fim = std::chrono::high_resolution_clock::now(); // fim da contagem de tempo
    auto duracao = fim - inicio;
    auto duracao_segundos = std::chrono::duration<double>(duracao);
    std::cout << " Tempo de execucao: " << std::fixed << duracao_segundos.count() << " segundos" << std::endl;
    return 0;

    Nodo *aux = lista.getHead();

    while (true)
    {
        if (lista.getSize() == 1)
        {
            break;
        }
        letra1 = lista.getHeadChar();
        lista.removeHead();
        // std::cout << lista.getSize() << std::endl;
        aux = lista.getHead();

        while (letra1 == aux->getLetra())
        {
            // std::cout << "entrou" << std::endl;
            aux = aux->getNext();
            if (aux == nullptr)
            {
                break;
            }
        }

        if (aux == nullptr)
        {
            lista.addHead(letra1);
            break;
        }
        letra2 = aux->getLetra();
        lista.removeMiddle(aux);
        aux = lista.getHead();

        if ((letra1 == 'D' && letra2 == 'A') || (letra1 == 'A' && letra2 == 'D'))
        {
            lista.addTail('N');
        }
        else if ((letra1 == 'D' && letra2 == 'N') || (letra1 == 'N' && letra2 == 'D'))
        {
            lista.addTail('A');
        }
        else if ((letra1 == 'A' && letra2 == 'N') || (letra1 == 'N' && letra2 == 'A'))
        {
            // std::cout << "IF D" << std::endl;
            lista.addTail('D');
        }
    }
    //auto fim = std::chrono::high_resolution_clock::now(); // fim da contagem de tempo
   // auto duracao = fim - inicio;
    //auto duracao_segundos = std::chrono::duration<double>(duracao);

    std::cout << " Tempo de execucao: " << std::fixed << duracao_segundos.count() << " segundos" << std::endl;
    lista.print();
    std::cout << "O tamanho da lista eh: " << lista.getSize() << std::endl;
}
