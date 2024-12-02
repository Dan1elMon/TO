#ifndef PRODUCTFACTORY_H
#define PRODUCTFACTORY_H

#include "producto.h"
#include <iostream>

void Cliente(const AbstractFactory &f) {
    const AbstractProductoA* producto_a = f.CrearProductoA();
    const AbstractProductoB* producto_b = f.CrearProductoB();

    std::cout << producto_b->Funcion1_B() << std::endl;
    std::cout << producto_b->Funcion2_B(*producto_a) << std::endl;

    delete producto_a;
    delete producto_b;
}

#endif // PRODUCTFACTORY_H
