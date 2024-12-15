#include <iostream>
#include "FooManager.h"
using namespace std;

int main() {
    cout << "Patron singleton" << endl;

    // crear la instancia 
    FooManager::Create();

    // Obtener la primera instancia
    FooManager* pMyFoo1 = FooManager::GetInst();
    if (pMyFoo1 != nullptr) {
        cout << "Primera instancia - Sample data: " << pMyFoo1->GetSampleData() << endl;
        cout << "Direccion de memoria: " << pMyFoo1 << endl;
    }

    // Obtener la misma instancia 
    FooManager* pMyFoo2 = FooManager::GetInst();
    if (pMyFoo2 != nullptr) {
        cout << "Segunda instancia? Sample data: " << pMyFoo2->GetSampleData() << endl;
        cout << "Direccion de memoria: " << pMyFoo2 << endl;
    }

    return 0;
}
