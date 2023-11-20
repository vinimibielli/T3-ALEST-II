#include "Grafo.h"
#include <iostream>
#include <vector>
#include <map>

Grafo::Grafo()
{
}

void Grafo::addGrafo(std::string elemento, std::vector<std::pair<std::string, int>> receita)
{

    if (lista.empty())
    {
        lista.push_back(elemento);
        grafo.insert(std::pair<std::string, std::vector<std::pair<std::string, int>>>(elemento, receita));
    }
    else
    {
        auto it = grafo.find(elemento);
        {
            if (it == grafo.end())
            {

                lista.push_back(elemento);
                grafo.insert(std::pair<std::string, std::vector<std::pair<std::string, int>>>(elemento, receita));
            }
            else
            {
                it->second.insert(it->second.end(), receita.begin(), receita.end());
            }
        }
    }
}

unsigned long long int Grafo::getQuantidade(std::string elemento)
{
    int64_t quantidade = 0;
    int64_t quantidadeAux = 0;
    std::vector<std::pair<std::string, int>> aux = grafo[elemento];

    for (int i = 0; i < aux.size(); i++)
    {
        if (aux[i].first == "hidrogenio")
        {
            return aux[i].second;
        }
        quantidade += aux[i].second * getQuantidade(aux[i].first);
    }
    return quantidade;
}