#ifndef BOMBERO_H
#define BOMBERO_H

#include "Persona.h"

class Bombero : public Persona {
public:
    Bombero(string _nombre, int _edad);
    void mostrarInformacion() override;
};

#endif
