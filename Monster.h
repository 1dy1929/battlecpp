#pragma once

#include <iostream>
#include <string>

#include "Player.h"

using namespace std;

class Monster
{
private:
    string name;

    int hp;
    int power;
    int defence;

    string dropItemName;
    int dropItemPrice;

public:
    Monster(
        string name,
        int hp,
        int power,
        int defence,
        string dropItemName,
        int dropItemPrice
    );

    void attack(Player* player);

    void printMonsterStatus();

    string getName();

    int getHP();
    int getPower();
    int getDefence();

    string getDropItemName();
    int getDropItemPrice();

    void setHP(int hp);
};