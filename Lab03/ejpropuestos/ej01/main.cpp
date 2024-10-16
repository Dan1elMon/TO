#include "Arquitecto.h"
#include "Doctor.h"
#include "Enfermera.h"
#include "Bombero.h"

int main() {
    // Crear instancias de diferentes oficios
    Arquitecto arq("Juan Carlo", 88);
    Doctor doc("Marco", 44);
    Enfermera enf("Elizabeth", 28);
    Bombero bom("Olga", 56);

    // Mostrar información de cada persona
    cout << "Información de personas por oficio:" << endl;
    cout << "------------------------------" << endl;
    
    arq.mostrarInformacion();
    cout << "------------------------------" << endl;

    doc.mostrarInformacion();
    cout << "------------------------------" << endl;

    enf.mostrarInformacion();
    cout << "------------------------------" << endl;

    bom.mostrarInformacion();
    cout << "------------------------------" << endl;

    return 0;
}
