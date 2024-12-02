#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;

// Clase base para los items de una laptop
class Item {
public:
    virtual string GetName() const { return ""; }
    virtual float GetPrice() const { return 0.0f; }
    virtual void GetConfiguration() const {}
    virtual ~Item() = default;
};

// Clases específicas para items

// Procesadores
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

// Memoria RAM
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

// Almacenamiento
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

// Monitor
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

// Tarjeta Gráfica
class GraphicsCard : public Item {
public:
    string GetName() const override { return "Graphics Card"; }
};

class GTX1650 : public GraphicsCard {
public:
    float GetPrice() const override { return 2000.00f; }
    void GetConfiguration() const override {
        cout << "NVIDIA GeForce GTX 1650, 4GB GDDR6" << endl;
    }
};

class RTX3060 : public GraphicsCard {
public:
    float GetPrice() const override { return 4500.00f; }
    void GetConfiguration() const override {
        cout << "NVIDIA GeForce RTX 3060, 6GB GDDR6" << endl;
    }
};

// Teclado
class Keyboard : public Item {
public:
    string GetName() const override { return "Keyboard"; }
};

class MechanicalKeyboard : public Keyboard {
public:
    float GetPrice() const override { return 800.00f; }
    void GetConfiguration() const override {
        cout << "Mechanical Keyboard, RGB Lighting" << endl;
    }
};

// Ratón
class Mouse : public Item {
public:
    string GetName() const override { return "Mouse"; }
};

class WirelessMouse : public Mouse {
public:
    float GetPrice() const override { return 500.00f; }
    void GetConfiguration() const override {
        cout << "Wireless Mouse, 1600 DPI" << endl;
    }
};

// Otros periféricos
class Headphones : public Item {
public:
    string GetName() const override { return "Headphones"; }
};

class GamingHeadset : public Headphones {
public:
    float GetPrice() const override { return 1200.00f; }
    void GetConfiguration() const override {
        cout << "Gaming Headset, 7.1 Surround Sound" << endl;
    }
};

// Impresora
class Printer : public Item {
public:
    string GetName() const override { return "Printer"; }
};

class LaserPrinter : public Printer {
public:
    float GetPrice() const override { return 2500.00f; }
    void GetConfiguration() const override {
        cout << "Laser Printer, 20 ppm" << endl;
    }
};

// Clase Laptop
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

// clase Builder
class LaptopBuilder {
public:
    Laptop* BuildBasicLaptop() {
        Laptop* laptop = new Laptop();
        laptop->AddItem(new IntelCoreI5());
        laptop->AddItem(new RAM8GB());
        laptop->AddItem(new HDD1TB());
        laptop->AddItem(new FHDMonitor());
        laptop->AddItem(new GTX1650());
        laptop->AddItem(new WirelessMouse());
        return laptop;
    }

    Laptop* BuildHighEndLaptop() {
        Laptop* laptop = new Laptop();
        laptop->AddItem(new IntelCoreI7());
        laptop->AddItem(new RAM16GB());
        laptop->AddItem(new SSD512GB());
        laptop->AddItem(new UHDMonitor());
        laptop->AddItem(new RTX3060());
        laptop->AddItem(new MechanicalKeyboard());
        laptop->AddItem(new GamingHeadset());
        laptop->AddItem(new LaserPrinter());
        return laptop;
    }
};

int main() {
    LaptopBuilder builder;

    cout << "Basic Laptop:\n";
    Laptop* basicLaptop = builder.BuildBasicLaptop();
    basicLaptop->ShowConfiguration();
    cout << "Total Cost: $" << fixed << setprecision(2) << basicLaptop->GetTotalCost() << "\n\n";
    delete basicLaptop;

    cout << "High-End Laptop:\n";
    Laptop* highEndLaptop = builder.BuildHighEndLaptop();
    highEndLaptop->ShowConfiguration();
    cout << "Total Cost: $" << fixed << setprecision(2) << highEndLaptop->GetTotalCost() << "\n";
    delete highEndLaptop;

    return 0;
}
