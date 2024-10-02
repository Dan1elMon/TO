#include "Beta.h"
#include <iostream>

Beta::Beta(const string& linaje, const string& fechaDeteccion, const string& lugarDeteccion)
    : Cepa(linaje, fechaDeteccion, lugarDeteccion) {}

void Beta::mostrarInformacion() const {
    cout << "Variante Beta:\n";
    Cepa::mostrarInformacion();
}
