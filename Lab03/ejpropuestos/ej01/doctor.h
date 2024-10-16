#ifndef DOCTOR_H
#define DOCTOR_H

#include "Persona.h"

class Doctor : public Persona {
public:
    Doctor(string _nombre, int _edad);
    void mostrarInformacion() override;
};

#endif
