#include <iostream>
#include <string>

using namespace std;

class infante {
private:
    string nombre;
public:
    infante(const string &nom) : nombre(nom) {}

    void gatear() {
        cout << nombre << " gateando....\n";
    }
};

class joven {
private:
    string nombre;
public: 
    joven(const string &nom) : nombre(nom) {}

    void correr() {
        cout << nombre << " corriendo...\n";
    }

    string getNombre() const { // Método para acceder al nombre
        return nombre;
    }
};

class adulto : public infante, public joven {
public:
    adulto(const string & nom) : infante(nom), joven(nom) {}

    void caminar() {
        cout << "Adulto " << joven::getNombre() << " caminando...\n"; // Accediendo al nombre a través del método
    }
};

int main() {
    // Crear un infante
    infante niño("Pedro");
    niño.gatear();

    // Crear un joven
    joven adolescente("Juan");
    adolescente.correr();

    // Crear un adulto
    adulto adulto1("Carlos");
    adulto1.gatear(); // Desde infante
    adulto1.correr(); // Desde joven
    adulto1.caminar(); // Desde adulto

    return 0;
}
