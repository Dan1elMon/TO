#include "mainwindow.h"
#include <QApplication>
#include <QDebug>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>

bool keepRunning = true;  // Definimos una variable para controlar el bucle

void* procesoHilo(void *dato){
    struct timespec tm = {1, 0};
    while (keepRunning) {
        qDebug() << "proceso";
        nanosleep(&tm, NULL);
    }
    return nullptr;
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    pthread_t proceso1;
    pthread_t proceso2;
    pthread_create(&proceso1, NULL, procesoHilo, NULL);
    pthread_create(&proceso2, NULL, procesoHilo, NULL);

    // Aquí esperamos a que los hilos terminen
    pthread_join(proceso1, NULL);
    pthread_join(proceso2, NULL);

    return a.exec();
}
