// arquitecto.h
#ifndef ARQUITECTO_H
#define ARQUITECTO_H

#include "persona.h"

class Arquitecto : public Persona {
public:
    Arquitecto(const std::string &nom, int ed) : Persona(nom, ed) {}
    void presentar() override {
        std::cout << "Soy arquitecto. Mi nombre es " << nombre << " y tengo " << edad << " años.\n";
    }
};

#endif // ARQUITECTO_H
