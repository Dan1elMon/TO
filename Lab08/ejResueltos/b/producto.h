#ifndef PRODUCTO_H
#define PRODUCTO_H

#include <string>

class AbstractProductoA {
public:
    virtual ~AbstractProductoA() {}
    virtual std::string Funcion1_A() const = 0;
};

class CProductoA1 : public AbstractProductoA {
public:
    std::string Funcion1_A() const override {
        return "Producto A1";
    }
};

class CProductoA2 : public AbstractProductoA {
public:
    std::string Funcion1_A() const override {
        return "Producto A2";
    }
};

class AbstractProductoB {
public:
    virtual ~AbstractProductoB() {}
    virtual std::string Funcion1_B() const = 0;
    virtual std::string Funcion2_B(const AbstractProductoA &colaborador) const = 0;
};

class CProductoB1 : public AbstractProductoB {
public:
    std::string Funcion1_B() const override {
        return "Producto B1.";
    }

    std::string Funcion2_B(const AbstractProductoA &colaborador) const override {
        return "B1 con ayuda de " + colaborador.Funcion1_A();
    }
};

class CProductoB2 : public AbstractProductoB {
public:
    std::string Funcion1_B() const override {
        return "Producto B2.";
    }

    std::string Funcion2_B(const AbstractProductoA &colaborador) const override {
        return "B2 con ayuda de " + colaborador.Funcion1_A();
    }
};

class AbstractFactory {
public:
    virtual ~AbstractFactory() {}
    virtual AbstractProductoA* CrearProductoA() const = 0;
    virtual AbstractProductoB* CrearProductoB() const = 0;
};

class CFactory1 : public AbstractFactory {
public:
    AbstractProductoA* CrearProductoA() const override {
        return new CProductoA1();
    }

    AbstractProductoB* CrearProductoB() const override {
        return new CProductoB1();
    }
};

class CFactory2 : public AbstractFactory {
public:
    AbstractProductoA* CrearProductoA() const override {
        return new CProductoA2();
    }

    AbstractProductoB* CrearProductoB() const override {
        return new CProductoB2();
    }
};

#endif // PRODUCTO_H
