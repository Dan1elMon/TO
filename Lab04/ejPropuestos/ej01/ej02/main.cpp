#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cstdlib>

using namespace std;

// funcion para verificar si un número es primo
bool esPrimo(int n) {
    if (n <= 1) return false;
    for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0) return false;
    }
    return true;
}

int main() {
    srand(time(0)); // semilla para numeros aleatorios

    // vector numeros aleatoris
    vector<int> numeros(100);  // vector de 100 numeros
    generate(numeros.begin(), numeros.end(), []() { return rand() % 1000; });

    //contar los numeros primos menores de 1000
    int conteoPrimos = count_if(numeros.begin(), numeros.end(), [](int n) {
        return n < 1000 && esPrimo(n);
    });

    cout << "Cantidad de numeros primos menores de 1000: " << conteoPrimos << endl;

    return 0;
}
