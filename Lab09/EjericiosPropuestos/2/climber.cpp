#include "Climber.h"

Climber::Climber(string name, string size, string type, string sector)
    : Plant(name, size, type, sector) {}

unique_ptr<Plant> Climber::clone() {
    return make_unique<Climber>(*this);
}
