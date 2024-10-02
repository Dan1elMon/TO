#ifndef ENFERMERA_H
#define ENFERMERA_H

#include "Persona.h"

class Enfermera : public Persona {
public:
    Enfermera(string _nombre, int _edad);
    void mostrarInformacion() override;
};

#endif
