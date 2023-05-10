#include "classes.h"

#include "config.h"

Player::Player(Color p_color) : m_color{p_color}, m_coordinate{0,8} 
{}

void Player::move(int dice)
{
    while(m_coordinate.y < g_board_number)
    {
        while(dice > 0 && m_coordinate.x < g_board_number)
        {
            m_coordinate.x += Board::get_dir();
            if(m_coordinate.x >= g_board_number || m_coordinate.x < 0)
            {
                m_coordinate.x -= Board::get_dir();
                break;
            }
            else
                --dice;
        }
        if(dice == 0)
        {
            break;
        }
        else if (m_coordinate.y < (g_board_number - 1))
        {
            ++m_coordinate.y;
            Board::change_dir();
            --dice;
        }
        else
        {
            std::cout << "Can not move higher\n";
            --dice;
        }
    }  
std::cerr << m_coordinate.x << ',' << m_coordinate.y << '\n'; 
}