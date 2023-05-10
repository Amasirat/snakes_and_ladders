#include "classes.h"
#include <iostream>
#include "config.h"
Ladder::Ladder(Coordinate start, Coordinate end) : m_start{start}, m_end{end}
{}
void Ladder::move(Player& player)
{
    int x{m_end.x};
    int y{player.get_coordinate().y};
    for(int i{0}; i < m_end.y; ++i)
    {
        ++y;
        Board::change_dir();
    }
    player.change_coordinates(x,y);
}