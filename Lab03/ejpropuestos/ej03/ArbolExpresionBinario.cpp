#include "ArbolExpresionBinario.h"
#include <iostream>
#include <cctype>
#include <stdexcept>

using namespace std;

void ArbolExpresionBinario::construirArbol(const string& expresion) {
    raiz = construirArbolPostfijo(expresion);
}

double ArbolExpresionBinario::evaluar(Nodo* nodo) {
    if (!nodo) return 0;

    // Si es un número, convertirlo a double y devolverlo
    if (isdigit(nodo->valor[0])) {
        return stod(nodo->valor);
    }

    // Evaluar los operandos
    double valorIzquierdo = evaluar(nodo->izquierdo.get());
    double valorDerecho = evaluar(nodo->derecho.get());

    // Realizar la operación correspondiente
    if (nodo->valor == "+") {
        return valorIzquierdo + valorDerecho;
    } else if (nodo->valor == "*") {
        return valorIzquierdo * valorDerecho;
    }

    throw invalid_argument("Operador no válido: " + nodo->valor);
}

unique_ptr<Nodo> ArbolExpresionBinario::construirArbolPostfijo(const string& expresion) {
    vector<unique_ptr<Nodo>> pila;
    string token;
    istringstream tokens(expresion);

    while (tokens >> token) {
        // Si el token es un número, crear un nuevo nodo
        if (isdigit(token[0])) {
            pila.push_back(make_unique<Nodo>(token));
        } else {
            // Si el token es un operador, pop dos nodos y crear un nuevo nodo
            if (pila.size() < 2) {
                throw invalid_argument("Expresión postfija inválida.");
            }
            auto nodoDerecho = move(pila.back());
            pila.pop_back();
            auto nodoIzquierdo = move(pila.back());
            pila.pop_back();

            auto nodoOperador = make_unique<Nodo>(token);
            nodoOperador->izquierdo = move(nodoIzquierdo);
            nodoOperador->derecho = move(nodoDerecho);

            pila.push_back(move(nodoOperador));
        }
    }

    if (pila.size() != 1) {
        throw invalid_argument("Expresión postfija inválida.");
    }

    return move(pila.back());
}
