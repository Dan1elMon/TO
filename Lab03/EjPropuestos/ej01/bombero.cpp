#include "Bombero.h"

Bombero::Bombero(string _nombre, int _edad) : Persona(_nombre, _edad) {}

void Bombero::mostrarInformacion() {
    Persona::mostrarInformacion();
    cout << "Oficio: Bombero" << endl;
    cout << "Apaga incendios y realiza rescates." << endl;
}
