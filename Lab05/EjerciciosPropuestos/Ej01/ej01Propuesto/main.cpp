#include <QCoreApplication>
#include <iostream>
#include <string>
using namespace std;

template <typename T>
class Nodo {
public:
    T valor;
    Nodo* siguiente;

    Nodo(T val) : valor(val), siguiente(nullptr) {}
};

template <typename T>
class ListaEnlazada {
private:
    Nodo<T>* cabeza;

public:
    ListaEnlazada() : cabeza(nullptr) {}

    void insertar(T val) {
        Nodo<T>* nuevoNodo = new Nodo<T>(val);
        nuevoNodo->siguiente = cabeza;
        cabeza = nuevoNodo;
    }

    void imprimir() {
        Nodo<T>* actual = cabeza;
        while (actual) {
            cout << actual->valor << " ";
            actual = actual->siguiente;
        }
        cout << endl;
    }

    ~ListaEnlazada() {
        Nodo<T>* actual = cabeza;
        while (actual) {
            Nodo<T>* siguiente = actual->siguiente;
            delete actual;
            actual = siguiente;
        }
    }
};

int main(int argc, char *argv[]) {
    QCoreApplication a(argc, argv);

    // ejemplo con edades
    ListaEnlazada<int> listaEdades;
    listaEdades.insertar(10);
    listaEdades.insertar(30);
    listaEdades.insertar(20);
    listaEdades.insertar(80);
    cout << "Secuencia de edades: ";
    listaEdades.imprimir();

    // ejemplo con palabras
    ListaEnlazada<string> listaPalabras;
    listaPalabras.insertar("Este");
    listaPalabras.insertar("es");
    listaPalabras.insertar("un");
    listaPalabras.insertar("texto");
    listaPalabras.insertar("de");
    listaPalabras.insertar("prueba");
    listaPalabras.insertar("en");
    listaPalabras.insertar("Qt");

    cout << "Secuencia de palabras: ";
    listaPalabras.imprimir();

    return a.exec();
}
