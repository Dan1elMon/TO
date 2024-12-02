#include <iostream>
#include <string>
#include "ToyFactory.cpp"
using namespace std;
//client
int main()
{
    int type;
        while (1) {
        cout << endl << "Ingresa un tipo (1 a 3) o '0' para salir" << endl;
        cin >> type;

        if (!type) {
            break;
        }
        Toy *v = ToyFactory::createToy(type);
        if (v) {
            v->showProduct();
            delete v;
        }
    }
    cout << "Saliendo..." << endl;
    return 0;
}