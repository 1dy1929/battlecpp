#pragma once
#pragma once

#include <iostream>
#include <string>
#include <vector>

#include "PotionRecipe.h"

using namespace std;

class AlchemyWorkshop
{
private:
    vector<PotionRecipe> recipes;

public:
    AlchemyWorkshop();

    void showAllRecipes() const;
    void searchByName(string name) const;
    void searchByIngredient(string ingredient) const;

    void openMenu() const;
};