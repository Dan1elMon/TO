// enfermera.h
#ifndef ENFERMERA_H
#define ENFERMERA_H

#include "persona.h"

class Enfermera : public Persona {
public:
    Enfermera(const std::string &nom, int ed) : Persona(nom, ed) {}
    void presentar() override {
        std::cout << "Soy enfermera. Mi nombre es " << nombre << " y tengo " << edad << " años.\n";
    }
};

#endif // ENFERMERA_H
