#include "Alfa.h"
#include <iostream>

Alfa::Alfa(const string& linaje, const string& fechaDeteccion, const string& lugarDeteccion)
    : Cepa(linaje, fechaDeteccion, lugarDeteccion) {}

void Alfa::mostrarInformacion() const {
    cout << "Variante Alfa:\n";
    Cepa::mostrarInformacion();
}
