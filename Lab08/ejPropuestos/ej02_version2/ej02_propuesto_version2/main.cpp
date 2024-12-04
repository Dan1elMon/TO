#include <QCoreApplication>
#include "mainwindow.h"

int main(int argc, char *argv[]) {
    QCoreApplication a(argc, argv);

    MainWindow mainWindow;
    mainWindow.run(); // Ejecutar la lógica principal

    return a.exec();
}
