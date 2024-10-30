#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "SynonymList.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void updateSynonymList();
    void on_addButton_clicked();
    void on_removeButton_clicked();
    void on_modifyButton_clicked();  // Nueva ranura para modificar sinónimos
    void on_clearAllButton_clicked();  // Nueva ranura para eliminar toda la lista

private:
    Ui::MainWindow *ui;
    SynonymList synonymList;
};

#endif // MAINWINDOW_H
