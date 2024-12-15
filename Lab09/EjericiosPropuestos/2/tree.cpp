#include "Tree.h"

Tree::Tree(string name, string size, string type, string sector)
    : Plant(name, size, type, sector) {}

unique_ptr<Plant> Tree::clone() {
    return make_unique<Tree>(*this);
}
