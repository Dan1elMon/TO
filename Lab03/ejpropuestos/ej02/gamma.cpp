#include "Gamma.h"
#include <iostream>

Gamma::Gamma(const string& linaje, const string& fechaDeteccion, const string& lugarDeteccion)
    : Cepa(linaje, fechaDeteccion, lugarDeteccion) {}

void Gamma::mostrarInformacion() const {
    cout << "Variante Gamma:\n";
    Cepa::mostrarInformacion();
}
