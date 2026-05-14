#include "Monster.h"

Monster::Monster(
    string name,
    int hp,
    int power,
    int defence,
    string dropItemName,
    int dropItemPrice
)
    : name(name),
    hp(hp),
    power(power),
    defence(defence),
    dropItemName(dropItemName),
    dropItemPrice(dropItemPrice)
{
}

void Monster::attack(Player* player)
{
    cout << name << " attacks!\n";
}

void Monster::printMonsterStatus()
{
    cout << "Monster: " << name << "\n";

    cout << "HP: " << hp
        << " Attack: " << power
        << " Defense: " << defence << "\n";
}

string Monster::getName()
{
    return name;
}

int Monster::getHP()
{
    return hp;
}

int Monster::getPower()
{
    return power;
}

int Monster::getDefence()
{
    return defence;
}

string Monster::getDropItemName()
{
    return dropItemName;
}

int Monster::getDropItemPrice()
{
    return dropItemPrice;
}

void Monster::setHP(int hp)
{
    this->hp = hp;
}