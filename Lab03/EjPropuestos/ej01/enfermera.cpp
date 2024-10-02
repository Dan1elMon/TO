#include "Enfermera.h"

Enfermera::Enfermera(string _nombre, int _edad) : Persona(_nombre, _edad) {}

void Enfermera::mostrarInformacion() {
    Persona::mostrarInformacion();
    cout << "Oficio: Enfermera" << endl;
    cout << "Cuida a los pacientes y asiste a los doctores." << endl;
}
