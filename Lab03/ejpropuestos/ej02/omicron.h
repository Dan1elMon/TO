#ifndef OMICRON_H
#define OMICRON_H

#include "Cepa.h"

class Omicron : public Cepa {
public:
    Omicron(const string& linaje, const string& fechaDeteccion, const string& lugarDeteccion);

    void mostrarInformacion() const override;
};

#endif
    