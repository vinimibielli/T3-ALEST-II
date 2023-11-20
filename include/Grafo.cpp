#include "Grafo.h"
#include <iostream>
#include <vector>
#include <map>

Grafo::Grafo()
{
}

void Grafo::addGrafo(std::string elemento, std::pair<std::vector<std::pair<std::string, int>>, math::Integer> receita)
{

    if (lista.empty())
    {
        lista.push_back(elemento);
        grafo.insert(std::pair<std::string, std::pair<std::vector<std::pair<std::string, int>>, math::Integer>>(elemento, receita));
    }
    else
    {
        auto it = grafo.find(elemento);
        {
            if (it == grafo.end())
            {

                lista.push_back(elemento);
                grafo.insert(std::pair<std::string, std::pair<std::vector<std::pair<std::string, int>>, math::Integer>>(elemento, receita));
            }
            else
            {
                it->second.first.insert(it->second.first.end(), receita.first.begin(), receita.first.end());
            }
        }
    }
}

math::Integer Grafo::getQuantidade(std::string elemento)
{

    math::Integer quantidade = 0;

    if(grafo[elemento].second != 0)
    {
        return grafo[elemento].second;
    }

    for (auto componente : grafo[elemento].first)
    {
        
            if (componente.first == "hidrogenio")
            {
                // std::cout << "hidrogenio" << std::endl;
                return componente.second;
            }
            else
            {
                // std::cout << componente.first << std::endl;
                quantidade += componente.second * getQuantidade(componente.first);
            }
        
    }
    grafo[elemento].second = quantidade;
    return quantidade;
}