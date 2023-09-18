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
    int letra1Quant;
    int letra2Quant;
    char caractere;
    char caractereAux = ' ';
    int quant = 1;

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
            if (caractere == caractereAux)
            {
                lista.editTailSoma();
                continue;
            }
            lista.addTail(caractere);
            caractereAux = caractere;

        }
    }

    casos.close();
    //auto fim = std::chrono::high_resolution_clock::now(); // fim da contagem de tempo

    //lista.print();
    Nodo *aux = lista.getHead();
    Nodo *aux2 = aux->getNext();
    letra1 = aux->getLetra();
    letra1Quant = aux->getQuantidade();
    letra2 = aux2->getLetra();
    letra2Quant = aux2->getQuantidade();

    //std::cout << "Letra 1: " << aux->getLetra() << " Quantidade: " << aux->getQuantidade() << std::endl;
    //std::cout << "Letra 2: " << aux2->getLetra() << " Quantidade: " << aux2->getQuantidade() << std::endl;
// std::cout << "Letra 1: " << letra1 << " Quantidade: " << letra1Quant << std::endl;
//                 std::cout << "Letra 2: " << letra2 << " Quantidade: " << letra2Quant << std::endl;
    while (true)
    {
        if (letra1Quant == 0 && letra2Quant == 0 && aux2->getNext()->getNext() == nullptr){
            lista.remove(aux);
            lista.remove(aux2);
            //std::cout << "Entrou no break" << std::endl;
            break;
        }
        
        if(letra1Quant == 0 && letra2Quant == 0){
            //std::cout << "ZERADOS" << std::endl;
            lista.remove(aux);
            aux = aux2->getNext();
            lista.remove(aux2);
            aux2 = aux->getNext();
            letra1 = aux->getLetra();
            letra1Quant = aux->getQuantidade();
            letra2 = aux2->getLetra();
            letra2Quant = aux2->getQuantidade();
            //std::cout << "MUDOU" << std::endl;
            //std::cout << "Letra 1: " << letra1 << " Quantidade: " << letra1Quant << std::endl;
            //std::cout << "Letra 2: " << letra2 << " Quantidade: " << letra2Quant << std::endl;
            //lista.print();
        }
    
        if (letra1Quant == 0)
        {
            //std::cout << "Entrou letra 1 igual 0" << std::endl;
            if(letra2Quant > 0){
                lista.remove(aux);
                aux = aux2;
                letra1 = letra2;
                letra1Quant = letra2Quant;
                aux2 = aux->getNext();
                letra2 = aux2->getLetra();
                letra2Quant = aux2->getQuantidade();
            }else{
            lista.remove(aux);
            aux = aux2->getNext();
            letra1 = aux->getLetra();
            letra1Quant = aux->getQuantidade();
            }
            //std::cout << "MUDOU" << std::endl;
                //std::cout << "Letra 1: " << letra1 << " Quantidade: " << letra1Quant << std::endl;
                //std::cout << "Letra 2: " << letra2 << " Quantidade: " << letra2Quant << std::endl;
        }
        
        if (letra2Quant == 0)
        {
            //std::cout << "Entrou letra 2 igual 0" << std::endl;
            lista.remove(aux2);
            aux2 = aux->getNext();
            letra2 = aux2->getLetra();
            letra2Quant = aux2->getQuantidade();
            //std::cout << "MUDOU" << std::endl;
                //std::cout << "Letra 1: " << letra1 << " Quantidade: " << letra1Quant << std::endl;
                //std::cout << "Letra 2: " << letra2 << " Quantidade: " << letra2Quant << std::endl;
        }
        
        if (letra1 == letra2)
        {
            //lista.print();
           //std::cout << "Entrou letra 1 igual letra 2" << std::endl;
            lista.removeHead();
            lista.editHead(letra1Quant + letra2Quant);
            aux = lista.getHead();
            aux2 = aux->getNext();
            letra1 = aux->getLetra();
            letra1Quant = aux->getQuantidade();
            letra2 = aux2->getLetra();
            letra2Quant = aux2->getQuantidade();
            //std::cout << "MUDOU" << std::endl;
                //std::cout << "Letra 1: " << letra1 << " Quantidade: " << letra1Quant << std::endl;
                //std::cout << "Letra 2: " << letra2 << " Quantidade: " << letra2Quant << std::endl;
                //lista.print();

        }
        //std::cout << "Letra 1: " << letra1 << " Quantidade: " << letra1Quant << std::endl;
        //std::cout << "Letra 2: " << letra2 << " Quantidade: " << letra2Quant << std::endl;
        if ((letra1 == 'D' && letra2 == 'A') || (letra1 == 'A' && letra2 == 'D'))
        {
            //std::cout << "Entrou N" << std::endl;
            if (lista.getTailChar() == 'N')
            {
                //std::cout << "Somou N" << std::endl;
                lista.editTailSoma();
            }
            else
            {
                //std::cout << "Adicionou N" << std::endl;
                lista.addTail('N');
            }
        }
        else if ((letra1 == 'D' && letra2 == 'N') || (letra1 == 'N' && letra2 == 'D'))
        {
            //std::cout << "Entrou A" << std::endl;
            if (lista.getTailChar() == 'A')
            {
                //std::cout << "Somou A" << std::endl;
                lista.editTailSoma();
            }
            else
            {
                //std::cout << "Adicionou A" << std::endl;
                lista.addTail('A');
            }
        }
        else if ((letra1 == 'A' && letra2 == 'N') || (letra1 == 'N' && letra2 == 'A'))
        {
            //std::cout << "Entrou D" << std::endl;
            if (lista.getTailChar() == 'D')
            {
                //std::cout << "Somou D" << std::endl;
                lista.editTailSoma();
            }
            else
            {
                //std::cout << "Adicionou D" << std::endl;
                lista.addTail('D');
            }
        }
        letra1Quant--;
        letra2Quant--;
    }
    auto fim = std::chrono::high_resolution_clock::now(); // fim da contagem de tempo
    auto duracao = fim - inicio;
    auto duracao_segundos = std::chrono::duration<double>(duracao);
lista.print();
    
    //std::cout << "Letra 1: " << aux->getLetra() << " Quantidade: " << aux->getQuantidade() << std::endl;
    std::cout << "Tempo de execucao: " << std::fixed << duracao_segundos.count() << " segundos" << std::endl;
}
