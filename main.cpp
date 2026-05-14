#include <iostream>
#include <string>
#include <limits>
#include <vector>

#include "Warrior.h"
#include "Magician.h"
#include "Thief.h"
#include "Archer.h"

#include "Monster.h"
#include "Battle.h"
#include "item.h"
#include "AlchemyWorkshop.h"

using namespace std;

const int SIZE = 4;

enum StatIndex
{
    HP = 0,
    MP,
    ATTACK,
    DEFENSE
};

void printTitle()
{
    cout << "===========================================\n";
    cout << "      [ Dungeon Escape Text RPG ]\n";
    cout << "===========================================\n";
}

void inputName(string& name)
{
    cout << "Enter your hero's name: ";
    cin >> name;

    cout << "\n";
}

void inputStatus(int stat[])
{
    while (true)
    {
        cout << "Enter HP and MP: ";
        cin >> stat[HP] >> stat[MP];

        if (cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            cout << "Invalid input. Please enter numbers only.\n";
            continue;
        }

        if (stat[HP] > 50 && stat[MP] > 50)
        {
            break;
        }

        cout << "HP or MP is too low. Try again.\n";
    }

    while (true)
    {
        cout << "Enter Attack and Defense: ";
        cin >> stat[ATTACK] >> stat[DEFENSE];

        if (cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            cout << "Invalid input. Please enter numbers only.\n";
            continue;
        }

        if (stat[ATTACK] > 0 && stat[DEFENSE] > 0)
        {
            break;
        }

        cout << "Attack or Defense is too low. Try again.\n";
    }

    cout << "\n";
}

void printStatus(string name, int stat[])
{
    cout << "====================================\n";
    cout << "  " << name << "'s Stats\n";
    cout << "====================================\n";

    cout << "HP: " << stat[HP]
        << "    MP: " << stat[MP] << "\n";

    cout << "Attack: " << stat[ATTACK]
        << "    Defense: " << stat[DEFENSE] << "\n";

    cout << "====================================\n";
}

void upgradeMenu(string name, int stat[])
{
    int hpPotion = 5;
    int mpPotion = 5;

    bool isGameStart = false;

    int choice;

    cout << "\n";
    cout << "* You received 5 HP Potions and 5 MP Potions.\n";

    while (!isGameStart)
    {
        cout << "===========================================\n";
        cout << "< Character Upgrade >\n";
        cout << "1. HP UP    2. MP UP    3. Attack x2\n";
        cout << "4. Defense x2  5. Show Stats  0. Start Game\n";
        cout << "===========================================\n";

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
            if (hpPotion > 0)
            {
                stat[HP] += 20;
                hpPotion--;

                cout << "* HP increased by 20. ";
                cout << "(HP Potion used: "
                    << hpPotion
                    << " left)\n";
            }
            else
            {
                cout << "* No HP Potions left.\n";
            }

            break;

        case 2:
            if (mpPotion > 0)
            {
                stat[MP] += 20;
                mpPotion--;

                cout << "* MP increased by 20. ";
                cout << "(MP Potion used: "
                    << mpPotion
                    << " left)\n";
            }
            else
            {
                cout << "* No MP Potions left.\n";
            }

            break;

        case 3:
            stat[ATTACK] *= 2;

            cout << "* Attack doubled.\n";

            break;

        case 4:
            stat[DEFENSE] *= 2;

            cout << "* Defense doubled.\n";

            break;

        case 5:
            printStatus(name, stat);

            break;

        case 0:
            cout << "Starting the game!\n";

            isGameStart = true;

            break;

        default:
            cout << "Invalid menu number.\n";

            break;
        }

        cout << "\n";
    }
}

Player* selectJob(string name, int stat[])
{
    int choice;

    while (true)
    {
        cout << "< Job Selection >\n";
        cout << name << ", choose your job!\n";
        cout << "1. Warrior   2. Mage   3. Rogue   4. Archer\n";
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
            return new Warrior(name, stat[HP], stat[MP], stat[ATTACK], stat[DEFENSE]);

        case 2:
            return new Magician(name, stat[HP], stat[MP], stat[ATTACK], stat[DEFENSE]);

        case 3:
            return new Thief(name, stat[HP], stat[MP], stat[ATTACK], stat[DEFENSE]);

        case 4:
            return new Archer(name, stat[HP], stat[MP], stat[ATTACK], stat[DEFENSE]);

        default:
            cout << "Invalid menu number.\n";
            break;
        }

        cout << "\n";
    }
}

void printInventory(const vector<Item>& inventory)
{
    cout << "\n";
    cout << "[ Inventory (" << inventory.size() << "/10) ]\n";

    if (inventory.empty())
    {
        cout << "Inventory is empty.\n";
        return;
    }

    int index = 1;

    for (const Item& item : inventory)
    {
        cout << index << ". ";
        item.printInfo();

        index++;
    }
}

void enterDungeon(Player* player, vector<Item>& inventory)
{
    int choice;

    cout << "\n";
    cout << "=== Dungeon ===\n";
    cout << "1. Slime\n";
    cout << "2. Goblin\n";
    cout << "Choose monster: ";
    cin >> choice;

    if (cin.fail())
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cout << "Invalid input.\n";
        return;
    }

    switch (choice)
    {
    case 1:
    {
        Monster slime(
            "Slime",
            30,
            20,
            10,
            "Slime Jelly",
            100
        );

        battle(player, slime, inventory);

        break;
    }

    case 2:
    {
        Monster goblin(
            "Goblin",
            50,
            25,
            5,
            "Goblin Tooth",
            150
        );

        battle(player, goblin, inventory);

        break;
    }

    default:
        cout << "Invalid monster number.\n";
        break;
    }
}

void mainMenu(Player* player, vector<Item>& inventory)
{
    AlchemyWorkshop workshop;

    bool isQuit = false;

    while (!isQuit)
    {
        int menuChoice;

        cout << "\n";
        cout << "=== Main Menu ===\n";
        cout << "1. Enter Dungeon\n";
        cout << "2. Check Inventory\n";
        cout << "3. Potion Shop\n";
        cout << "0. Quit\n";
        cout << "Choose: ";
        cin >> menuChoice;

        if (cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            cout << "Invalid input.\n";
            continue;
        }

        switch (menuChoice)
        {
        case 1:
            enterDungeon(player, inventory);

            break;

        case 2:
            printInventory(inventory);

            break;

        case 3:
            workshop.openMenu();

            break;

        case 0:
            cout << "Quit game.\n";

            isQuit = true;

            break;

        default:
            cout << "Invalid menu number.\n";

            break;
        }
    }
}

int main()
{
    string name;

    int stat[SIZE] = { 0 };

    printTitle();

    inputName(name);

    inputStatus(stat);

    printStatus(name, stat);

    upgradeMenu(name, stat);

    Player* player = selectJob(name, stat);

    vector<Item> inventory;

    cout << "\n";

    player->printPlayerStatus();

    mainMenu(player, inventory);

    delete player;

    player = nullptr;

    return 0;
}