#include "mainwindow.h"
#include "qboxlayout.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Crear la lista de carreras
    careerListWidget = new QListWidget(this);
    QStringList careers = {"Ciencia de la Computación", "Ingeniería de Software", "Sistemas de Información", "Tecnología de la Información", "Ingeniería en Computación"};
    careerListWidget->addItems(careers);
    connect(careerListWidget, &QListWidget::itemClicked, this, &MainWindow::showCareerDetails);

    // Crear el label para mostrar los detalles de la carrera
    careerDetailsLabel = new QLabel("Detalles de la carrera", this); // Elimina la redeclaración

    // Configurar el layout
    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(careerListWidget);
    layout->addWidget(careerDetailsLabel);
    ui->centralwidget->setLayout(layout);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::showCareerDetails(QListWidgetItem *item)
{
    QString career = item->text();
    QString details;

    if (career == "Ciencia de la Computación") {
        details = "Programa: Ciencia de la Computación\nEnfocado en teoría de computación y algoritmos.";
    } else if (career == "Ingeniería de Software") {
        details = "Programa: Ingeniería de Software\nEnfocado en diseño y desarrollo de software.";
    } else if (career == "Sistemas de Información") {
        details = "Programa: Sistemas de Información\nEnfocado en gestión de sistemas de información.";
    } else if (career == "Tecnología de la Información") {
        details = "Programa: Tecnología de la Información\nEnfocado en infraestructura tecnológica.";
    } else if (career == "Ingeniería en Computación") {
        details = "Programa: Ingeniería en Computación\nEnfocado en hardware y software de sistemas.";
    }

    careerDetailsLabel->setText(details);
}
