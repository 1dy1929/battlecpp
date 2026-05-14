#include "Warrior.h"

Warrior::Warrior(string name, int hp, int mp, int power, int defence)
    : Player(name, hp, mp, power, defence)
{
    job = "Warrior";
    this->hp += 30;

    cout << "* You became a Warrior! (HP +30)\n";
}

void Warrior::attack()
{
    cout << "* Swings a powerful sword!\n";
}