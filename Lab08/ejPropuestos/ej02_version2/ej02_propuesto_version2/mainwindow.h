#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QObject>

class MainWindow : public QObject {
    Q_OBJECT
public:
    explicit MainWindow(QObject* parent = nullptr);
    void run(); // Método para ejecutar la lógica
};

#endif // MAINWINDOW_H
