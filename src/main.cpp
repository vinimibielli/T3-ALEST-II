#include <iostream>
#include <chrono>
#include <fstream>
#include <sstream>
#include "Grafo.cpp"
#include "math_Integer.h"
#include "math_Rational.h"
#include "math_Unsigned.h"
#define caso "data\\casoc240.txt"

int main()
{
    auto inicio = std::chrono::high_resolution_clock::now();
    std::ifstream casos;
    Grafo grafo;
    std::string palavra;
    std::string linha;
    std::vector<std::pair<std::string, int>> conjunto;
    std::pair<std::string, int> elementos;
    bool aux = false;

    casos.open(caso); // Abre o arquivo para leitura

    if (!casos.is_open())
    { // verifica se o arquivo foi aberto

        std::cout << "nao foi possivel abrir o arquivo" << std::endl;
        return 1;
    }
    while (!casos.eof())
    { // pega cada carctere do arquivo
        // std::cout << "entrou" << std::endl;
        aux = false;
        getline(casos, linha);
        std::stringstream s(linha);
        while (!s.eof())
        {
            // std::cout << "entrou2" << std::endl;
            getline(s, palavra, ' ');
            if (palavra == "->")
            {
                aux = true;
            }
            if (aux == false)
            {
                if (isdigit(palavra[0]))
                {
                    elementos.second = std::stoi(palavra);
                }
                else
                {
                    elementos.first = palavra;
                    conjunto.push_back(elementos);
                }
            }
        }
        grafo.addGrafo(palavra, conjunto);
        conjunto.clear();
    }

    casos.close();

    std::cout << "Quantidade de hidrogenio: " << grafo.getQuantidade("ouro") << std::endl;
    auto fim = std::chrono::high_resolution_clock::now(); // fim da contagem de tempo
    auto duracao = fim - inicio;
    auto duracao_segundos = std::chrono::duration<double>(duracao);
    std::cout << "Tempo de execucao: " << std::fixed << duracao_segundos.count() << " segundos" << std::endl;
}
