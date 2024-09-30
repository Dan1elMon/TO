// persona.h
#ifndef PERSONA_H
#define PERSONA_H

#include <string>
#include <iostream>

class Persona {
protected:
    std::string nombre;
    int edad;

public:
    Persona(const std::string &nom, int ed) : nombre(nom), edad(ed) {}
    virtual void presentar() = 0; // Método virtual puro
};

#endif // PERSONA_H
