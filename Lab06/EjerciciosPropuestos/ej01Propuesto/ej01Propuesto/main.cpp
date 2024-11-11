#include <iostream>
#include <thread>
#include <mutex>
#include <random>
#include <chrono>

// Nodo de la lista enlazada
struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

// Lista enlazada simple con operaciones protegidas por mutex
class LinkedList {
private:
    Node* head;
    std::mutex listMutex;

public:
    LinkedList() : head(nullptr) {}

    // Inserta un nuevo nodo al inicio de la lista
    void insert(int value) {
        std::lock_guard<std::mutex> lock(listMutex);
        Node* newNode = new Node(value);
        newNode->next = head;
        head = newNode;
        std::cout << "Insertando: " << value << std::endl;
    }

    // Elimina el primer nodo que contenga el valor dado
    bool remove(int value) {
        std::lock_guard<std::mutex> lock(listMutex);
        Node* current = head;
        Node* prev = nullptr;

        while (current != nullptr) {
            if (current->data == value) {
                if (prev == nullptr) {
                    head = current->next;
                } else {
                    prev->next = current->next;
                }
                delete current;
                std::cout << "Eliminando: " << value << std::endl;
                return true;
            }
            prev = current;
            current = current->next;
        }
        std::cout << "No se elimino: " << value << std::endl;
        return false;
    }

    // Busca un valor en la lista
    bool search(int value) {
        std::lock_guard<std::mutex> lock(listMutex);
        Node* current = head;
        while (current != nullptr) {
            if (current->data == value) {
                std::cout << "Encontrado: " << value << std::endl;
                return true;
            }
            current = current->next;
        }
        std::cout << "No encontrado: " << value << std::endl;
        return false;
    }

    // Modifica un valor en la lista sumando una cantidad a un valor específico
    bool modify(int value, int increment) {
        std::lock_guard<std::mutex> lock(listMutex);
        Node* current = head;
        while (current != nullptr) {
            if (current->data == value) {
                int newValue = current->data + increment;
                std::cout << "Modificando " << value << " a " << newValue << std::endl;
                current->data = newValue;
                return true;
            }
            current = current->next;
        }
        std::cout << "No se encontro: " << value << std::endl;
        return false;
    }
};

// Funcion para generar números aleatorios
int getRandomNumber(int min, int max) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(min, max);
    return dist(gen);
}

// Thread 1: Eliminar valores aleatorios
void threadRemove(LinkedList& list) {
    for (int i = 0; i < 10; ++i) {
        int num = getRandomNumber(1, 100);
        list.remove(num);
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
}

// Thread 2: Insertar valores aleatorios
void threadInsert(LinkedList& list) {
    for (int i = 0; i < 10; ++i) {
        int num = getRandomNumber(1, 100);
        list.insert(num);
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
}

// Thread 3: Buscar valores aleatorios
void threadSearch(LinkedList& list) {
    for (int i = 0; i < 10; ++i) {
        int num = getRandomNumber(1, 100);
        list.search(num);
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
}

// Thread 4: Modificar valores aleatorios
void threadModify(LinkedList& list) {
    for (int i = 0; i < 10; ++i) {
        int num = getRandomNumber(1, 100);
        int increment = getRandomNumber(1, 10);
        list.modify(num, increment);
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
}

int main() {
    LinkedList list;

    // Crear y lanzar los threads
    //std::cout << "hilo 1"<< std::endl;
    std::thread t1(threadRemove, std::ref(list));

    //std::cout << "hilo 2"<< std::endl;
    std::thread t2(threadInsert, std::ref(list));

    //::cout << "hilo 3"<< std::endl;
    std::thread t3(threadSearch, std::ref(list));

    //std::cout << "hilo 4"<< std::endl;
    std::thread t4(threadModify, std::ref(list));


    // Esperar a que todos los threads terminen
    t1.join();
    t2.join();
    t3.join();
    t4.join();

    return 0;
}
