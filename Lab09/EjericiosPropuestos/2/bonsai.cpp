#include "Bonsai.h"

Bonsai::Bonsai(string name, string size, string type, string sector)
    : Plant(name, size, type, sector) {}

unique_ptr<Plant> Bonsai::clone() {
    return make_unique<Bonsai>(*this);
}
