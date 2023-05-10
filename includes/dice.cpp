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

void Dice::move_player(Player& player, int dice_throw)
{
    if(player.is_movable())
    {
        player.move(dice_throw);
    }
    else
    {
        std::cout << "Player not allowed to move!\n";
    }
}