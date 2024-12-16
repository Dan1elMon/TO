#ifndef PLANTFACTORY_H
#define PLANTFACTORY_H

#include "Climber.h"
#include "Tree.h"
#include "Ornamental.h"
#include "Bonsai.h"
#include <unordered_map>

class PlantFactory {
private:
    unordered_map<string, unique_ptr<Plant>> prototypes;

public:
    PlantFactory();
    unique_ptr<Plant> createPlant(const string& type);
};

#endif // PLANTFACTORY_H
