#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <QListWidgetItem>

namespace Ui {
class CarreraWindow;
}

class CarreraWindow : public QWidget
{
    Q_OBJECT

public:
    explicit CarreraWindow(QWidget *parent = nullptr);
    ~CarreraWindow();

private slots:
    void mostrarCarrera(QListWidgetItem *item);

private:
    Ui::CarreraWindow *ui;
};

#endif // MAINWINDOW_H
