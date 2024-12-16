#ifndef TREE_H
#define TREE_H

#include "Plant.h"

// Clase concreta para árboles normales
class Tree : public Plant {
public:
    Tree(string name, string size, string type, string sector);
    unique_ptr<Plant> clone() override;
};

#endif // TREE_H
