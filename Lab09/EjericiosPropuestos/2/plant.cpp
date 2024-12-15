#include "Plant.h"

Plant::Plant(string name, string size, string type, string sector)
    : name(name), size(size), type(type), sector(sector) {}

void Plant::displayInfo() {
    cout << "Nombre: " << name << ", Tamanio: " << size
         << ", Tipo: " << type << ", Sector: " << sector << endl;
}
