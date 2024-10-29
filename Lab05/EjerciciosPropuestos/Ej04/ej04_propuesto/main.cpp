//#include "mainwindow.h"

#include <QApplication>
#include <QCoreApplication>
#include <iostream>
using namespace std;

template <typename T>

//declarando nodos para el arbol
class Nodo {
public:
    T valor;
    Nodo* izquierdo;
    Nodo* derecho;

    Nodo(T val) : valor(val), izquierdo(nullptr), derecho(nullptr) {}
};
//template generico para los datos del arbol y admita numeros enteros, flotantes y otros tipos de datosasd
template <typename T>
class ArbolBinario {
private:
    Nodo<T>* raiz;

    Nodo<T>* insertar(Nodo<T>* nodo, T val) {
        if (!nodo) return new Nodo<T>(val);

        if (val < nodo->valor) {
            nodo->izquierdo = insertar(nodo->izquierdo, val);
        } else {
            nodo->derecho = insertar(nodo->derecho, val);
        }
        return nodo;
    }

    void imprimirEnOrden(Nodo<T>* nodo) {
        if (!nodo) return;
        imprimirEnOrden(nodo->izquierdo);
        cout << nodo->valor << " ";
        imprimirEnOrden(nodo->derecho);
    }

public:
    ArbolBinario() : raiz(nullptr) {}

    void insertar(T val) {
        raiz = insertar(raiz, val);
    }

    void imprimirEnOrden() {
        imprimirEnOrden(raiz);
        cout << endl;
    }
};

int main(int argc, char *argv[]) {
    QCoreApplication a(argc, argv);

    //con enteros
    ArbolBinario<int> arbolEnteros;
    arbolEnteros.insertar(7);
    arbolEnteros.insertar(2);
    arbolEnteros.insertar(8);
    arbolEnteros.insertar(9);
    arbolEnteros.insertar(3);

    cout << "arbol de enteros en orden: ";
    arbolEnteros.imprimirEnOrden();

    //CON LETRAS
    ArbolBinario<char> arbolCaracteres;
    arbolCaracteres.insertar('C');
    arbolCaracteres.insertar('O');
    arbolCaracteres.insertar('S');
    arbolCaracteres.insertar('T');
    arbolCaracteres.insertar('A');

    cout << "arbol de caracteres en orden: ";
    arbolCaracteres.imprimirEnOrden();

    //Con flotantes
    ArbolBinario<float> arbolFlotantes;
    arbolFlotantes.insertar(5.5);
    arbolFlotantes.insertar(3.3);
    arbolFlotantes.insertar(8.8);
    arbolFlotantes.insertar(1.1);
    arbolFlotantes.insertar(4.4);
    cout << "arbol de flotantes en orden: ";
    arbolFlotantes.imprimirEnOrden();

    return a.exec();
}
