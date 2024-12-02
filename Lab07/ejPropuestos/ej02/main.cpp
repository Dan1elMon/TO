#include <iostream>
#include <vector>
#include <memory>
#include <functional>
#include <map>
#include <ctime>
#include <sstream>
#include <algorithm>  // Para usar find

using namespace std;

// Clase base Cuenta
class Cuenta {
public:
    string titular;
    double saldo;
    string tipoCuenta;

    Cuenta(string titular, string tipoCuenta, double saldo = 0.0)
        : titular(titular), tipoCuenta(tipoCuenta), saldo(saldo) {}

    virtual double calcularInteres() const = 0;  // Método virtual puro

    virtual void estadoDeCuenta() const {
        cout << "Tipo de Cuenta: " << tipoCuenta << "\nTitular: " << titular << "\nSaldo: " << saldo << endl;
    }

    virtual ~Cuenta() {}
};

// Cuentas derivadas

class CuentaAhorro : public Cuenta {
public:
    CuentaAhorro(string titular, double saldo)
        : Cuenta(titular, "Ahorro", saldo) {}

    double calcularInteres() const override {
        return saldo * 0.0045;  // 0.45% para cuentas de ahorro
    }
};

class CuentaJoven : public Cuenta {
public:
    CuentaJoven(string titular, double saldo)
        : Cuenta(titular, "Joven", saldo) {}

    double calcularInteres() const override {
        return saldo * 0.01;  // 1% para cuentas Joven
    }
};

class CuentaPluss : public Cuenta {
public:
    CuentaPluss(string titular, double saldo)
        : Cuenta(titular, "Pluss", saldo) {}

    double calcularInteres() const override {
        return saldo * 0.015;  // 1.5% para cuentas Pluss
    }
};

class CuentaEmpresarial : public Cuenta {
public:
    CuentaEmpresarial(string titular, double saldo)
        : Cuenta(titular, "Empresarial", saldo) {}

    double calcularInteres() const override {
        return saldo * 0.02;  // 2% para cuentas Empresariales
    }
};

class TarjetaCredito : public Cuenta {
public:
    TarjetaCredito(string titular, double saldo)
        : Cuenta(titular, "Tarjeta de Crédito", saldo) {}

    double calcularInteres() const override {
        return saldo * 0.20;  // 20% para tarjetas de crédito
    }

    void realizarCompra(double monto) {
        saldo -= monto;  // Restamos el monto de la compra
    }
};

// Clase para representar un préstamo personal
class Prestamo {
public:
    double monto;
    double tasaInteres;
    bool aprobado;
    string mensajeAprobacion;

    Prestamo(double monto, double tasaInteres)
        : monto(monto), tasaInteres(tasaInteres), aprobado(false) {}

    void evaluarPrestamo(function<bool(double)> calificacion) {
        aprobado = calificacion(monto);
        if (aprobado) {
            mensajeAprobacion = "Préstamo aprobado por " + to_string(tasaInteres) + "% de interés.";
        } else {
            mensajeAprobacion = "Préstamo rechazado debido a las condiciones del cliente.";
        }
    }

    double calcularInteres() const {
        return monto * tasaInteres;
    }

    void mostrarMensaje() const {
        cout << mensajeAprobacion << endl;
    }
};

// Enumeración para tipo de firma en cuentas mancomunadas
enum TipoFirma {
    FIRMA_SIMPLE, // Cualquiera puede operar la cuenta
    FIRMA_CONJUNTA // Todos deben autorizar
};

// Clase CuentaMancomunada con flexibilidad en el tipo de firma
class CuentaMancomunada : public Cuenta {
public:
    vector<string> titulares;
    TipoFirma tipoFirma;

    CuentaMancomunada(vector<string> titulares, TipoFirma tipoFirma, double saldo = 0.0)
        : Cuenta("Cuenta Mancomunada", "Mancomunada", saldo), titulares(titulares), tipoFirma(tipoFirma) {}

    void agregarTitular(const string& titular) {
        titulares.push_back(titular);
    }

    void quitarTitular(const string& titular) {
        auto it = find(titulares.begin(), titulares.end(), titular);
        if (it != titulares.end()) {
            titulares.erase(it);
        } else {
            cout << "Titular no encontrado.\n";
        }
    }

    void estadoDeCuenta() const override {
        cout << "Cuenta Mancomunada\nTitulares: ";
        for (const auto& titular : titulares) {
            cout << titular << " ";
        }
        cout << "\nSaldo: " << saldo << "\nTipo de Firma: ";
        if (tipoFirma == FIRMA_SIMPLE) {
            cout << "Firma Simple\n";
        } else {
            cout << "Firma Conjunta\n";
        }
    }

    double calcularInteres() const override {
        return saldo * 0.01;  // 1% de interés para cuentas mancomunadas
    }
};

