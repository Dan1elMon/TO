#include "receta.h"

// Implementacion de LomoSaltado
void LomoSaltado::setName() {
    name = "Lomo Saltado";
}

void LomoSaltado::setIngredients() {
    ingredients = "Lomo de res, cebolla, tomate, papa frita, sillao, vinagre, sal, pimienta.";
}

void LomoSaltado::setPreparationSteps() {
    preparationSteps = 
        "1. Cortar la carne en tiras y sazonar.\n"
        "2. Saltear en un wok con aceite caliente.\n"
        "3. Agregar cebolla, tomate y sillao.\n"
        "4. Incorporar las papas fritas.\n"
        "5. Servir acompaniado de arroz.";
}

void LomoSaltado::showRecipe() {
    cout << "Receta: " << name << endl
         << "Ingredientes: " << ingredients << endl
         << "Preparacion:\n" << preparationSteps << endl;
}

// Implementacion de Ceviche
void Ceviche::setName() {
    name = "Ceviche";
}

void Ceviche::setIngredients() {
    ingredients = "Pescado fresco, limon, cebolla roja, aji limo, cilantro, sal.";
}

void Ceviche::setPreparationSteps() {
    preparationSteps = 
        "1. Cortar el pescado en cubos.\n"
        "2. Marinar con jugo de limon y sal.\n"
        "3. Agregar cebolla, aji y cilantro.\n"
        "4. Servir frio acompaniado de camote y choclo.";
}

void Ceviche::showRecipe() {
    cout << "Receta: " << name << endl
         << "Ingredientes: " << ingredients << endl
         << "Preparacion:\n" << preparationSteps << endl;
}

// Implementacion de Arroz Chaufa
void ArrozChaufa::setName() {
    name = "Arroz Chaufa";
}

void ArrozChaufa::setIngredients() {
    ingredients = "Arroz cocido, pollo, huevo, cebolla china, sillao, aceite.";
}

void ArrozChaufa::setPreparationSteps() {
    preparationSteps = 
        "1. Cocinar el pollo y cortarlo en trozos pequeños.\n"
        "2. Batir los huevos y hacer un omelette, luego cortarlo.\n"
        "3. En un wok, saltear el pollo, huevo y arroz con sillao.\n"
        "4. Agregar cebolla china y servir caliente.";
}

void ArrozChaufa::showRecipe() {
    cout << "Receta: " << name << endl
         << "Ingredientes: " << ingredients << endl
         << "Preparacion:\n" << preparationSteps << endl;
}

// Implementacion de RecipeFactory
Recipe* RecipeFactory::createRecipe(int type) {
    Recipe* recipe = nullptr;
    switch (type) {
    case 1:
        recipe = new LomoSaltado();
        break;
    case 2:
        recipe = new Ceviche();
        break;
    case 3:
        recipe = new ArrozChaufa();
        break;
    default:
        cout << "Tipo de receta invalido. Intente nuevamente." << endl;
        return nullptr;
    }
    recipe->setName();
    recipe->setIngredients();
    recipe->setPreparationSteps();
    return recipe;
}
