#ifndef Grafo_h
#define Grafo_h
#include <map>
#include <vector>
#include <string>
#include <iostream>
#include "math_Integer.h"

class Grafo
{
private:
    std::map<std::string, std::pair<std::vector<std::pair<std::string, int>>, math::Integer>> grafo;
    std::vector<std::string> lista;

public:
    Grafo();
    void addGrafo(std::string elemento, std::pair<std::vector<std::pair<std::string, int>>, math::Integer>);
    math::Integer getQuantidade(std::string elemento);
};

#endif