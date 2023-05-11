#include "classes.h"

#include "config.h"
#include <iostream>

Dice::Dice(int sides) : m_sides{sides}
{}

int Dice::throw_dice(Player& player)
{
    srand((unsigned) time(NULL));
    int num = (rand() % m_sides) + 1;
    player.make_movable(num);
    return num;
}