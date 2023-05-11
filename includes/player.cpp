#include "classes.h"

#include "config.h"

Player::Player(Color p_color) : m_color{p_color}, m_coordinate{1,0},
sixhappened{true}
{}

void Player::move(int move_count)
{
    if(sixhappened)
        while(m_coordinate.y < g_board_number)
        {
            while(move_count > 0 && m_coordinate.x < g_board_number)
            {
                m_coordinate.x += Board::get_dir();
                if(m_coordinate.x >= g_board_number || m_coordinate.x < 0)
                {
                    m_coordinate.x -= Board::get_dir();
                    break;
                }
                else
                    --move_count;
            }
            if(move_count == 0)
            {
                break;
            }
            else if (m_coordinate.y < (g_board_number - 1))
            {
                ++m_coordinate.y;
                Board::change_dir();
                --move_count;
            }
            else
            {
                std::cout << "Can not move higher\n";
                --move_count;
            }
        }
    else
        std::cout << "You are not allowed to move, You still haven't gotten a six, you poor thing\n";
}
//given the right number(== 6), it will make player be able to move
void Player::make_movable(int num)
{
    if(num == 6)
    {
        sixhappened = true;
    }
    else{return;}
}
bool Player::is_movable() const
{
    return sixhappened;
}
void Player::change_coordinates(int x, int y)
{
    m_coordinate.x = x;
    m_coordinate.y = y;
}
void Player::show_coordinates() const
{
    std::cout << "You are here --> (" << m_coordinate.x << ',' << m_coordinate.y << ")\n";
}
//getter
Coordinate Player::get_coordinate() const
{
    return m_coordinate;
}