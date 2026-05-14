#include "PotionRecipe.h"

PotionRecipe::PotionRecipe(
    string potionName,
    string ingredient1,
    string ingredient2
)
    : potionName(potionName),
    ingredient1(ingredient1),
    ingredient2(ingredient2)
{
}

string PotionRecipe::getPotionName() const
{
    return potionName;
}

string PotionRecipe::getIngredient1() const
{
    return ingredient1;
}

string PotionRecipe::getIngredient2() const
{
    return ingredient2;
}

void PotionRecipe::printRecipe() const
{
    cout << "-> "
        << potionName
        << ": "
        << ingredient1
        << " x1, "
        << ingredient2
        << " x1\n";
}

bool PotionRecipe::hasIngredient(string ingredient) const
{
    return ingredient1 == ingredient
        || ingredient2 == ingredient;
}