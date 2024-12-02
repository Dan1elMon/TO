#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Configurar el QTextEdit para mostrar la salida
    ui->outputTextEdit->setReadOnly(true);
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::on_runButton_clicked() {
    // Limpiar salida
    ui->outputTextEdit->clear();

    // Cliente: Windows
    WinFactory winFactory;
    Application winApp(winFactory, 1, ui->outputTextEdit);

    // Cliente: Mac
    MacFactory macFactory;
    Application macApp(macFactory, 2, ui->outputTextEdit);

    // Cliente: Linux
    LinuxFactory linuxFactory;
    Application linuxApp(linuxFactory, 3, ui->outputTextEdit);
}
