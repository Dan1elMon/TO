#ifndef NODO_H
#define NODO_H

#include <memory>
#include <string>

class Nodo {
public:
    std::string valor;
    std::unique_ptr<Nodo> izquierdo;
    std::unique_ptr<Nodo> derecho;

    Nodo(const std::string& val) : valor(val), izquierdo(nullptr), derecho(nullptr) {}
};

#endif // NODO_H
