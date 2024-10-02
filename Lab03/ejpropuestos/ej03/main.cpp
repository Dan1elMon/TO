#include "ArbolExpresionBinario.h"
#include <iostream>

int main() {
    ArbolExpresionBinario aeb;
    std::string expresion = "5 3 + 2 *"; // (5 + 3) * 2

    try {
        aeb.construirArbol(expresion);
        double resultado = aeb.evaluar(aeb.raiz.get());
        std::cout << "Resultado: " << resultado << std::endl; // Debe imprimir 16
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}
