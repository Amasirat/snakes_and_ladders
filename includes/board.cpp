#include "classes.h"
#include <iostream>

Board::Board(int length) : m_length{length}
{
    m_end.y = m_length - 1;
    if(m_end.y % 2 == 0)
    {
        m_end.x = m_length - 1;
    }
    else
    {
        m_end.x = 0;
    }
}
//for checking if player is on end coordnates
bool Board::player_is_on_end(const Player& player)
{
    return player.get_coordinate().x == m_end.x &&
    player.get_coordinate().y == m_end.y;  
}