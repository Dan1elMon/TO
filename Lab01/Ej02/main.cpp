#include <iostream>
#include <iomanip>
#include <vector>
#include <string>

using namespace std;

struct Jugador {
    string nombre;
    int dorsal;
    int puntosPorPartido;
};

int main() {
    vector<Jugador> jugadores = {
        {"Oliver",19, 25},
        {"Luis",17, 27},
        {"Cristian",10, 29},
        {"Pedro",1, 12},
        {"Paolo",9, 26}
    };

    cout << left << setw(20) << "Nombre" << setw(10) << "Dorsal" << setw(10) << "Goles" << endl;
    cout << string(40, '-') << endl;

    for (const auto& jugador : jugadores) {
        cout << left << setw(20) << jugador.nombre << setw(10) << jugador.dorsal<< setw(10) << jugador.puntosPorPartido << endl;
    }

    return 0;
}
