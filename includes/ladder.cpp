#include "classes.h"
#include <iostream>
#include "config.h"
//static var init
int Ladder::s_id{0};
Ladder::Ladder(Coordinate start, Coordinate end) : m_start{start}, m_end{end}
{++s_id;}
void Ladder::move(Player& player)
{
//x is not problematic, it can be set as anything, however the y axis is delicate since board's direction of 
//movement will be affected. My solution is to increment y which holds player's current y postion
//each loop and while doing that also change board direction with it
    int x{m_end.x};
    int y{player.get_coordinate().y};
    while(y != m_end.y && y < m_end.y)
    {
        ++y;
        player.change_dir();
    }
   // for(int i{0}; i < m_end.y; ++i)
   // {
   //     ++y;
   //     player.change_dir();
   // }
    player.change_coordinates(x,y);
}