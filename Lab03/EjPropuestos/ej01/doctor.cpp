#include "Doctor.h"

Doctor::Doctor(string _nombre, int _edad) : Persona(_nombre, _edad) {}

void Doctor::mostrarInformacion() {
    Persona::mostrarInformacion();
    cout << "Oficio: Doctor" << endl;
    cout << "Diagnostica y trata enfermedades." << endl;
}
