#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QListWidget>
#include <QLabel>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void showCareerDetails(QListWidgetItem *item);

private:
    Ui::MainWindow *ui;
    QListWidget *careerListWidget;
    QLabel *careerDetailsLabel;
};

#endif // MAINWINDOW_H
