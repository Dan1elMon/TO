#ifndef BETA_H
#define BETA_H

#include "Cepa.h"

class Beta : public Cepa {
public:
    Beta(const string& linaje, const string& fechaDeteccion, const string& lugarDeteccion);

    void mostrarInformacion() const override;
};

#endif
