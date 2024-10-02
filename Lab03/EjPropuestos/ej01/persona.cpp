#include "Persona.h"

Persona::Persona(string _nombre, int _edad) : nombre(_nombre), edad(_edad) {}

void Persona::mostrarInformacion() {
    cout << "Nombre: " << nombre << endl;
    cout << "Edad: " << edad << " anios" << endl;
}