// Función para calcular transferencia
double calcularTarifaTransferencia(const string& moneda, double monto) {
    if (moneda == "S/") {
        return monto * 0.02;  // Tarifa para soles: 2%
    } else if (moneda == "$") {
        return monto * 0.30;  // Tarifa para dolares: 0.3%
    }
    return 0.0;
}

// Clase Cliente
class Cliente {
public:
    string nombre;
    string dni;
    string claveSecreta;
    double puntajeCredito;
    double deudaExistente;
    double ingresosMensuales;
    int anosDeTrabajo;
    map<string, bool> historialPrestamos;  // True = pagado a tiempo, False = no pagado a tiempo
    vector<shared_ptr<Cuenta>> cuentas;

    Cliente(string nombre, string dni, string claveSecreta, double puntajeCredito, double deudaExistente = 0.0, double ingresosMensuales = 0.0, int anosDeTrabajo = 0)
        : nombre(nombre), dni(dni), claveSecreta(claveSecreta), puntajeCredito(puntajeCredito), deudaExistente(deudaExistente), ingresosMensuales(ingresosMensuales), anosDeTrabajo(anosDeTrabajo) {}

    void agregarCuenta(shared_ptr<Cuenta> cuenta) {
        cuentas.push_back(cuenta);
    }

    void mostrarEstadoCuenta() {
        for (auto& cuenta : cuentas) {
            cuenta->estadoDeCuenta();
        }
    }

    void mostrarEstadoDeCuentaConCorte(const string& fechaCorte, const string& tipoCuenta = "") {
        cout << "Estado de cuenta a la fecha de corte: " << fechaCorte << endl;
        for (auto& cuenta : cuentas) {
            if (tipoCuenta.empty() || cuenta->tipoCuenta == tipoCuenta) {
                cuenta->estadoDeCuenta();
            }
        }
    }

    double calcularTotalIntereses() {
        double totalIntereses = 0;
        for (auto& cuenta : cuentas) {
            totalIntereses += cuenta->calcularInteres();
        }
        return totalIntereses;
    }

    bool calificarPrestamo(double monto) {
        double tasaBase = 0.10;  // Tasa base de 10% para préstamos
        string mensaje;

        // Evaluación por puntaje de crédito
        if (puntajeCredito > 750) {
            tasaBase -= 0.02;  // Descuento de 2% para buen crédito
        } else if (puntajeCredito < 600) {
            tasaBase += 0.05;  // Aumento de 5% para mal crédito
            mensaje += "Puntaje de crédito bajo, tasa de interés aumentada. ";
        }

        // Evaluación por deuda existente
        if (deudaExistente > 5000) {
            tasaBase += 0.03;  // Aumento de 3% si se tiene mucha deuda existente
            mensaje += "Deuda existente alta, tasa de interés aumentada. ";
        }

        // Evaluación por ingresos mensuales
        if (ingresosMensuales < 2000) {
            tasaBase += 0.02;  // Aumento de 2% si los ingresos son bajos
            mensaje += "Ingresos bajos, tasa de interés aumentada. ";
        }

        // Evaluación por años de trabajo
        if (anosDeTrabajo < 2) {
            tasaBase += 0.01;  // Aumento de 1% si los años de trabajo son bajos
            mensaje += "Poco tiempo de trabajo, tasa de interés aumentada. ";
        }

        Prestamo prestamo(monto, tasaBase);
        prestamo.evaluarPrestamo([&](double monto) -> bool {
            return monto <= 5000 && puntajeCredito > 600;
        });

        prestamo.mostrarMensaje();
        return prestamo.aprobado;
    }
};

// Función para verificar login
Cliente* login(vector<Cliente>& clientes) {
    string dni, clave;
    cout << "Ingrese DNI: ";
    cin >> dni;
    cout << "Ingrese clave secreta: ";
    cin >> clave;

    for (auto& cliente : clientes) {
        if (cliente.dni == dni && cliente.claveSecreta == clave) {
            return &cliente;
        }
    }
    cout << "DNI o clave incorrectos.\n";
    return nullptr;
}

// Función para mostrar el menú
void mostrarMenu() {
    cout << "\n1. Ver estado de cuenta\n";
    cout << "2. Crear nueva cuenta\n";
    cout << "3. Solicitar tarjeta de credito\n";
    cout << "4. Solicitar préstamo\n";
    cout << "5. Hacer transferencia\n";
    cout << "6. Liquidar deuda\n";
    cout << "7. Salir\n";
}

