#ifndef GAMMA_H
#define GAMMA_H

#include "Cepa.h"

class Gamma : public Cepa {
public:
    Gamma(const string& linaje, const string& fechaDeteccion, const string& lugarDeteccion);

    void mostrarInformacion() const override;
};

#endif
