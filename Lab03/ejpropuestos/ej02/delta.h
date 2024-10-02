#ifndef DELTA_H
#define DELTA_H

#include "Cepa.h"

class Delta : public Cepa {
public:
    Delta(const string& linaje, const string& fechaDeteccion, const string& lugarDeteccion);

    void mostrarInformacion() const override;
};

#endif
