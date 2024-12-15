#include "AccountManager.h"
#include <sstream>
#include <iomanip>

void AccountManager::loadAccounts(const std::vector<std::string>& data) {
    for (const auto& line : data) {
        std::istringstream ss(line);
        Account account;
        char delimiter = ',';

        std::getline(ss, account.type, delimiter);
        std::getline(ss, account.id, delimiter);
        std::getline(ss, account.owner, delimiter);
        ss >> account.balance;

        accounts.push_back(account);
        std::cout << "Cargando cuenta: " << account.type << " - " << account.id 
                  << " - " << account.owner << " - " << account.balance << std::endl;
    }
}

void AccountManager::showGlobalStatement() {
    std::cout << "===== Estado de Cuenta Global =====" << std::endl;
    for (const auto& account : accounts) {
        std::cout << "ID: " << account.id << ", Propietario: " << account.owner
                  << ", Tipo: " << account.type << ", Balance: $" << std::fixed 
                  << std::setprecision(2) << account.balance << std::endl;
    }
}

void AccountManager::showStatementByType() {
    std::cout << "Ingrese el tipo de cuenta a consultar: ";
    std::string type;
    std::cin >> type;

    std::cout << "===== Estado de Cuenta para Tipo: " << type << " =====" << std::endl;
    for (const auto& account : accounts) {
        if (account.type == type) {
            std::cout << "ID: " << account.id << ", Propietario: " << account.owner
                      << ", Balance: $" << std::fixed << std::setprecision(2) 
                      << account.balance << std::endl;
        }
    }
}

void AccountManager::makeTransfer() {
    std::string fromId, toId;
    double amount;

    std::cout << "Ingrese el ID de la cuenta origen: ";
    std::cin >> fromId;
    std::cout << "Ingrese el ID de la cuenta destino: ";
    std::cin >> toId;
    std::cout << "Ingrese el monto a transferir: ";
    std::cin >> amount;

    Account* fromAccount = nullptr;
    Account* toAccount = nullptr;

    for (auto& account : accounts) {
        if (account.id == fromId) fromAccount = &account;
        if (account.id == toId) toAccount = &account;
    }

    if (fromAccount && toAccount && fromAccount->balance >= amount) {
        fromAccount->balance -= amount;
        toAccount->balance += amount;
        std::cout << "Transferencia realizada con éxito!" << std::endl;
    } else {
        std::cout << "Error en la transferencia. Verifique los datos." << std::endl;
    }
}

void AccountManager::payDebt() {
    std::string id;
    double amount;

    std::cout << "Ingrese el ID de la cuenta para liquidar deuda: ";
    std::cin >> id;
    std::cout << "Ingrese el monto a liquidar: ";
    std::cin >> amount;

    for (auto& account : accounts) {
        if (account.id == id) {
            account.balance -= amount;
            std::cout << "Deuda liquidada con éxito. Nuevo balance: $" 
                      << account.balance << std::endl;
            return;
        }
    }
    std::cout << "Cuenta no encontrada." << std::endl;
}

std::string AccountManager::generateReport() {
    std::ostringstream report;
    report << "===== Reporte de Cuentas =====" << std::endl;
    for (const auto& account : accounts) {
        report << "ID: " << account.id << ", Propietario: " << account.owner
               << ", Tipo: " << account.type << ", Balance: $" << std::fixed 
               << std::setprecision(2) << account.balance << std::endl;
    }
    return report.str();
}
