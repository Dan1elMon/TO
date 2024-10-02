// bombero.h
#ifndef BOMBERO_H
#define BOMBERO_H

#include "persona.h"

class Bombero : public Persona {
public:
    Bombero(const std::string &nom, int ed) : Persona(nom, ed) {}
    void presentar() override {
        std::cout << "Soy bombero. Mi nombre es " << nombre << " y tengo " << edad << " años.\n";
    }
};

#endif // BOMBERO_H