int main() {
    // Crear clientes por defecto
    vector<Cliente> clientes = {
        Cliente("Juan Perez", "12345678", "clave", 800, 3000, 6000, 3),
        Cliente("Maria Lopez", "12312311", "clave", 650, 5000, 2000, 2),
        Cliente("Carlos Gomez", "87654321", "clave", 700, 1000, 5000, 5)
    };

    // Login
    Cliente* clienteActual = login(clientes);
    if (clienteActual == nullptr) {
        cout << "Error de autenticación. Saliendo...\n";
        return 0;
    }

    cout << "¡Bienvenido " << clienteActual->nombre << "!\n";

    bool salir = false;
    while (!salir) {
        mostrarMenu();
        int opcion;
        cout << "Seleccione una opción: ";
        cin >> opcion;

        switch (opcion) {
            case 1: {
                string fechaCorte;
                cout << "Ingrese fecha de corte (YYYY-MM-DD): ";
                cin >> fechaCorte;
                clienteActual->mostrarEstadoDeCuentaConCorte(fechaCorte);
                break;
            }
            case 2: {
                string tipoCuenta;
                cout << "Ingrese tipo de cuenta (ahorro/joven/pluss/empresarial): ";
                cin >> tipoCuenta;

                shared_ptr<Cuenta> nuevaCuenta;
                if (tipoCuenta == "ahorro") {
                    nuevaCuenta = make_shared<CuentaAhorro>(clienteActual->nombre, 0.0);
                } else if (tipoCuenta == "joven") {
                    nuevaCuenta = make_shared<CuentaJoven>(clienteActual->nombre, 0.0);
                } else if (tipoCuenta == "pluss") {
                    nuevaCuenta = make_shared<CuentaPluss>(clienteActual->nombre, 0.0);
                } else if (tipoCuenta == "empresarial") {
                    nuevaCuenta = make_shared<CuentaEmpresarial>(clienteActual->nombre, 0.0);
                } else {
                    cout << "Tipo de cuenta no válido.\n";
                    break;
                }

                clienteActual->agregarCuenta(nuevaCuenta);
                cout << "Cuenta de tipo " << tipoCuenta << " creada exitosamente.\n";
                break;
            }
            case 3: {
                double saldo;
                cout << "Ingrese el saldo para la tarjeta de crédito: ";
                cin >> saldo;

                shared_ptr<TarjetaCredito> nuevaTarjeta = make_shared<TarjetaCredito>(clienteActual->nombre, saldo);
                clienteActual->agregarCuenta(nuevaTarjeta);
                cout << "Tarjeta de crédito solicitada con saldo de " << saldo << endl;
                break;
            }
            case 4: {
                double monto;
                cout << "Ingrese el monto del préstamo: ";
                cin >> monto;

                if (clienteActual->calificarPrestamo(monto)) {
                    cout << "Préstamo aprobado.\n";
                } else {
                    cout << "Préstamo rechazado.\n";
                }
                break;
            }
            case 5: {
                string dniDestinatario;
                cout << "Ingrese el DNI del destinatario: ";
                cin >> dniDestinatario;

                Cliente* destinatario = nullptr;
                for (auto& cliente : clientes) {
                    if (cliente.dni == dniDestinatario) {
                        destinatario = &cliente;
                        break;
                    }
                }

                if (!destinatario) {
                    cout << "Destinatario no encontrado.\n";
                    break;
                }

                double monto;
                cout << "Ingrese monto de la transferencia: ";
                cin >> monto;

                double tarifa = calcularTarifaTransferencia("S/", monto);  // Asumimos S/ como moneda por defecto
                cout << "Tarifa de transferencia: " << tarifa << endl;

                // Realizamos la transferencia
                // Verificamos las cuentas de cada cliente y actualizamos los saldos
                bool transferido = false;
                for (auto& cuenta : clienteActual->cuentas) {
                    if (cuenta->saldo >= monto + tarifa) {
                        cuenta->saldo -= monto + tarifa; // Se deduce del saldo
                        transferido = true;
                        break;
                    }
                }

                if (transferido) {
                    for (auto& cuenta : destinatario->cuentas) {
                        cuenta->saldo += monto;  // Se agrega al saldo del destinatario
                    }
                    cout << "Transferencia realizada con éxito.\n";
                } else {
                    cout << "Saldo insuficiente.\n";
                }
                break;
            }
            case 6: {
                double monto;
                cout << "Ingrese monto a liquidar o adelantar deuda: ";
                cin >> monto;

                bool liquidado = false;
                for (auto& cuenta : clienteActual->cuentas) {
                    if (cuenta->saldo >= monto) {
                        cuenta->saldo -= monto;
                        liquidado = true;
                        break;
                    }
                }

                if (liquidado) {
                    cout << "Deuda liquidada o adelantada con éxito.\n";
                } else {
                    cout << "Saldo insuficiente para liquidar deuda.\n";
                }
                break;
            }
            case 7: {
                salir = true;
                cout << "¡Hasta luego!\n";
                break;
            }
            default:
                cout << "Opción inválida.\n";
                break;
        }
    }

    return 0;
}
