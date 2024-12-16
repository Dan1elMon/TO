#ifndef ORNAMENTAL_H
#define ORNAMENTAL_H
#include <memory>

#include "Plant.h"

// Clase concreta para ornamentales
class Ornamental : public Plant {
public:
    Ornamental(string name, string size, string type, string sector);
    unique_ptr<Plant> clone() override;
};

#endif // ORNAMENTAL_H
