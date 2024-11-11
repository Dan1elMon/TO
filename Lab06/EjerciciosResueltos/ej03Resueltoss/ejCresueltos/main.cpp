#include "mainwindow.h"

#include <QApplication>
#include <thread>
#include <sstream>
#include <chrono>
#include <ctime>
#include <mutex>
#include <vector>
#include <iostream>
#include <QDebug>

// Función procesamiento secuencia
void FindPrimes1(unsigned int start, unsigned int end, std::vector<unsigned int>& vect) {
    // el bucle recorre sin tomar los números pares
    for (unsigned int x = start; x <= end; x += 2) {
        for (unsigned int y = 2; y < x; y++) {
            if ((x % y) == 0) {
                break;
            } else if ((y + 1) == x) {
                vect.push_back(x);
            }
        }
    }
}

std::mutex vectLock;
std::vector<unsigned int> primeVect;

void FindPrimes(unsigned int start, unsigned int end) {
    // recorre los n8umeros sin tomar en cuenta los pares
    for (unsigned int x = start; x <= end; x += 2) {
        // Si un número es divisible entre otro, no es primo
        for (unsigned int y = 2; y < x; y++) {
            if ((x % y) == 0) {
                break;
            } else if ((y + 1) == x) {
                vectLock.lock();
                primeVect.push_back(x);
                vectLock.unlock();
            }
        }
    }
}

void FindPrimesWithThreads(unsigned int start, unsigned int end, unsigned int numThreads) {
    std::vector<std::thread> threadVect;

    // Divide la cantidad de numeros a procesar a cada hilo
    unsigned int threadSpread = end / numThreads;
    unsigned int newEnd = start + threadSpread - 1;

    // Crear lista de primos para cada hilo
    for (unsigned int x = 0; x < numThreads; x++) {
        threadVect.emplace_back(FindPrimes, start, newEnd);
        start += threadSpread;
        newEnd += threadSpread;
    }

    for (auto& t : threadVect) {
        t.join();
    }
}

int main(int argc, char* argv[]) {
    QApplication a(argc, argv);

    // Capturar la fecha inicial completa
    int startTime = clock();

    // Encontrar números primos sin hilos
    FindPrimes1(1, 1000000, primeVect);

    // Capturar la fecha final de finalización
    int endTime = clock();

    // Imprimir el tiempo transcurrido promedio
    qDebug() << "Execution Time without threads:" << (endTime - startTime) / double(CLOCKS_PER_SEC) << "\n";

    // Con hilos
    // Capturar la fecha inicial completa
    startTime = clock();

    FindPrimesWithThreads(1, 1000000, 8);

    // Capturar la fecha final de finalización
    endTime = clock();

    // Imprimir el tiempo transcurrido promedio
    qDebug() << "Execution Time with threads:" << (endTime - startTime) / double(CLOCKS_PER_SEC) << "\n";

    MainWindow w;
    w.show();
    return a.exec();
}
