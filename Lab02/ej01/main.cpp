#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <cctype>

using namespace std;

// Clase que se encarga de analizar la operación matemática
class Analizador {
public:
    // Método que analiza la cadena de operación y devuelve los números y operadores
    void analizar(const string& operacion, vector<int>& numeros, vector<char>& operadores) {
        stringstream ss(operacion);
        int numero;
        char operador;

        // Leer el primer número
        ss >> numero;
        numeros.push_back(numero);

        // Leer los operadores y números siguientes
        while (ss >> operador) {
            if (isspace(operador)) continue; // Ignorar espacios
            operadores.push_back(operador);
            ss >> numero;
            numeros.push_back(numero);
        }
    }
};

// Clase que se encarga de realizar las operaciones matemáticas
class Calculadora {
public:
    // Método que realiza la operación indicada
    int operar(const vector<int>& numeros, const vector<char>& operadores) {
        int resultado = numeros[0];

        for (size_t i = 0; i < operadores.size(); ++i) {
            switch (operadores[i]) {
                case '+':
                    resultado += numeros[i + 1];
                    break;
                case '-':
                    resultado -= numeros[i + 1];
                    break;
                case '*':
                    resultado *= numeros[i + 1];
                    break;
                case '/':
                    if (numeros[i + 1] != 0)
                        resultado /= numeros[i + 1];
                    else {
                        cerr << "Error: División por cero" << endl;
                        return 0;
                    }
                    break;
                default:
                    cerr << "Error: Operador desconocido " << operadores[i] << endl;
                    return 0;
            }
        }

        return resultado;
    }
};

// Clase que procesa la operación ingresada
class Procesador {
private:
    Analizador analizador;
    Calculadora calculadora;

public:
    // Método que procesa la cadena de operación
    void procesar(const string& operacion) {
        vector<int> numeros;
        vector<char> operadores;

        analizador.analizar(operacion, numeros, operadores);
        int resultado = calculadora.operar(numeros, operadores);
        
        cout << "Resultado de la operación '" << operacion << "' es: " << resultado << endl;
    }
};

int main() {
    Procesador procesador;

    string entrada;
    cout << "Ingrese la operación (máximo 6 números): ";
    getline(cin, entrada);

    procesador.procesar(entrada);

    return 0;
}
