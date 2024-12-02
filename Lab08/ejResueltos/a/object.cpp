#include <iostream>
#include <string>
using namespace std;
class Toy {
    protected:
    string name;
    float price;
    public:
    virtual void prepareParts() = 0;
    virtual void combineParts() = 0;
    virtual void assembleParts() = 0;
    virtual void applyLabel() = 0;
    virtual void showProduct() = 0;
};
class Car : public Toy {
//
public:
    void prepareParts() { cout << "Preparando partes de Car" << endl; };
    void combineParts() { cout << "Combinando partes de Car" << endl; };
    void assembleParts() { cout << "ensamblando partes de Car" << endl; };
    void applyLabel() { cout << "aplicando etiquetado de Car" << endl; };
    void showProduct() { cout << "Name: " <<name<< endl <<"Price: "<<price<<endl; };
};
class Bike : public Toy {
//
    public:
    void prepareParts() { cout << "Preparando partes de Bike" << endl; };
    void combineParts() { cout << "Combinando partes de Bike" << endl; };
    void assembleParts() { cout << "ensamblando partes de Bike" << endl; };
    void applyLabel() { cout << "aplicando etiquetado de Bike" << endl; };
    void showProduct() { cout << "Name: " << name << endl << "Price: " << price << endl; };
};
class Plane : public Toy {
//
public:
    void prepareParts() { cout << "Preparando partes de Plane" << endl; };
    void combineParts() { cout << "Combinando partes de Plane" << endl; };
    void assembleParts() { cout << "ensamblando partes de Plane" << endl; };
    void applyLabel() { cout << "aplicando etiquetado de Plane" << endl; };
    void showProduct() { cout << "Name: " << name << endl << "Price: " << price << endl; };
};