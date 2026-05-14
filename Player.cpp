#include "Player.h"

Player::Player(string name, int hp, int mp, int power, int defence)
    : name(name),
    job("None"),
    level(1),
    hp(hp),
    mp(mp),
    power(power),
    defence(defence)
{
}

void Player::printPlayerStatus()
{
    cout << "------------------------------------\n";
    cout << "Name: " << name
        << " | Job: " << job
        << " | Lv." << level << "\n";

    cout << "HP: " << hp
        << " | MP: " << mp
        << " | Attack: " << power
        << " | Defense: " << defence << "\n";

    cout << "------------------------------------\n";
}

Player::~Player()
{
} 
string Player::getName()
{
    return name;
}

string Player::getJob()
{
    return job;
}

int Player::getHP()
{
    return hp;
}

int Player::getMP()
{
    return mp;
}

int Player::getPower()
{
    return power;
}

int Player::getDefence()
{
    return defence;
}

void Player::setHP(int hp)
{
    this->hp = hp;
}