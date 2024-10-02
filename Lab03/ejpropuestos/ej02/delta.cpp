#include "Delta.h"
#include <iostream>

Delta::Delta(const string& linaje, const string& fechaDeteccion, const string& lugarDeteccion)
    : Cepa(linaje, fechaDeteccion, lugarDeteccion) {}

void Delta::mostrarInformacion() const {
    cout << "Variante Delta:\n";
    Cepa::mostrarInformacion();
}
