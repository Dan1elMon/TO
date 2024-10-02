#ifndef CEPA_H
#define CEPA_H

#include <string>
using namespace std;

class Cepa {
protected:
    string linaje;
    string fechaDeteccion;
    string lugarDeteccion;

public:
    Cepa(const string& linaje, const string& fechaDeteccion, const string& lugarDeteccion);

    virtual void mostrarInformacion() const;
};

#endif
