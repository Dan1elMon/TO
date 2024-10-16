#include <QCoreApplication>
#include <QDebug>
#include <vector>
#include <algorithm>

int main(int argc, char *argv[]) {
    QCoreApplication a(argc, argv);

    // Definir la función lambda que suma 3 a un número
    int (*s)(int) = [](int valor) { return valor + 3; };

    // Ejemplo con el valor de u
    int u = 5;
    qDebug() << "Resultado de sumar 3 a u:" << s(u);

    // Vector de enteros
    std::vector<int> numeros = { 5, 2, 3, 7, 1, 0, 14, 20 };

    // Iterar sobre el vector y mostrar los valores
    std::for_each(numeros.begin(), numeros.end(), [](int valor) {
        qDebug() << "Valor en el vector:" << valor;
    });

    return a.exec();
}
