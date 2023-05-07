#include "classes.h"
#include <iostream>

Dice::Dice(int sides) : m_sides{sides}
{}

int Dice::throw_dice()
{
    srand((unsigned) time(NULL));
    return (rand() % m_sides) + 1;
}