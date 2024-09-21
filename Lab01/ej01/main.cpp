#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>

using namespace std;

void ordenarDescendente(vector<int>& numeros) {
    // Algoritmo de ordenamiento de burbuja
    int n = numeros.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (numeros[j] < numeros[j + 1]) {
                swap(numeros[j], numeros[j + 1]);
            }
        }
    }
}

int main() {
    int N;
    cout << "Digite un numero entero positivo N: ";
    cin >> N;

    // Validar que N sea positivo
    if (N <= 0) {
        cout << "Por favor, ingrese un numero entero positivo." << endl;
        return 1;
    }

    char opcion;
    cout << "Ingrese 'g' para generar numeros aleatorios o 'i' para ingresarlos manualmente: ";
    cin >> opcion;

    vector<int> numeros;

    if (opcion == 'g') {
        // Inicializar generador de números aleatorios
        srand(static_cast<unsigned int>(time(0))); // Inicializar con la hora actual

        for (int i = 0; i < N; i++) {
            int numeroAleatorio = rand() % N + 1; // Números entre 1 y N
            numeros.push_back(numeroAleatorio);
        }
        cout << "Números generados aleatoriamente: ";
    } else if (opcion == 'i') {
        cout << "Ingrese " << N << " numeros enteros: ";
        for (int i = 0; i < N; i++) {
            int numero;
            cin >> numero;
            numeros.push_back(numero);
        }
    } else {
        cout << "Opción no válida." << endl;
        return 1;
    }

    // Mostrar los números ingresados o generados
    for (int numero : numeros) {
        cout << numero << " ";
    }
    cout << endl;

    // Ordenar de mayor a menor
    ordenarDescendente(numeros);

    // Mostrar los números ordenados
    cout << "Números ordenados de mayor a menor: ";
    for (int numero : numeros) {
        cout << numero << " ";
    }
    cout << endl;

    return 0;
}
