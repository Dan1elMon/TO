#include "Omicron.h"
#include <iostream>

Omicron::Omicron(const string& linaje, const string& fechaDeteccion, const string& lugarDeteccion)
    : Cepa(linaje, fechaDeteccion, lugarDeteccion) {}

void Omicron::mostrarInformacion() const {
    cout << "Variante Ómicron:\n";
    Cepa::mostrarInformacion();
}
