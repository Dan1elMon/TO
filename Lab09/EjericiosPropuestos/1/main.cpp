#include <iostream>
#include <memory>
#include "AccountManager.h"
#include "FileManager.h"

using namespace std;

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
    vector<string> inputData = FileManager::readFile("datos.txt");
    accountManager.loadAccounts(inputData);

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
            FileManager::writeFile("datos2.txt", accountManager.generateReport());
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
