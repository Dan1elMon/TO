#include "mainwindow.h"
#include "application.h"
#include "guifactory.h"

MainWindow::MainWindow(QObject* parent) : QObject(parent) {}

void MainWindow::run() {
    int os = 1; // Cambiar a 2 para Mac
    GUIFactory* factory;

    // Determinar la fábrica en tiempo de ejecución
    if (os == 1) {
        factory = new WinFactory();
    } else {
        factory = new MacFactory();
    }

    Application app(*factory, os);

    delete factory;
}
