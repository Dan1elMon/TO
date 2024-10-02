#include "arquitecto.h"
#include "doctor.h"
#include "enfermera.h"
#include "bombero.h"

int main(int argc, char *argv[]) {

    Arquitecto arq("Carlos", 30);
    Doctor doc("Ana", 35);
    Enfermera enf("Luis", 28);
    Bombero bom("Sofía", 40);

    arq.presentar();
    doc.presentar();
    enf.presentar();
    bom.presentar();

}
