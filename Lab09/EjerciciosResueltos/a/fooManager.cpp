#include "FooManager.h"

// Inicializar el puntero estático
FooManager* FooManager::m_Inst = nullptr;

FooManager::FooManager() : SampleData(100) {
    // Constructor privado
}

FooManager::~FooManager() {
    // Destructor
}
