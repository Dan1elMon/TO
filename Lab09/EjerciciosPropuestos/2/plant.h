#ifndef PLANT_H
#define PLANT_H

#include <string>
#include <memory>
#include <iostream>
using namespace std;

// Prototipo Base
class Plant {
protected:
    string name;
    string size;
    string type;
    string sector;

public:
    Plant(string name, string size, string type, string sector);
    virtual unique_ptr<Plant> clone() = 0;
    void displayInfo();
    virtual ~Plant() {}
};

#endif // PLANT_H
