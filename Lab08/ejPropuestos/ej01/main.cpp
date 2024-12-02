#include <iostream>
#include "receta.h"
using namespace std;

int main() {
    int type;
    while (true) {
        cout << endl << "Ingrese un tipo de receta (1: Lomo Saltado, 2: Ceviche, 3: Arroz Chaufa) o '0' para salir:" << endl;
        cin >> type;

        if (type == 0) {
            break;
        }

        Recipe* recipe = RecipeFactory::createRecipe(type);
        if (recipe) {
            recipe->showRecipe();
            delete recipe;
        }
    }

    cout << "Saliendo..." << endl;
    return 0;
}
