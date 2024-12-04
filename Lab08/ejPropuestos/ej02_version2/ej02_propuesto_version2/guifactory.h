#ifndef GUIFACTORY_H
#define GUIFACTORY_H

#include "button.h"

// Abstract Factory
class GUIFactory {
public:
    virtual ~GUIFactory() = default;
    virtual Button* createButton() = 0;
};

// Concrete Factory Implementations
class WinFactory : public GUIFactory {
public:
    Button* createButton() override {
        return new WinButton;
    }
};

class MacFactory : public GUIFactory {
public:
    Button* createButton() override {
        return new MacButton;
    }
};

#endif // GUIFACTORY_H
