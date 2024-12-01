#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Interfaz IBuilder que define las operaciones para construir partes del producto
class IBuilder {
public:
    virtual ~IBuilder() {}
    virtual void ProducirParteA() const = 0;
    virtual void ProducirParteB() const = 0;
    virtual void ProducirParteC() const = 0;
};

// Clase Producto  almacena las partes del producto final
class Producto {
public:
    vector<string> componentes;

    void ListaComponentes() const {
        cout << "Componentes: ";
        for (size_t i = 0; i < componentes.size(); i++) {
            cout << componentes[i];
            if (i < componentes.size() - 1) cout << ", ";
        }
        cout << endl;
    }
};

// BuilderEspecifico que implementa la interfaz IBuilder
class BuilderEspecifico : public IBuilder {
private:
    Producto* producto;

public:
    BuilderEspecifico() { this->Reset(); }
    ~BuilderEspecifico() { delete producto; }

    void Reset() { this->producto = new Producto(); }
    void ProducirParteA() const override { this->producto->componentes.push_back("ParteA1"); }
    void ProducirParteB() const override { this->producto->componentes.push_back("ParteB1"); }
    void ProducirParteC() const override { this->producto->componentes.push_back("ParteC1"); }

    Producto* GetProducto() {
        Producto* resultado = this->producto;
        this->Reset();
        return resultado;
    }
};

// Clase director que utiliza el builder para construir diferentes productos
class Director {
private:
    IBuilder* builder;

public:
    void SetBuilder(IBuilder* builder) { this->builder = builder; }

    void BuildProductoMinimo() {
        this->builder->ProducirParteA();
    }

    void BuildProductoCompleto() {
        this->builder->ProducirParteA();
        this->builder->ProducirParteB();
        this->builder->ProducirParteC();
    }
};

//cliente que interactúa con el director y bilder para construir productos
void ClienteCode(Director& director) {
    BuilderEspecifico* builder = new BuilderEspecifico();
    director.SetBuilder(builder);

    cout << "Producto Basico:\n";
    director.BuildProductoMinimo();
    Producto* p = builder->GetProducto();
    p->ListaComponentes();
    delete p;

    cout << "Producto Completo:\n";
    director.BuildProductoCompleto();
    p = builder->GetProducto();
    p->ListaComponentes();
    delete p;

    cout << "Producto Personalizado:\n";
    builder->ProducirParteA();
    builder->ProducirParteC();
    p = builder->GetProducto();
    p->ListaComponentes();
    delete p;

    delete builder;
}

int main() {
    Director* director = new Director();
    ClienteCode(*director);
    delete director;
    return 0;
}
