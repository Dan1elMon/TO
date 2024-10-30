#include <iostream>
#include <vector>
#include <string>
#include <algorithm> // Incluir esta cabecera para usar std::find

using namespace std;

class SynonymList {
private:
    std::string word;
    std::vector<std::string> synonyms;

public:
    // Constructor que inicializa la palabra principal
    SynonymList(const std::string& mainWord) : word(mainWord) {}

    // Método para mostrar los sinónimos
    void showSynonyms() const {
        std::cout << "Sinónimos de \"" << word << "\":\n";
        if (synonyms.empty()) {
            std::cout << "No hay sinónimos disponibles.\n";
        } else {
            for (const auto& synonym : synonyms) {
                std::cout << "- " << synonym << '\n';
            }
        }
    }

    // Método para agregar un sinónimo
    void addSynonym(const std::string& synonym) {
        synonyms.push_back(synonym);
        std::cout << "Sinónimo \"" << synonym << "\" agregado.\n";
    }

    // Método para eliminar un sinónimo
    void removeSynonym(const std::string& synonym) {
        auto it = std::find(synonyms.begin(), synonyms.end(), synonym);
        if (it != synonyms.end()) {
            synonyms.erase(it);
            std::cout << "Sinónimo \"" << synonym << "\" eliminado.\n";
        } else {
            std::cout << "Sinónimo \"" << synonym << "\" no encontrado.\n";
        }
    }
};

int main() {
    // Crear la lista de sinónimos para una palabra
    SynonymList mySynonyms("rápido");

    // Mostrar la lista vacía de sinónimos
    mySynonyms.showSynonyms();

    // Agregar algunos sinónimos
    mySynonyms.addSynonym("veloz");
    mySynonyms.addSynonym("ligero");
    mySynonyms.addSynonym("pronto");

    // Mostrar los sinónimos actualizados
    mySynonyms.showSynonyms();

    // Eliminar un sinónimo
    mySynonyms.removeSynonym("ligero");

    // Mostrar los sinónimos después de la eliminación
    mySynonyms.showSynonyms();

    return 0;
}
