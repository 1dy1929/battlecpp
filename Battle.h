#pragma once

#include <vector>

#include "Player.h"
#include "Monster.h"
#include "Item.h"

using namespace std;

void battle(
    Player* player,
    Monster& monster,
    vector<Item>& inventory
);