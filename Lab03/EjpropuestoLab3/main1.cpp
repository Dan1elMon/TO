#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <ctime>

using namespace std;

// Función para ingresar combinación de 3 números
vector<int> ingresarCombinacion() {
    vector<int> combinacion(3);
    cout << "Ingrese 3 números entre 0 y 9 separados por espacio: ";
    for (int i = 0; i < 3; ++i) {
        cin >> combinacion[i];
        while (combinacion[i] < 0 || combinacion[i] > 9) {
            cout << "Número inválido, ingrese un número entre 0 y 9: ";
            cin >> combinacion[i];
        }
    }
    return combinacion;
}

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
    Cerrojo(const vector<int>& combinacionInicial) : combinacion(combinacionInicial) {}

    virtual bool abrir(const vector<int>& intento) {
        if (verificarCombinacion(intento)) {
            cout << "Cerrojo abierto." << endl;
            return true;
        } else {
            cout << "Combinación incorrecta." << endl;
            return false;
        }
    }

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

    vector<int> obtenerCombinacion() const {
        return combinacion;
    }
};

// Clase Director, con acceso completo (verde)
class Director : public Cerrojo {
public:
    Director(const vector<int>& combinacionInicial) : Cerrojo(combinacionInicial) {}

    // El director puede abrir el negocio sin ingresar combinación (acceso verde)
    bool abrir(const vector<int>& intento) override {
        cout << "Director tiene acceso verde. Cerrojo abierto sin combinación." << endl;
        return true;
    }

    bool cambiarCombinacion(const vector<int>& combinacionActual, const vector<int>& nuevaCombinacion) override {
        bool exito = Cerrojo::cambiarCombinacion(combinacionActual, nuevaCombinacion);
        if (exito) {
            notificarCambio(nuevaCombinacion, "Director");
        }
        return exito;
    }
};

// Clase Gerencia, también con acceso completo (verde)
class Gerencia : public Cerrojo {
public:
    Gerencia(const vector<int>& combinacionInicial) : Cerrojo(combinacionInicial) {}

    // El gerente puede abrir el negocio sin ingresar combinación (acceso verde)
    bool abrir(const vector<int>& intento) override {
        cout << "Gerente tiene acceso verde. Cerrojo abierto sin combinación." << endl;
        return true;
    }

    bool cambiarCombinacion(const vector<int>& combinacionActual, const vector<int>& nuevaCombinacion) override {
        bool exito = Cerrojo::cambiarCombinacion(combinacionActual, nuevaCombinacion);
        if (exito) {
            notificarCambio(nuevaCombinacion, "Gerente");
        }
        return exito;
    }
};

// Clase Empleado, con acceso limitado (rojo)
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

// Clase para el negocio, manejando el estado de apertura
class Negocio {
private:
    map<int, Cerrojo*> empleados;
    bool abierto;
    int diaActual;

public:
    Negocio(map<int, Cerrojo*>& empleados) : empleados(empleados), abierto(false), diaActual(1) {}

    // Función para simular la apertura del negocio
    void abrirNegocio(int id) {
        auto it = empleados.find(id);
        if (it == empleados.end()) {
            cout << "Empleado no encontrado." << endl;
            return;
        }

        Cerrojo* empleado = it->second;
        
        // Solo los empleados deben ingresar combinación
        if (dynamic_cast<Empleado*>(empleado)) {
            vector<int> intento = ingresarCombinacion();
            if (empleado->abrir(intento)) {
                cout << "Negocio abierto." << endl;
                abierto = true;
            } else {
                cout << "No se pudo abrir el negocio." << endl;
            }
        } else {
            // Director o gerente tienen acceso verde, no necesitan ingresar combinación
            empleado->abrir({});
            abierto = true;
        }
    }

    // Función para cambiar la clave diaria
    void cambiarClaveDiaria() {
        if (!abierto) {
            cout << "El negocio está cerrado, no se puede cambiar la clave." << endl;
            return;
        }

        // Rotar la clave y asignarla al siguiente empleado
        int id;
        cout << "Ingrese su ID para cambiar la clave: ";
        cin >> id;

        auto it = empleados.find(id);
        if (it == empleados.end()) {
            cout << "Empleado no encontrado." << endl;
            return;
        }

        Cerrojo* empleado = it->second;
        cout << "Ingrese la nueva combinación: " << endl;
        vector<int> nuevaCombinacion = ingresarCombinacion();
        empleado->cambiarCombinacion(empleado->obtenerCombinacion(), nuevaCombinacion);
    }

    // Simular el paso de un día
    void siguienteDia() {
        diaActual++;
        cout << "Día " << diaActual << " ha comenzado. Recuerde cambiar la combinación." << endl;
        abierto = false;  // El negocio se cierra automáticamente al final del día
    }
};

// Menú interactivo
void menuInteractivo(Negocio& negocio) {
    int opcion, id;

    cout << "1. Abrir negocio\n2. Cambiar clave diaria\n3. Siguiente día\nElija una opción: ";
    cin >> opcion;

    switch (opcion) {
    case 1:
        cout << "Ingrese su ID de empleado: ";
        cin >> id;
        negocio.abrirNegocio(id);
        break;
    case 2:
        negocio.cambiarClaveDiaria();
        break;
    case 3:
        negocio.siguienteDia();
        break;
    default:
        cout << "Opción no válida." << endl;
    }
}

int main() {
    vector<int> combinacionInicial = {1, 2, 3};

    // Crear empleados, director y gerente
    Director director(combinacionInicial);
    Gerencia gerente(combinacionInicial);
    Empleado empleado1(combinacionInicial, &director, &gerente);
    Empleado empleado2(combinacionInicial, &director, &gerente);
    Empleado empleado3(combinacionInicial, &director, &gerente);
    Empleado empleado4(combinacionInicial, &director, &gerente);
    Empleado empleado5(combinacionInicial, &director, &gerente);
    Empleado empleado6(combinacionInicial, &director, &gerente);
    Empleado empleado7(combinacionInicial, &director, &gerente);
    Empleado empleado8(combinacionInicial, &director, &gerente);
    Empleado empleado9(combinacionInicial, &director, &gerente);
    Empleado empleado10(combinacionInicial, &director, &gerente);

    // Mapa de empleados
    map<int, Cerrojo*> empleados;
    empleados[0001] = &director;
    empleados[0002] = &gerente;
    empleados[1003] = &empleado1;
    empleados[1001] = &empleado2;
    empleados[1002] = &empleado2;
    empleados[1003] = &empleado2;
    empleados[1004] = &empleado2;
    empleados[1005] = &empleado2;
    empleados[1006] = &empleado2;
    empleados[1007] = &empleado2;
    empleados[1008] = &empleado2;
    empleados[1009] = &empleado2;
    empleados[1010] = &empleado2;


    // Crear el negocio
    Negocio negocio(empleados);

    while (true) {
        menuInteractivo(negocio);
        cout << endl;
    }

    return 0;
}