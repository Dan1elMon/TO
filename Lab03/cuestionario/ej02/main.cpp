#include <iostream>
using namespace std;

class Animal {
public:
    virtual void hacerSonido() const {  // Función virtual
        cout << "El animal hace un sonido" << endl;
    }
};

class Perro : public Animal {
public:
    void hacerSonido() const override {  // Sobrescritura de función virtual
        cout << "El perro ladra" << endl;
    }
};

class Gato : public Animal {
public:
    void hacerSonido() const override {
        cout << "El gato maúlla" << endl;
    }
};

void hacerSonidoAnimal(const Animal& animal) {
    animal.hacerSonido();  // Se invoca la versión de la clase derivada
}

int main() {
    Perro perro;
    Gato gato;
    Animal animal;

    hacerSonidoAnimal(perro);  // Llama a Perro::hacerSonido()
    hacerSonidoAnimal(gato);   // Llama a Gato::hacerSonido()
    hacerSonidoAnimal(animal); // Llama a Animal::hacerSonido()

    return 0;
}
