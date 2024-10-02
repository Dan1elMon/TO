
// doctor.h
#ifndef DOCTOR_H
#define DOCTOR_H

#include "persona.h"

class Doctor : public Persona {
public:
    Doctor(const std::string &nom, int ed) : Persona(nom, ed) {}
    void presentar() override {
        std::cout << "Soy doctor. Mi nombre es " << nombre << " y tengo " << edad << " años.\n";
    }
};

#endif // DOCTOR_H
