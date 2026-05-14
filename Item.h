#pragma once

#include <iostream>
#include <string>

using namespace std;

struct Item
{
    string name;
    int price;

    Item(string name, int price)
        : name(name), price(price)
    {
    }

    void printInfo() const
    {
        cout << name << " (" << price << "G)\n";
    }
};