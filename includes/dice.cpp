#include "classes.h"

#include "config.h"
#include <iostream>

Dice::Dice(int sides) : m_sides{sides}
{
    sixhappened = false;
}

int Dice::throw_dice()
{
    srand((unsigned) time(NULL));
    int num = (rand() % m_sides) + 1;
    if(num == 6)
        sixhappened = true;
    return num;
}

//void Dice::move_player(Player& player, int dice_throw)
//{

  //  if(sixhappened)
  //  {
  //      player.move(dice_throw);
  //  }
  //  else
  //  {
  //      std::cout << "Player not allowed to move!\n";
  //  }
//}