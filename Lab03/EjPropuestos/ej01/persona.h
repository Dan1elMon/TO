#ifndef PERSONA_H
#define PERSONA_H

#include <string>
#include <iostream>

using namespace std;

class Persona {
protected:
    string nombre;
    int edad;

public:
    Persona(string _nombre, int _edad);
    virtual void mostrarInformacion();
};

#endif
