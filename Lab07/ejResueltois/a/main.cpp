#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;

// Clase base para  los iutems de una laptop
class Item {
public:
    virtual string GetName() const { return ""; }
    virtual float GetPrice() const { return 0.0f; }
    virtual void GetConfiguration() const {}
    virtual ~Item() = default;
};

// Clases específicas para Itemes
class Processor : public Item {
public:
    string GetName() const override { return "Processor"; }
};

class IntelCoreI5 : public Processor {
public:
    float GetPrice() const override { return 3000.00f; }
    void GetConfiguration() const override {
        cout << "Intel Core i5, 1.5 GHz, up to 2.0 GHz, 2 cores, 4 threads, 8MB cache" << endl;
    }
};

class IntelCoreI7 : public Processor {
public:
    float GetPrice() const override { return 4700.00f; }
    void GetConfiguration() const override {
        cout << "Intel Core i7, 1.6 GHz, up to 1.99 GHz, 4 cores, 8 threads, 16MB cache" << endl;
    }
};

class Memory : public Item {
public:
    string GetName() const override { return "Memory"; }
};

class RAM8GB : public Memory {
public:
    float GetPrice() const override { return 800.00f; }
    void GetConfiguration() const override {
        cout << "8GB DDR4, 2400 MHz" << endl;
    }
};

class RAM16GB : public Memory {
public:
    float GetPrice() const override { return 1500.00f; }
    void GetConfiguration() const override {
        cout << "16GB DDR4, 3200 MHz" << endl;
    }
};

class Drive : public Item {
public:
    string GetName() const override { return "Storage Drive"; }
};

class HDD1TB : public Drive {
public:
    float GetPrice() const override { return 1500.00f; }
    void GetConfiguration() const override {
        cout << "1TB HDD, 5400 RPM" << endl;
    }
};

class SSD512GB : public Drive {
public:
    float GetPrice() const override { return 3000.00f; }
    void GetConfiguration() const override {
        cout << "512GB SSD, NVMe, 1800 MB/s" << endl;
    }
};

class Monitor : public Item {
public:
    string GetName() const override { return "Monitor"; }
};

class FHDMonitor : public Monitor {
public:
    float GetPrice() const override { return 2500.00f; }
    void GetConfiguration() const override {
        cout << "15.6´´ Full HD, 1920x1080 resolution" << endl;
    }
};

class UHDMonitor : public Monitor {
public:
    float GetPrice() const override { return 4000.00f; }
    void GetConfiguration() const override {
        cout << "15.6´´ Ultra HD, 3840x2160 resolution" << endl;
    }
};

// Clase para la Laptop que almacena los items
class Laptop {
public:
    void AddItem(Item* Item) { Items.push_back(Item); }
    float GetTotalCost() const {
        float total = 0.0f;
        for (auto Item : Items) {
            total += Item->GetPrice();
        }
        return total;
    }
    void ShowConfiguration() const {
        cout << "Laptop Configuration:\n";
        for (auto Item : Items) {
            cout << "- " << Item->GetName() << ": ";
            Item->GetConfiguration();
        }
    }
    ~Laptop() {
        for (auto Item : Items) {
            delete Item;
        }
    }

private:
    vector<Item*> Items;
};

// Clase builder 
class LaptopBuilder {
public:
    Laptop* BuildBasicLaptop() {
        Laptop* laptop = new Laptop();
        laptop->AddItem(new IntelCoreI5());
        laptop->AddItem(new RAM8GB());
        laptop->AddItem(new HDD1TB());
        laptop->AddItem(new FHDMonitor());
        return laptop;
    }

    Laptop* BuildHighEndLaptop() {
        Laptop* laptop = new Laptop();
        laptop->AddItem(new IntelCoreI7());
        laptop->AddItem(new RAM16GB());
        laptop->AddItem(new SSD512GB());
        laptop->AddItem(new UHDMonitor());
        return laptop;
    }
};

int main() {
    LaptopBuilder builder;

    // Construir una laptop basica
    cout << "Basic Laptop:\n";
    Laptop* basicLaptop = builder.BuildBasicLaptop();
    basicLaptop->ShowConfiguration();
    cout << "Total Cost: $" << fixed << setprecision(2) << basicLaptop->GetTotalCost() << "\n\n";
    delete basicLaptop;

    // Construir una laptop de gama alta
    cout << "High-End Laptop:\n";
    Laptop* highEndLaptop = builder.BuildHighEndLaptop();
    highEndLaptop->ShowConfiguration();
    cout << "Total Cost: $" << fixed << setprecision(2) << highEndLaptop->GetTotalCost() << "\n";
    delete highEndLaptop;

    return 0;
}
