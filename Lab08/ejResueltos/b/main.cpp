#include <iostream>
#include "producto.h"
#include "productfactory.h"

int main() {
    std::cout << "Cliente: Tipo 1" << std::endl;
    CFactory1* f1 = new CFactory1();
    Cliente(*f1);
    delete f1;

    std::cout << "\nCliente: Tipo 2" << std::endl;
    CFactory2* f2 = new CFactory2();
    Cliente(*f2);
    delete f2;

    return 0;
}
