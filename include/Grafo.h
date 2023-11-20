#ifndef Grafo_h
#define Grafo_h
#include <map>
#include <vector>
#include "math_Integer.h"
#include "math_Rational.h"
#include "math_Unsigned.h"

class Grafo
{
private:
    std::map<std::string, std::vector<std::pair<std::string, int>>> grafo;
    std::vector<std::string> lista;

public:
    Grafo();
    void addGrafo(std::string elemento, std::vector<std::pair<std::string, int>>);
    unsigned long long int getQuantidade(std::string elemento);
};

#endif