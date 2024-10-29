#include "mainwindow.h"
#include <QApplication>
#include <iostream>

using namespace std;

template <typename Tipo>
Tipo aritmetica(Tipo x, Tipo y) {
    return x + y;
}

char mayorLetras(char a, char b) {
    return (a > b ? a : b);
}

int mayorNumeros(int a, int b) {
    return (a > b ? a : b);
}

template <typename Tipo>
Tipo mayorDe(Tipo a, Tipo b) {
    return (a > b ? a : b);
}

template <typename T>
class Contenedor {
public:
    T metodo1(int xx) {
        return array[xx];
    }
    void metodo2(T val, int i) {
        array[i] = val;
    }
    void mostrar() const;
private:
    T array[4] = {0};  // Inicializamos el arreglo
};

template<typename T>
void Contenedor<T>::mostrar() const {
    for (int i = 0; i < 4; i++) {  // Cambié `<=4` a `<4`
        cout << array[i] << " ";
    }
    cout << endl;
}

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    MainWindow w;
    w.show();

    cout << "aritmetica<int>(3, 5): " << aritmetica<int>(3, 5) << endl;
    cout << "aritmetica<double>(3.45, 8.10): " << aritmetica<double>(3.45, 8.10) << endl;
    cout << "aritmetica<float>(0.14f, 0.147f): " << aritmetica<float>(0.14f, 0.147f) << endl;

    char x = mayorDe<char>('e', 'z');
    int y = mayorDe<int>(9, 4);

    cout << "Caracter mayor: " << x << endl;
    cout << "Numero mayor: " << y << endl;

    Contenedor<int> z;

    z.metodo2(10, 0);
    z.metodo2(50, 1);
    z.metodo2(60, 2);
    z.metodo2(70, 3);  // Use el indice 3 para evitar sobrescritura

    z.mostrar();
    return a.exec();
}
