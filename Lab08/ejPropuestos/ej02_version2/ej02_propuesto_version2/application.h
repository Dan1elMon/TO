#ifndef APPLICATION_H
#define APPLICATION_H

#include "guifactory.h"

class Application {
public:
    Application(GUIFactory& factory, int os) {
        Button* button = factory.createButton();
        std::cout << "Cliente: ";
        if (os == 1) {
            std::cout << "Windows" << std::endl;
        } else {
            std::cout << "Mac" << std::endl;
        }
        button->draw();
        delete button;
    }
};

#endif // APPLICATION_H
