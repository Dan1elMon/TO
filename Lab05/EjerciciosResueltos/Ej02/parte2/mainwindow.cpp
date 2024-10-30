#include "MainWindow.h"
#include "ui_MainWindow.h"
#include <QMessageBox>
#include <QListWidgetItem>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    synonymList("rápido")  // Palabra inicial para los sinónimos
{
    ui->setupUi(this);

    // Conexión de botones
    connect(ui->addButton, &QPushButton::clicked, this, &MainWindow::on_addButton_clicked);
    connect(ui->removeButton, &QPushButton::clicked, this, &MainWindow::on_removeButton_clicked);
    connect(ui->modifyButton, &QPushButton::clicked, this, &MainWindow::on_modifyButton_clicked);
    connect(ui->clearAllButton, &QPushButton::clicked, this, &MainWindow::on_clearAllButton_clicked);  // Conectar el botón de eliminar toda la lista

    updateSynonymList();  // Muestra sinónimos iniciales
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::updateSynonymList() {
    ui->synonymListWidget->clear();  // Limpia la lista actual
    for (const QString &synonym : synonymList.getSynonyms()) {
        ui->synonymListWidget->addItem(synonym);  // Agrega cada sinónimo al QListWidget
    }
}

void MainWindow::on_addButton_clicked() {
    QString newSynonym = ui->synonymInput->text().trimmed();
    if (!newSynonym.isEmpty()) {
        synonymList.addSynonym(newSynonym);  // Agrega el sinónimo al QVector
        ui->synonymInput->clear();           // Limpia el campo de entrada
        updateSynonymList();                 // Actualiza la lista en pantalla
    }
}

void MainWindow::on_removeButton_clicked() {
    QListWidgetItem *selectedItem = ui->synonymListWidget->currentItem();
    if (selectedItem) {
        QString synonym = selectedItem->text();
        synonymList.removeSynonym(synonym);
        updateSynonymList();
    } else {
        QMessageBox::warning(this, "Error", "Seleccione un sinónimo para eliminar.");
    }
}

void MainWindow::on_modifyButton_clicked() {
    QListWidgetItem *selectedItem = ui->synonymListWidget->currentItem();
    QString newSynonym = ui->synonymInput->text().trimmed();

    if (selectedItem && !newSynonym.isEmpty()) {
        QString oldSynonym = selectedItem->text();
        synonymList.removeSynonym(oldSynonym);   // Elimina el sinónimo antiguo
        synonymList.addSynonym(newSynonym);      // Agrega el nuevo sinónimo
        ui->synonymInput->clear();               // Limpia el campo de entrada
        updateSynonymList();                     // Actualiza la lista en pantalla
    } else {
        QMessageBox::warning(this, "Error", "Seleccione un sinónimo y escriba el nuevo nombre.");
    }
}

void MainWindow::on_clearAllButton_clicked() {
    synonymList.clearAll();  // Elimina todos los sinónimos en la lista
    updateSynonymList();     // Refresca la lista en pantalla
}
