#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

// Función para fusionar dos subvectores
void merge(vector<int>& numeros, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<int> L(n1), R(n2);

    for (int i = 0; i < n1; i++)
        L[i] = numeros[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = numeros[mid + 1 + j];

    int i = 0, j = 0, k = left;

    // Fusionar los vectores L y R de nuevo en numeros
    while (i < n1 && j < n2) {
        if (L[i] >= R[j]) { // Ordenar de mayor a menor
            numeros[k] = L[i];
            i++;
        } else {
            numeros[k] = R[j];
            j++;
        }
        k++;
    }

    // Copiar los elementos restantes de L, si los hay
    while (i < n1) {
        numeros[k] = L[i];
        i++;
        k++;
    }

    // Copiar los elementos restantes de R, si los hay
    while (j < n2) {
        numeros[k] = R[j];
        j++;
        k++;
    }
}

// Función principal de Merge Sort
void mergeSort(vector<int>& numeros, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        // Ordenar la primera y la segunda mitad
        mergeSort(numeros, left, mid);
        mergeSort(numeros, mid + 1, right);

        // Fusionar las mitades ordenadas
        merge(numeros, left, mid, right);
    }
}

int main() {
    int N;
    cout << "Ingrese un numero entero positivo N: ";
    cin >> N;

    // verificar el numero ingresado es positivo
    if (N <= 0) {
        cout << "Error, ingrese un numero entero positivo." << endl;
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
        cout << "Numeros aleatorios: ";
    } else if (opcion == 'i') {
        cout << "Ingrese " << N << " numero entero: ";
        for (int i = 0; i < N; i++) {
            int numero;
            cin >> numero;
            numeros.push_back(numero);
        }
    } else {
        cout << "Opcion no valida." << endl;
        return 1;
    }

    // Mostrar los números ingresados o generados
    for (int numero : numeros) {
        cout << numero << " ";
    }
    cout << endl;

    // Ordenar de mayor a menor usando Merge Sort
    mergeSort(numeros, 0, numeros.size() - 1);

    // Mostrar los números ordenados
    cout << "Numeros ordenados: ";
    for (int numero : numeros) {
        cout << numero << " ";
    }
    cout << endl;

    return 0;
}
