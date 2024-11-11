#include "mainwindow.h"

#include <QApplication>
#include <thread>
//#include <sstream>
#include <chrono>
#include <ctime>
#include <cstdlib>

void ExecuteThread(int id){
    auto nowTime = std::chrono::system_clock::now();
    std::time_t sleepTime = std::chrono::system_clock::to_time_t(nowTime);

    // Calcular la zona horaria local
    tm myLocalTime = *localtime(&sleepTime);

    qDebug() << "Thread: " << id << " sleep Time: " << std::ctime(&sleepTime);
    qDebug() << "Month: " << (myLocalTime.tm_mon + 1);
    qDebug() << "Day: " << myLocalTime.tm_mday;
    qDebug() << "Year: " << (myLocalTime.tm_year + 1900);
    qDebug() << "Hours: " << myLocalTime.tm_hour;
    qDebug() << "Minutes: " << myLocalTime.tm_min;
    qDebug() << "Seconds: " << myLocalTime.tm_sec;

    // 3 segundos de espera antes de imprimir en consola
    std::this_thread::sleep_for(std::chrono::seconds(rand() % 3 + 1));

    nowTime = std::chrono::system_clock::now();
    sleepTime = std::chrono::system_clock::to_time_t(nowTime);
    qDebug() << "Thread: " << id << " Awake Time: " << std::ctime(&sleepTime) << "\n";
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    std::thread th1(ExecuteThread, 1);
    th1.join();
    std::thread th2(ExecuteThread, 2);
    th2.join();

    return a.exec();
}
