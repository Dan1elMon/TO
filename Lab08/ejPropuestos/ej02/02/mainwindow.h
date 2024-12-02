#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTextEdit>
#include <QString>

using namespace std;

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

// Producto Abstracto: Button
class Button {
public:
    virtual QString Draw() const = 0;
    virtual ~Button() {}
};

// Producto Abstracto: CheckBox
class CheckBox {
public:
    virtual QString Draw() const = 0;
    virtual ~CheckBox() {}
};

// Producto Concreto: WinButton
class WinButton : public Button {
public:
    QString Draw() const override {
        return "Draw: WinButton\n";
    }
};

// Producto Concreto: MacButton
class MacButton : public Button {
public:
    QString Draw() const override {
        return "Draw: MacButton\n";
    }
};

// Producto Concreto: LinuxButton
class LinuxButton : public Button {
public:
    QString Draw() const override {
        return "Draw: LinuxButton\n";
    }
};

// Producto Concreto: WinCheckBox
class WinCheckBox : public CheckBox {
public:
    QString Draw() const override {
        return "Draw: WinCheckBox\n";
    }
};

// Producto Concreto: MacCheckBox
class MacCheckBox : public CheckBox {
public:
    QString Draw() const override {
        return "Draw: MacCheckBox\n";
    }
};

// Producto Concreto: LinuxCheckBox
class LinuxCheckBox : public CheckBox {
public:
    QString Draw() const override {
        return "Draw: LinuxCheckBox\n";
    }
};

// Fábrica Abstracta
class GUIFactory {
public:
    virtual Button* CreateButton() const = 0;
    virtual CheckBox* CreateCheckBox() const = 0;
    virtual ~GUIFactory() {}
};

// Fábrica Concreta: WinFactory
class WinFactory : public GUIFactory {
public:
    Button* CreateButton() const override {
        return new WinButton();
    }

    CheckBox* CreateCheckBox() const override {
        return new WinCheckBox();
    }
};

// Fábrica Concreta: MacFactory
class MacFactory : public GUIFactory {
public:
    Button* CreateButton() const override {
        return new MacButton();
    }

    CheckBox* CreateCheckBox() const override {
        return new MacCheckBox();
    }
};

// Fábrica Concreta: LinuxFactory
class LinuxFactory : public GUIFactory {
public:
    Button* CreateButton() const override {
        return new LinuxButton();
    }

    CheckBox* CreateCheckBox() const override {
        return new LinuxCheckBox();
    }
};

// Aplicación
class Application {
private:
    Button* button;
    CheckBox* checkbox;

public:
    Application(const GUIFactory& factory, int os, QTextEdit* output) {
        button = factory.CreateButton();
        checkbox = factory.CreateCheckBox();
        QString system = (os == 1) ? "Sistema: Windows\n" : (os == 2) ? "Sistema: Mac\n" : "Sistema: Linux\n";
        output->append(system + button->Draw() + checkbox->Draw());
    }

    ~Application() {
        delete button;
        delete checkbox;
    }
};

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

private slots:
    void on_runButton_clicked(); // Ejecutar la simulación
};

#endif // MAINWINDOW_H
