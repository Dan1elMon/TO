#ifndef ACCOUNTMANAGER_H
#define ACCOUNTMANAGER_H

#include <vector>
#include <string>
#include <map>
#include <memory>
#include <iostream>

struct Account {
    std::string type;
    std::string id;
    std::string owner;
    double balance;
};

class AccountManager {
private:
    std::vector<Account> accounts;
    AccountManager() {}

public:
    static AccountManager& getInstance() {
        static AccountManager instance;
        return instance;
    }

    void loadAccounts(const std::vector<std::string>& data);
    void showGlobalStatement();
    void showStatementByType();
    void makeTransfer();
    void payDebt();
    std::string generateReport();

    // Evitar copia del singleton
    AccountManager(const AccountManager&) = delete;
    void operator=(const AccountManager&) = delete;
};

#endif // ACCOUNTMANAGER_H
