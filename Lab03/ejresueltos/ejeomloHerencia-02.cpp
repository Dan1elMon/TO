#include <iostream>
#include <string>

using namespace std;

class Mamifero {
public:
    Mamifero() : edad(0) {
        cout << "Mamifero constructor...\n";
    }
    virtual ~Mamifero() {
        cout << "Mamifero destructor...\n";
    }
    virtual void Move() const {
        cout << "Mamifero moves!\n";
    }
protected:
    int edad;
};

class Dog : public Mamifero {
public:
    Dog() {
        cout << "Dog constructor...\n";
    }
    ~Dog() {
        cout << "Dog destructor...\n";
    }
    void WagTail() {
        cout << "Wagging Tail...\n";
    }
    void Speak() {
        cout << "Woof!\n";
    }
    void Move() const override {
        cout << "Dog moves 5 steps...\n";
    }
};

int main() {
    // crear un objeto Mamifero
    Mamifero mamifero;
    mamifero.Move();

    // crear un objeto Dog
    Dog perro;
    perro.Move();
    perro.WagTail();
    perro.Speak();

    return 0;
}
