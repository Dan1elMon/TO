#include <iostream>
#include <chrono>
#include <thread>
#include <iomanip>
#include <atomic>

using namespace std;
atomic<bool> alarmSet(false);
atomic<bool> alarmTriggered(false);
tm alarmTime = {};

// Función para obtener la hora actual como string
string getCurrentTime() {
    auto now = chrono::system_clock::now();
    auto now_time = chrono::system_clock::to_time_t(now);
    tm *local_time = localtime(&now_time);

    stringstream ss;
    ss << put_time(local_time, "%H:%M:%S");
    return ss.str();
}

// Función que verifica si la hora actual coincide con la alarma
void checkAlarm() {
    if (alarmSet) {
        auto now = chrono::system_clock::now();
        auto now_time = chrono::system_clock::to_time_t(now);
        tm *local_time = localtime(&now_time);

        if (local_time->tm_hour == alarmTime.tm_hour &&
            local_time->tm_min == alarmTime.tm_min &&
            local_time->tm_sec == alarmTime.tm_sec) {
            cout << "\n¡La alarma ha sonado!" << endl;
            alarmSet = false;
            alarmTriggered = true;
        }
    }
}

// Hilo para mostrar la hora actual y verificar la alarma
void displayClock() {
    while (true) {
        system("clear");  // Para limpiar la pantalla en Linux/MacOS. Usa "cls" en Windows.
        cout << "Hora actual: " << getCurrentTime() << endl;

        // Verificar si la alarma debe sonar
        checkAlarm();

        if (alarmSet) {
            cout << "Alarma configurada para: " 
                 << setw(2) << setfill('0') << alarmTime.tm_hour << ":"
                 << setw(2) << setfill('0') << alarmTime.tm_min << ":"
                 << setw(2) << setfill('0') << alarmTime.tm_sec << endl;
        }

        // Espera de un segundo antes de actualizar la pantalla
        this_thread::sleep_for(chrono::seconds(1));
    }
}

// Función para configurar la alarma
void setAlarm() {
    cout << "Configura la hora de la alarma (HH MM SS): ";
    cin >> alarmTime.tm_hour >> alarmTime.tm_min >> alarmTime.tm_sec;
    alarmSet = true;
    alarmTriggered = false;
}

int main() {
    // Iniciar el hilo para mostrar la hora
    thread clockThread(displayClock);

    while (true) {
        cout << "\nMenu:\n";
        cout << "1. Configurar alarma\n";
        cout << "2. Salir\n";
        cout << "Elige una opción: ";
        int choice;
        cin >> choice;

        switch (choice) {
            case 1:
                setAlarm();
                break;
            case 2:
                cout << "Saliendo del programa..." << endl;
                clockThread.detach();  // Desvincular el hilo del reloj
                return 0;
            default:
                cout << "Opción no válida. Intente de nuevo." << endl;
        }
    }

    return 0;
}
