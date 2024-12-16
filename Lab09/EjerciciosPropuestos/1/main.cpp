#include <iostream>
#include <memory>
#include <string>
#include "AccountManager.h"
#include "FileManager.h"

using namespace std;

// Función para autenticar al usuario mediante DNI y contraseña secreta de 4 dígitos
bool authenticateUser() {
    string dni;
    string password;

    // Solicitamos el DNI y la contraseña secreta
    cout << "Ingrese su DNI (sin guiones ni espacios): ";
    cin >> dni;
    
    // Verificamos que el DNI tenga un formato válido
    if (dni.length() != 8 || !isdigit(dni[0])) {
        cout << "DNI inválido. Asegúrese de ingresar un DNI correcto.\n";
        return false;
    }

    cout << "Ingrese su contraseña secreta (4 dígitos): ";
    cin >> password;

    // Verificamos que la contraseña tenga exactamente 4 dígitos
    if (password.length() != 4 || !isdigit(password[0])) {
        cout << "Contraseña secreta inválida. Asegúrese de ingresar una contraseña de 4 dígitos.\n";
        return false;
    }

    // Validamos el DNI y la contraseña secreta
    // Para este ejemplo, validamos con valores fijos (puedes mejorar esto con un sistema de base de datos)
    if (dni == "12345678" && password == "1234") {
        cout << "Autenticación exitosa.\n";
        return true;
    } else {
        cout << "Autenticación fallida. DNI o contraseña incorrectos.\n";
        return false;
    }
}

void showMenu() {
    cout << "===== MENÚ DE OPCIONES =====" << endl;
    cout << "1. Ver estado de cuenta global" << endl;
    cout << "2. Ver estado de cuenta por tipo" << endl;
    cout << "3. Realizar transferencia" << endl;
    cout << "4. Liquidar deudas" << endl;
    cout << "5. Generar reporte en archivo" << endl;
    cout << "0. Salir" << endl;
    cout << "Ingrese su opción: ";
}

int main() {
    auto& accountManager = AccountManager::getInstance();

    // Leer datos iniciales desde archivo
    vector<string> inputData = FileManager::readFile("entrada.txt");
    accountManager.loadAccounts(inputData);

    // Primero, autenticamos al usuario
    bool authenticated = false;
    while (!authenticated) {
        authenticated = authenticateUser();
    }

    // Si la autenticación es exitosa, mostramos el menú
    int option;
    do {
        showMenu();
        cin >> option;

        switch (option) {
        case 1:
            accountManager.showGlobalStatement();
            break;
        case 2:
            accountManager.showStatementByType();
            break;
        case 3:
            accountManager.makeTransfer();
            break;
        case 4:
            accountManager.payDebt();
            break;
        case 5:
            FileManager::writeFile("salida.txt", accountManager.generateReport());
            cout << "Reporte guardado en salida.txt" << endl;
            break;
        case 0:
            cout << "Saliendo..." << endl;
            break;
        default:
            cout << "Opción no válida." << endl;
        }
    } while (option != 0);

    return 0;
}
