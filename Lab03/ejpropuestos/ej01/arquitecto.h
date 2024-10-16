#ifndef ARQUITECTO_H
#define ARQUITECTO_H

#include "Persona.h"

class Arquitecto : public Persona {
public:
    Arquitecto(string _nombre, int _edad);
    void mostrarInformacion() override;
};

#endif
