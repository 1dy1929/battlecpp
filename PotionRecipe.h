#pragma once

#include <iostream>
#include <string>

using namespace std;

class PotionRecipe
{
private:
    string potionName;
    string ingredient1;
    string ingredient2;

public:
    PotionRecipe(
        string potionName,
        string ingredient1,
        string ingredient2
    );

    string getPotionName() const;
    string getIngredient1() const;
    string getIngredient2() const;

    void printRecipe() const;
    bool hasIngredient(string ingredient) const;
};