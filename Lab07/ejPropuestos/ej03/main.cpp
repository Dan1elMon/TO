#include <iostream>
#include <vector>
#include <memory>
#include <string>
#include <iomanip>

using namespace std;

// Clase base para todos los componentes del carro
class Component {
public:
    virtual ~Component() = default;
    virtual string GetName() const = 0;
    virtual string GetDetails() const = 0;
    virtual float GetPrice() const = 0;

    virtual void GetConfiguration() const = 0;
};

// Clase base para Puertas
class Puerta : public Component {
protected:
    string color;
    float price;

public:
    Puerta(const string& color, float price) : color(color), price(price) {}
    string GetName() const override { return "Puerta"; }
    string GetDetails() const override { return color; }
    float GetPrice() const override { return price; }

    void GetConfiguration() const override {
        cout << "Puerta de color " << color << " ($" << price << ")" << endl;
    }
};

// Subclases de Puertas
class PuertaBlanca : public Puerta {
public:
    PuertaBlanca() : Puerta("Blanco", 500.0f) {}
};

class PuertaNegra : public Puerta {
public:
    PuertaNegra() : Puerta("Negro", 600.0f) {}
};

class PuertaRoja : public Puerta {
public:
    PuertaRoja() : Puerta("Rojo", 700.0f) {}
};

// Clase base para Llantas
class Llanta : public Component {
protected:
    string tipo;
    float price;

public:
    Llanta(const string& tipo, float price) : tipo(tipo), price(price) {}
    string GetName() const override { return "Llanta"; }
    string GetDetails() const override { return tipo; }
    float GetPrice() const override { return price; }

    void GetConfiguration() const override {
        cout << "Llanta tipo " << tipo << " ($" << price << ")" << endl;
    }
};

// Subclases de Llantas
class LlantaBasica : public Llanta {
public:
    LlantaBasica() : Llanta("Básico", 200.0f) {}
};

class LlantaDeportiva : public Llanta {
public:
    LlantaDeportiva() : Llanta("Deportivo", 300.0f) {}
};

class LlantaTodoTerreno : public Llanta {
public:
    LlantaTodoTerreno() : Llanta("Todo Terreno", 400.0f) {}
};

// Clase base para Motores
class Motor : public Component {
protected:
    string capacidad;
    float price;

public:
    Motor(const string& capacidad, float price) : capacidad(capacidad), price(price) {}
    string GetName() const override { return "Motor"; }
    string GetDetails() const override { return capacidad; }
    float GetPrice() const override { return price; }

    void GetConfiguration() const override {
        cout << "Motor de capacidad " << capacidad << " ($" << price << ")" << endl;
    }
};

// Subclases de Motores
class Motor16L : public Motor {
public:
    Motor16L() : Motor("1.6L", 1500.0f) {}
};

class Motor20Turbo : public Motor {
public:
    Motor20Turbo() : Motor("2.0L Turbo", 3000.0f) {}
};

class Motor30Turbo : public Motor {
public:
    Motor30Turbo() : Motor("3.0L Turbo", 5000.0f) {}
};

// Clase para Modelos
class Modelo : public Component {
protected:
    string nombre;
    float price;

public:
    Modelo(const string& nombre, float price) : nombre(nombre), price(price) {}
    string GetName() const override { return "Modelo"; }
    string GetDetails() const override { return nombre; }
    float GetPrice() const override { return price; }

    void GetConfiguration() const override {
        cout << "Modelo: " << nombre << " ($" << price << ")" << endl;
    }
};

// Subclases de Modelos
class ModeloSedan : public Modelo {
public:
    ModeloSedan() : Modelo("Sedán", 15000.0f) {}
};

class ModeloSUV : public Modelo {
public:
    ModeloSUV() : Modelo("SUV", 20000.0f) {}
};

class ModeloCoupe : public Modelo {
public:
    ModeloCoupe() : Modelo("Coupe", 25000.0f) {}
};

// Clase para Colores
class Color : public Component {
protected:
    string color;
    float price;

public:
    Color(const string& color, float price) : color(color), price(price) {}
    string GetName() const override { return "Color"; }
    string GetDetails() const override { return color; }
    float GetPrice() const override { return price; }

    void GetConfiguration() const override {
        cout << "Color: " << color << " ($" << price << ")" << endl;
    }
};

// Subclases de Colores
class ColorRojo : public Color {
public:
    ColorRojo() : Color("Rojo", 500.0f) {}
};

class ColorAzul : public Color {
public:
    ColorAzul() : Color("Azul", 600.0f) {}
};

