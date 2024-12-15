#include "PlantFactory.h"
#include "Climber.h"
#include "Tree.h"
#include "Ornamental.h"
#include "Bonsai.h"

PlantFactory::PlantFactory() {
    prototypes["climber"] = make_unique<Climber>("Trepadora", "Mediana", "Trepadora", "Trepadoras");
    prototypes["tree"] = make_unique<Tree>("Arbol Normal", "Grande", "Arbol", "Arboles Normales");
    prototypes["ornamental"] = make_unique<Ornamental>("Ornamental", "Pequenia", "Ornamental", "Ornamentales");
    prototypes["bonsai"] = make_unique<Bonsai>("BonsAi", "Pequenia", "BonsAi", "BonsAis");
}

unique_ptr<Plant> PlantFactory::createPlant(const string& type) {
    if (prototypes.find(type) != prototypes.end()) {
        return prototypes[type]->clone();
    }
    return nullptr;
}
