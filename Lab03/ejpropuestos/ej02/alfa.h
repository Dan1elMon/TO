#ifndef ALFA_H
#define ALFA_H

#include "Cepa.h"

class Alfa : public Cepa {
public:
    Alfa(const string& linaje, const string& fechaDeteccion, const string& lugarDeteccion);

    void mostrarInformacion() const override;
};

#endif
