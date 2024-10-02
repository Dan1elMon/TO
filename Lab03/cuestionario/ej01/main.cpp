#include <iostream>
using namespace std;

void imprimir(int x) {
    cout << "Entero: " << x << endl;
}

void imprimir(double x) {
    cout << "Doble: " << x << endl;
}

void imprimir(string x) {
    cout << "Cadena: " << x << endl;
}

int main() {
    imprimir(5);          // Llama a la versión de int
    imprimir(3.14);       // Llama a la versión de double
    imprimir("Hola");     // Llama a la versión de string
    return 0;
}
