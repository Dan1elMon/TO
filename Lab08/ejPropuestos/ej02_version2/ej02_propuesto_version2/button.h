#ifndef BUTTON_H
#define BUTTON_H

#include <iostream>

// Abstract Button Interface
class Button {
public:
    virtual ~Button() = default;
    virtual void draw() = 0;
};

// Concrete Button Implementations
class WinButton : public Button {
public:
    void draw() override {
        std::cout << "Dibujando Button Windows" << std::endl;
    }
};

class MacButton : public Button {
public:
    void draw() override {
        std::cout << "Dibujando Button Mac" << std::endl;
    }
};

#endif // BUTTON_H