class ColorNegro : public Color {
public:
    ColorNegro() : Color("Negro", 700.0f) {}
};

// Clase para País
class Pais : public Component {
protected:
    string pais;
    float price;

public:
    Pais(const string& pais, float price) : pais(pais), price(price) {}
    string GetName() const override { return "País"; }
    string GetDetails() const override { return pais; }
    float GetPrice() const override { return price; }

    void GetConfiguration() const override {
        cout << "Fabricado en: " << pais << " ($" << price << ")" << endl;
    }
};

// Subclases de País
class PaisMexico : public Pais {
public:
    PaisMexico() : Pais("Mexico", 2000.0f) {}
};

class PaisAlemania : public Pais {
public:
    PaisAlemania() : Pais("Alemania", 3000.0f) {}
};

class PaisJapon : public Pais {
public:
    PaisJapon() : Pais("Japon", 4000.0f) {}
};

// Clase para Frenos
class Freno : public Component {
protected:
    string tipo;
    float price;

public:
    Freno(const string& tipo, float price) : tipo(tipo), price(price) {}
    string GetName() const override { return "Freno"; }
    string GetDetails() const override { return tipo; }
    float GetPrice() const override { return price; }

    void GetConfiguration() const override {
        cout << "Frenos: " << tipo << " ($" << price << ")" << endl;
    }
};

// Subclases de Frenos
class FrenoDeDisco : public Freno {
public:
    FrenoDeDisco() : Freno("Disco", 1000.0f) {}
};

class FrenoDeTambor : public Freno {
public:
    FrenoDeTambor() : Freno("Tambor", 800.0f) {}
};

// Clase para Turbo
class Turbo : public Component {
protected:
    string tipo;
    float price;

public:
    Turbo(const string& tipo, float price) : tipo(tipo), price(price) {}
    string GetName() const override { return "Turbo"; }
    string GetDetails() const override { return tipo; }
    float GetPrice() const override { return price; }

    void GetConfiguration() const override {
        cout << "Turbo: " << tipo << " ($" << price << ")" << endl;
    }
};

// Subclases de Turbo
class TurboSimple : public Turbo {
public:
    TurboSimple() : Turbo("Simple", 2500.0f) {}
};

class TurboDoble : public Turbo {
public:
    TurboDoble() : Turbo("Doble", 4000.0f) {}
};

// Clase para Carrocería
class Carroceria : public Component {
protected:
    string tipo;
    float price;

public:
    Carroceria(const string& tipo, float price) : tipo(tipo), price(price) {}
    string GetName() const override { return "Carrocería"; }
    string GetDetails() const override { return tipo; }
    float GetPrice() const override { return price; }

    void GetConfiguration() const override {
        cout << "Carrocería: " << tipo << " ($" << price << ")" << endl;
    }
};

// Subclases de Carrocería
class CarroceriaSedan : public Carroceria {
public:
    CarroceriaSedan() : Carroceria("Sedán", 3000.0f) {}
};

class CarroceriaHatchback : public Carroceria {
public:
    CarroceriaHatchback() : Carroceria("Hatchback", 3500.0f) {}
};

class CarroceriaCoupe : public Carroceria {
public:
    CarroceriaCoupe() : Carroceria("Coupe", 4000.0f) {}
};


// Clase para Tipo de Combustible
class Combustible : public Component {
protected:
    string tipo;
    float price;

public:
    Combustible(const string& tipo, float price) : tipo(tipo), price(price) {}
    string GetName() const override { return "Combustible"; }
    string GetDetails() const override { return tipo; }
    float GetPrice() const override { return price; }

    void GetConfiguration() const override {
        cout << "Combustible: " << tipo << " ($" << price << ")" << endl;
    }
};

// Subclases de Combustible
class CombustibleGasolina : public Combustible {
public:
    CombustibleGasolina() : Combustible("Gasolina", 1000.0f) {}
};

class CombustibleDiesel : public Combustible {
public:
    CombustibleDiesel() : Combustible("Diesel", 1200.0f) {}
};

class CombustibleElectrico : public Combustible {
public:
    CombustibleElectrico() : Combustible("Electrico", 1500.0f) {}
};


// Funcion para mostrar configuraciones
void MostrarConfiguraciones(const vector<shared_ptr<Component>>& componentes) {
    float total = 0.0f;
    cout << "\nConfiguracion del Vehículo:\n";
    cout << "============================\n";
    for (const auto& componente : componentes) {
        componente->GetConfiguration();
        total += componente->GetPrice();
    }
    cout << "============================\n";
    cout << "Costo Total: $" << total << endl;
}

