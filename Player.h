#pragma once

#include <iostream>
#include <string>

using namespace std;

class Player
{
protected:
    string name;
    string job;
    int level;
    int hp;
    int mp;
    int power;
    int defence;

public:
    Player(string name, int hp, int mp, int power, int defence);

    virtual void attack() = 0;

    virtual void printPlayerStatus();

    virtual ~Player();
    
    string getName();
    string getJob();

    int getHP();
    int getMP();
    int getPower();
    int getDefence();

    void setHP(int hp);
};