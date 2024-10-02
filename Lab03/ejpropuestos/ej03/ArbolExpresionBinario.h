#ifndef ARBOL_EXPRESION_BINARIO_H
#define ARBOL_EXPRESION_BINARIO_H

#include "Nodo.h"
#include <string>
#include <vector>
#include <sstream>

class ArbolExpresionBinario {
public:
    std::unique_ptr<Nodo> raiz;

    void construirArbol(const std::string& expresion);
    double evaluar(Nodo* nodo);

private:
    std::unique_ptr<Nodo> construirArbolPostfijo(const std::string& expresion);
};

#endif // ARBOL_EXPRESION_BINARIO_H
