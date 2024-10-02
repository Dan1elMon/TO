#include "Cepa.h"
#include <iostream>

Cepa::Cepa(const string& linaje, const string& fechaDeteccion, const string& lugarDeteccion)
    : linaje(linaje), fechaDeteccion(fechaDeteccion), lugarDeteccion(lugarDeteccion) {}

void Cepa::mostrarInformacion() const {
    cout << "Linaje: " << linaje << "\n"
         << "Fecha de detección: " << fechaDeteccion << "\n"
         << "Lugar de detección: " << lugarDeteccion << "\n";
}
