#include "Ornamental.h"
#include <memory>
#include "Ornamental.h"

Ornamental::Ornamental(string name, string size, string type, string sector)
    : Plant(name, size, type, sector) {}


unique_ptr<Plant> Ornamental::clone() {
    return make_unique<Ornamental>(*this);
}
