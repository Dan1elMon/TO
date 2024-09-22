#include <iostream>
#include <iomanip> 
#include <string>

using namespace std;

class CitaMedica {
private:
    string fecha;
    string hora;
    string tipoAtencion;
    int numeroAsegurado;
    string nombrePaciente;
    string especialidad;
    string doctorAsignado;
    string estado;

public:
    // Constructor
    CitaMedica() : fecha(""), hora(""), tipoAtencion(""),
     numeroAsegurado(0), nombrePaciente(""), especialidad(""), 
     doctorAsignado(""), estado("Pendiente") {}

    // Métodos set
    void setFecha(const string& fechaDet) { fecha = fechaDet; }
    void setHora(const string& horaDet) { hora = horaDet; }
    void setTipoAtencion(const string& tipo) { tipoAtencion = tipo; }
    void setNumeroAsegurado(int numero) { numeroAsegurado = numero; }
    void setNombrePaciente(const string& nombre) { nombrePaciente = nombre; }
    void setEspecialidad(const string& esp) { especialidad = esp; }
    void setDoctorAsignado(const string& doctor) { doctorAsignado = doctor; }
    void setEstado(const string& est) { estado = est; }

    // Método para imprimir detalles
    void imprimirDetalles() const {
        cout << left << setw(20) << "Nombre Paciente:" << nombrePaciente << endl;
        cout << left << setw(20) << "Fecha:" << fecha << endl;
        cout << left << setw(20) << "Hora:" << hora << endl;
        cout << left << setw(20) << "Tipo de Atención:" << tipoAtencion << endl;
        cout << left << setw(20) << "Número Asegurado:" << numeroAsegurado << endl;
        cout << left << setw(20) << "Especialidad:" << especialidad << endl;
        cout << left << setw(20) << "Doctor Asignado:" << doctorAsignado << endl;
        cout << left << setw(20) << "Estado:" << estado << endl;
    }
};

int main() {
    CitaMedica cita;
    cita.setFecha("2024-09-22");
    cita.setHora("12:45");
    cita.setTipoAtencion("Consulta");
    cita.setNumeroAsegurado(123456);
    cita.setNombrePaciente("Juan de Dios");
    cita.setEspecialidad("Cardiología");
    cita.setDoctorAsignado("Dr. Judas");
    cita.setEstado("Confirmada");

    // Imprimir detalles de la cita
    cita.imprimirDetalles();

    return 0;
}
