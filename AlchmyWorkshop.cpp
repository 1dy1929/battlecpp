#include "AlchemyWorkshop.h"
#include <limits>

AlchemyWorkshop::AlchemyWorkshop()
{
    recipes.push_back(
        PotionRecipe("HPPotion", "Herb", "Clear Water")
    );

    recipes.push_back(
        PotionRecipe("MPPotion", "Magic Herb", "Clear Water")
    );

    recipes.push_back(
        PotionRecipe("StaminaPotion", "Herb", "Berry")
    );
}

void AlchemyWorkshop::showAllRecipes() const
{
    cout << "\n";
    cout << "[ All Potion Recipes ]\n";

    for (const PotionRecipe& recipe : recipes)
    {
        recipe.printRecipe();
    }
}

void AlchemyWorkshop::searchByName(string name) const
{
    bool isFound = false;

    for (const PotionRecipe& recipe : recipes)
    {
        if (recipe.getPotionName() == name)
        {
            recipe.printRecipe();
            isFound = true;
        }
    }

    if (!isFound)
    {
        cout << "Recipe not found.\n";
    }
}

void AlchemyWorkshop::searchByIngredient(string ingredient) const
{
    int count = 0;

    for (const PotionRecipe& recipe : recipes)
    {
        if (recipe.hasIngredient(ingredient))
        {
            cout << "-> "
                << recipe.getPotionName()
                << " ("
                << recipe.getIngredient1()
                << " x1, "
                << recipe.getIngredient2()
                << " x1)\n";

            count++;
        }
    }

    if (count == 0)
    {
        cout << "Recipe not found.\n";
    }
    else
    {
        cout << "Found "
            << count
            << " recipes.\n";
    }
}

void AlchemyWorkshop::openMenu() const
{
    bool isBack = false;

    while (!isBack)
    {
        int choice;

        cout << "\n";
        cout << "=== Potion Shop ===\n";
        cout << "1. Show all recipes\n";
        cout << "2. Search by potion name\n";
        cout << "3. Search by ingredient\n";
        cout << "0. Go back\n";
        cout << "Choose: ";
        cin >> choice;

        if (cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            cout << "Invalid input.\n";
            continue;
        }

        switch (choice)
        {
        case 1:
            showAllRecipes();
            break;

        case 2:
        {
            string name;

            cout << "Search potion name: ";
            cin >> name;

            searchByName(name);

            break;
        }

        case 3:
        {
            string ingredient;

            cout << "Search ingredient: ";
            cin >> ingredient;

            searchByIngredient(ingredient);

            break;
        }

        case 0:
            isBack = true;
            break;

        default:
            cout << "Invalid menu number.\n";
            break;
        }
    }
}