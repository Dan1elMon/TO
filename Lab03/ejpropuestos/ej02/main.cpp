#include "Alfa.h"
#include "Beta.h"
#include "Gamma.h"
#include "Delta.h"
#include "Omicron.h"
#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<Cepa*> cepas;

    // Crear cepas
    cepas.push_back(new Alfa("B.1.1.7", "Septiembre de 2020", "Reino Unido"));
    cepas.push_back(new Beta("B.1.351", "Mayo de 2020", "Sudamérica"));
    cepas.push_back(new Gamma("P.1", "Noviembre de 2020", "Brasil"));
    cepas.push_back(new Delta("B.1.617.2", "Octubre de 2020", "India"));
    cepas.push_back(new Omicron("B.1.1.529", "Noviembre de 2021", "Varios países (África, Hong Kong, Israel, etc.)"));

    // Mostrar información de cada cepa
    for (const auto& cepa : cepas) {
        cepa->mostrarInformacion();
        cout << "------------------------\n";
    }

    // Liberar memoria
    for (auto& cepa : cepas) {
        delete cepa;
    }

    return 0;
}
