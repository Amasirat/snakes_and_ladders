#include "classes.h"
#include <iostream>
//static int init
int Snake::s_id{0};

Snake::Snake(Coordinate start, Coordinate end) :
m_start{start}, m_end{end}
{
    ++s_id;
}
//move player character down
void Snake::move_player(Player& player)
{
    int player_x{m_start.x};
    int player_y{player.get_coordinate().y};
    //move player character down gently while changing movement direction each row
    while(player_y != m_start.y)
    {
        --player_y;
        player.change_dir();
    }
    player.change_coordinates(player_x, player_y);   
}
//returns snake's tail position
Coordinate Snake::get_start() const
{
    return m_start;
}
//returns snake's head position
Coordinate Snake::get_end() const
{
    return m_end;
}
