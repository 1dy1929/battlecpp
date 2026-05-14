#include "Battle.h"

void battle(
    Player* player,
    Monster& monster,
    vector<Item>& inventory
)
{
    cout << "\n";

    cout << "[ Battle Start! ] "
        << player->getName()
        << "("
        << player->getJob()
        << ") vs "
        << monster.getName()
        << "\n\n";

    while (player->getHP() > 0
        && monster.getHP() > 0)
    {
        cout << "--- Player Turn ---\n";

        player->attack();

        int damage =
            player->getPower()
            - monster.getDefence();

        if (damage <= 0)
        {
            damage = 1;
        }

        int beforeHP = monster.getHP();

        monster.setHP(
            monster.getHP() - damage
        );

        cout << damage
            << " damage to "
            << monster.getName()
            << "!\n";

        cout << monster.getName()
            << " HP: "
            << beforeHP
            << " -> "
            << monster.getHP();

        if (monster.getHP() <= 0)
        {
            cout << " (Dead)\n\n";

            cout << "Victory!\n";

            Item droppedItem(
                monster.getDropItemName(),
                monster.getDropItemPrice()
            );

            cout << " -> Got: "
                << monster.getDropItemName()
                << "!\n";

            if (inventory.size() >= 10)
            {
                cout << " -> Inventory is full. Item could not be saved.\n";
            }
            else
            {
                inventory.push_back(droppedItem);

                cout << " -> Saved to inventory.\n";
            }

            break;
        }

        cout << "\n\n";

        

        cout << "--- Monster Turn ---\n";

        monster.attack(player);

        damage =
            monster.getPower()
            - player->getDefence();

        if (damage <= 0)
        {
            damage = 1;
        }

        beforeHP = player->getHP();

        player->setHP(
            player->getHP() - damage
        );

        cout << damage
            << " damage to "
            << player->getName()
            << "!\n";

        cout << player->getName()
            << " HP: "
            << beforeHP
            << " -> "
            << player->getHP();

        if (player->getHP() <= 0)
        {
            cout << " (Dead)\n\n";

            cout << "Defeat...\n";

            break;
        }

        cout << "\n\n";
    }
}