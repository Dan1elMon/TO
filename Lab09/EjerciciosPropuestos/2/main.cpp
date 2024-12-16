#include "PlantFactory.h"

int main() {
    PlantFactory plantFactory;

    // Crear y mostrar una trepadora
    auto climber = plantFactory.createPlant("climber");
    climber->displayInfo();

    // Crear y mostrar un bonsái
    auto bonsai = plantFactory.createPlant("bonsai");
    bonsai->displayInfo();


    // Crear y mostrar un tree
    auto tree = plantFactory.createPlant("tree");
    tree->displayInfo();

    // Crear y mostrar un tree
    auto ornamental = plantFactory.createPlant("ornamental");
    ornamental->displayInfo();

    return 0;
}
