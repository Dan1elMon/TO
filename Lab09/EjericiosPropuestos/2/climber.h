#ifndef CLIMBER_H
#define CLIMBER_H

#include "Plant.h"

// Clase concreta para trepadoras
class Climber : public Plant {
public:
    Climber(string name, string size, string type, string sector);
    unique_ptr<Plant> clone() override;
};

#endif // CLIMBER_H
