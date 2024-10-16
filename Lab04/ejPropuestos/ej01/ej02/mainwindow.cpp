#include <QApplication>
#include <QWidget>
#include <QVBoxLayout>
#include <QListWidget>
#include <QLabel>
#include <QTextEdit>

class CarreraWindow : public QWidget {
    Q_OBJECT

public:
    CarreraWindow(QWidget *parent = nullptr) : QWidget(parent) {
        // Configurar el layout principal
        QVBoxLayout *layout = new QVBoxLayout(this);

        // Lista de carreras
        QListWidget *listaCarreras = new QListWidget(this);
        listaCarreras->addItem("Ciencia de la Computación");
        listaCarreras->addItem("Ingeniería de Software");
        listaCarreras->addItem("Sistemas de Información");
        listaCarreras->addItem("Tecnología de la Información");
        listaCarreras->addItem("Ingeniería en Computación");

        // Label para mostrar la carrera seleccionada
        QLabel *labelCarrera = new QLabel("Selecciona una carrera", this);
        QTextEdit *textoEspecificacion = new QTextEdit(this);
        textoEspecificacion->setReadOnly(true);

        // Agregar widgets al layout
        layout->addWidget(listaCarreras);
        layout->addWidget(labelCarrera);
        layout->addWidget(textoEspecificacion);

        // Conectar la señal del clic de la lista con la función de mostrar carrera
        connect(listaCarreras, &QListWidget::itemClicked, [=](QListWidgetItem *item) {
            QString carrera = item->text();
            labelCarrera->setText("Carrera seleccionada: " + carrera);

            // Mostrar especificación de acuerdo a la carrera seleccionada
            if (carrera == "Ciencia de la Computación") {
                textoEspecificacion->setText("Estudia los fundamentos teóricos de la computación...");
            } else if (carrera == "Ingeniería de Software") {
                textoEspecificacion->setText("Se enfoca en el diseño, desarrollo y mantenimiento de software...");
            } else if (carrera == "Sistemas de Información") {
                textoEspecificacion->setText("Mezcla el conocimiento de tecnología con gestión de información...");
            } else if (carrera == "Tecnología de la Información") {
                textoEspecificacion->setText("Se especializa en la implementación de tecnologías en organizaciones...");
            } else if (carrera == "Ingeniería en Computación") {
                textoEspecificacion->setText("Combina principios de ingeniería eléctrica y ciencias de la computación...");
            }
        });
    }
};

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    CarreraWindow window;
    window.setWindowTitle("Carreras Profesionales en Sistemas y Computación");
    window.resize(400, 300);
    window.show();

    return app.exec();
}

#include "main.moc"