// Funcion para mostrar el menú de opciones y devolver la seleccion del usuario
template <typename T>
shared_ptr<Component> SeleccionarOpcion(const vector<shared_ptr<T>>& opciones) {
    int opcion;
    cout << "Seleccione una opcion:\n";
    for (size_t i = 0; i < opciones.size(); ++i) {
        cout << i + 1 << ". " << opciones[i]->GetDetails() << " ($" << opciones[i]->GetPrice() << ")\n";
    }
    cout << "Opcion: ";
    cin >> opcion;
    if (opcion > 0 && static_cast<size_t>(opcion) <= opciones.size()) {
        return opciones[opcion - 1];
    }
    cout << "Opcion inválida. Seleccion por defecto: " << opciones[0]->GetDetails() << endl;
    return opciones[0];
}


int main() {
    vector<shared_ptr<Component>> configuracion;

    // Opciones para cada categoría
    vector<shared_ptr<Puerta>> puertas = {
        make_shared<PuertaBlanca>(),
        make_shared<PuertaNegra>(),
        make_shared<PuertaRoja>()
    };

    vector<shared_ptr<Llanta>> llantas = {
        make_shared<LlantaBasica>(),
        make_shared<LlantaDeportiva>(),
        make_shared<LlantaTodoTerreno>()
    };

    vector<shared_ptr<Motor>> motores = {
        make_shared<Motor16L>(),
        make_shared<Motor20Turbo>(),
        make_shared<Motor30Turbo>()
    };

    vector<shared_ptr<Modelo>> modelos = {
        make_shared<ModeloSedan>(),
        make_shared<ModeloSUV>(),
        make_shared<ModeloCoupe>()
    };

    vector<shared_ptr<Color>> colores = {
        make_shared<ColorRojo>(),
        make_shared<ColorAzul>(),
        make_shared<ColorNegro>()
    };

    vector<shared_ptr<Pais>> paises = {
        make_shared<PaisMexico>(),
        make_shared<PaisAlemania>(),
        make_shared<PaisJapon>()
    };

    vector<shared_ptr<Freno>> frenos = {
        make_shared<FrenoDeDisco>(),
        make_shared<FrenoDeTambor>()
    };

    vector<shared_ptr<Turbo>> turbos = {
        make_shared<TurboSimple>(),
        make_shared<TurboDoble>()
    };

    vector<shared_ptr<Carroceria>> carrocerias = {
        make_shared<CarroceriaSedan>(),
        make_shared<CarroceriaHatchback>(),
        make_shared<CarroceriaCoupe>()
    };

    vector<shared_ptr<Combustible>> combustibles = {
        make_shared<CombustibleGasolina>(),
        make_shared<CombustibleDiesel>(),
        make_shared<CombustibleElectrico>()
    };

    // Menú interactivo
    cout << "Configurador de Vehículo\n";
    cout << "=========================\n";

    // Seleccion de puertas
    cout << "\nSeleccione las puertas:\n";
    configuracion.push_back(SeleccionarOpcion(puertas));

    // Seleccion de llantas
    cout << "\nSeleccione las llantas:\n";
    configuracion.push_back(SeleccionarOpcion(llantas));

    // Seleccion de motor
    cout << "\nSeleccione el motor:\n";
    configuracion.push_back(SeleccionarOpcion(motores));

    // Seleccion de modelo
    cout << "\nSeleccione el modelo:\n";
    configuracion.push_back(SeleccionarOpcion(modelos));

    // Seleccion de color
    cout << "\nSeleccione el color:\n";
    configuracion.push_back(SeleccionarOpcion(colores));

    // Seleccion de país
    cout << "\nSeleccione el país de fabricacion:\n";
    configuracion.push_back(SeleccionarOpcion(paises));

    // Seleccion de frenos
    cout << "\nSeleccione los frenos:\n";
    configuracion.push_back(SeleccionarOpcion(frenos));

    // Seleccion de turbo
    cout << "\nSeleccione el tipo de turbo:\n";
    configuracion.push_back(SeleccionarOpcion(turbos));

    // Seleccion de carrocería
    cout << "\nSeleccione la carrocería:\n";
    configuracion.push_back(SeleccionarOpcion(carrocerias));

    // Seleccion de combustible
    cout << "\nSeleccione el tipo de combustible:\n";
    configuracion.push_back(SeleccionarOpcion(combustibles));

    // Mostrar configuraciones finales
    MostrarConfiguraciones(configuracion);

    return 0;
}

