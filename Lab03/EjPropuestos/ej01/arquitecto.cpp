#include "Arquitecto.h"

Arquitecto::Arquitecto(string _nombre, int _edad) : Persona(_nombre, _edad) {}

void Arquitecto::mostrarInformacion() {
    Persona::mostrarInformacion();
    cout << "Oficio: Arquitecto" << endl;
    cout << "Diseniaa y planifica edificios." << endl;
}
