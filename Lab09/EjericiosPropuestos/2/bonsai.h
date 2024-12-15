#ifndef BONSAI_H
#define BONSAI_H

#include "Plant.h"

// Clase concreta para bonsáis
class Bonsai : public Plant {
public:
    Bonsai(string name, string size, string type, string sector);
    unique_ptr<Plant> clone() override;
};

#endif // BONSAI_H
