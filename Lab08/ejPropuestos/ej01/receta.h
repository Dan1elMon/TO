#ifndef RECETA_H
#define RECETA_H

#include <iostream>
#include <string>
using namespace std;

// Clase base
class Recipe {
protected:
    string name;
    string ingredients;
    string preparationSteps;

public:
    virtual void setName() = 0;
    virtual void setIngredients() = 0;
    virtual void setPreparationSteps() = 0;
    virtual void showRecipe() = 0;
    virtual ~Recipe() {}
};

// Clase derivada para Lomo Saltado
class LomoSaltado : public Recipe {
public:
    void setName() override;
    void setIngredients() override;
    void setPreparationSteps() override;
    void showRecipe() override;
};

// Clase derivada para Ceviche
class Ceviche : public Recipe {
public:
    void setName() override;
    void setIngredients() override;
    void setPreparationSteps() override;
    void showRecipe() override;
};

// Clase derivada para Arroz Chaufa
class ArrozChaufa : public Recipe {
public:
    void setName() override;
    void setIngredients() override;
    void setPreparationSteps() override;
    void showRecipe() override;
};

// Clase RecipeFactory
class RecipeFactory {
public:
    static Recipe* createRecipe(int type);
};

#endif // RECETA_H
