#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

// Clase base Cerrojo
class Cerrojo {
private:
    vector<int> combinacion;  // Combinación oculta

protected:
    bool verificarCombinacion(const vector<int>& intento) {
        return intento == combinacion;
    }

    void notificarCambio(const vector<int>& nuevaCombinacion, const string& rol) {
        cout << rol << " ha sido notificado del cambio de la combinación: ";
        for (int num : nuevaCombinacion) {
            cout << num << " ";
        }
        cout << endl;
    }

public:
    // Constructor que asigna una combinación inicial
    Cerrojo(const vector<int>& combinacionInicial) : combinacion(combinacionInicial) {}

    // Método para abrir el cerrojo
    virtual bool abrir(const vector<int>& intento) {
        if (verificarCombinacion(intento)) {
            cout << "Cerrojo abierto." << endl;
            return true;
        } else {
            cout << "Combinación incorrecta." << endl;
            return false;
        }
    }

    // Método para cambiar la combinación si se conoce la actual
    virtual bool cambiarCombinacion(const vector<int>& combinacionActual, const vector<int>& nuevaCombinacion) {
        if (verificarCombinacion(combinacionActual)) {
            combinacion = nuevaCombinacion;
            cout << "Combinación cambiada con éxito." << endl;
            return true;
        } else {
            cout << "Combinación actual incorrecta. No se puede cambiar." << endl;
            return false;
        }
    }
};

// Clase Director, con acceso completo
class Director : public Cerrojo {
public:
    Director(const vector<int>& combinacionInicial) : Cerrojo(combinacionInicial) {}

    bool cambiarCombinacion(const vector<int>& combinacionActual, const vector<int>& nuevaCombinacion) override {
        bool exito = Cerrojo::cambiarCombinacion(combinacionActual, nuevaCombinacion);
        if (exito) {
            notificarCambio(nuevaCombinacion, "Director");
        }
        return exito;
    }
};

// Clase Gerencia, también con acceso completo
class Gerencia : public Cerrojo {
public:
    Gerencia(const vector<int>& combinacionInicial) : Cerrojo(combinacionInicial) {}

    bool cambiarCombinacion(const vector<int>& combinacionActual, const vector<int>& nuevaCombinacion) override {
        bool exito = Cerrojo::cambiarCombinacion(combinacionActual, nuevaCombinacion);
        if (exito) {
            notificarCambio(nuevaCombinacion, "Gerente");
        }
        return exito;
    }
};

// Clase Empleado, con acceso limitado (consulta de estado)
class Empleado : public Cerrojo {
private:
    Cerrojo* director;
    Cerrojo* gerente;

public:
    Empleado(const vector<int>& combinacionInicial, Cerrojo* dir, Cerrojo* ger) 
        : Cerrojo(combinacionInicial), director(dir), gerente(ger) {}

    // Método que devuelve el estado de acceso del empleado (colores)
    string consultarAcceso(const vector<int>& intento) {
        if (verificarCombinacion(intento)) {
            return "Verde: Acceso concedido.";
        } else {
            return "Rojo: Aún sin acceso.";
        }
    }

    bool cambiarCombinacion(const vector<int>& combinacionActual, const vector<int>& nuevaCombinacion) override {
        bool exito = Cerrojo::cambiarCombinacion(combinacionActual, nuevaCombinacion);
        if (exito) {
            cout << "Empleado ha cambiado la combinación." << endl;
            director->cambiarCombinacion(combinacionActual, nuevaCombinacion);  // Notifica al director
            gerente->cambiarCombinacion(combinacionActual, nuevaCombinacion);   // Notifica al gerente
        }
        return exito;
    }
};

// Función para ingresar combinación de 3 números
vector<int> ingresarCombinacion() {
    vector<int> combinacion(3);
    cout << "Ingrese 3 números entre 0 y 9 separados por espacio: ";
    for (int i = 0; i < 3; ++i) {
        cin >> combinacion[i];
        // Validar que el número esté en el rango 0-9
        while (combinacion[i] < 0 || combinacion[i] > 9) {
            cout << "Número inválido, ingrese un número entre 0 y 9: ";
            cin >> combinacion[i];
        }
    }
    return combinacion;
}

// Menú interactivo
void menuInteractivo(map<int, Cerrojo*>& empleados, vector<int> combinacionInicial) {
    int id;
    int opcion;
    vector<int> intento, nuevaCombinacion;

    cout << "Ingrese su ID de empleado: ";
    cin >> id;

    auto it = empleados.find(id);
    if (it == empleados.end()) {
        cout << "Empleado no encontrado." << endl;
        return;
    }

    Cerrojo* empleado = it->second;

    cout << "1. Abrir cerrojo\n2. Cambiar combinación\nElija una opción: ";
    cin >> opcion;

    if (opcion == 1) {
        intento = ingresarCombinacion();
        empleado->abrir(intento);
    } else if (opcion == 2) {
        cout << "Ingrese la combinación actual:\n";
        intento = ingresarCombinacion();

        cout << "Ingrese la nueva combinación:\n";
        nuevaCombinacion = ingresarCombinacion();

        empleado->cambiarCombinacion(intento, nuevaCombinacion);
    } else {
        cout << "Opción no válida." << endl;
    }
}

int main() {
    vector<int> combinacionInicial = {1, 2, 3};

    // Crear empleados y director/gerente
    Director director(combinacionInicial);
    Gerencia gerente(combinacionInicial);
    Empleado empleado1(combinacionInicial, &director, &gerente);
    Empleado empleado2(combinacionInicial, &director, &gerente);

    // Mapa de empleados
    map<int, Cerrojo*> empleados;
    empleados[1001] = &director;
    empleados[1002] = &gerente;
    empleados[1003] = &empleado1;
    empleados[1004] = &empleado2;

    while (true) {
        menuInteractivo(empleados, combinacionInicial);
        cout << endl;
    }

    return 0;
}
