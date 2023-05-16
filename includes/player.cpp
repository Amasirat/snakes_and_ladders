#include "classes.h"

#include "config.h"
int Player::s_id{0};
Player::Player(Color p_color) : m_color{p_color}, m_coordinate{5,9},
sixhappened{true}
{
    ++s_id;
    if(m_coordinate.y % 2 == 0)
        m_direction = true;
    else
        m_direction = false;
}
//win method for player
void Player::win() const
{
    std::cout << "Player " << s_id << " has won the game! *clap* *clap*\n";
    std::cout << "Congratulations, Player " << s_id << "! You deserve it!\n";    
}
void Player::change_dir()
{
    m_direction = !(m_direction);
}
//returns 1 if player direction is left and -1 if it's right
int Player::direction() const
{if(m_direction)return 1;else return -1;}

void Player::move(int move_count)
{
    if(sixhappened)
    {
        if(m_coordinate.y == g_board_number - 1 && (m_coordinate.x - move_count < -1 || m_coordinate.x + move_count > 10))
        {
            std::cout << "Oooooooh!!!You were so close, "
            "but the dice number was too big! A shame really! Try Again\n";
            return;
        }
        else
            while(m_coordinate.y < g_board_number)
            {
                while(move_count > 0 && m_coordinate.x < g_board_number)
                {
                    m_coordinate.x += direction();
                    if(m_coordinate.x >= g_board_number || m_coordinate.x < 0)
                    {
                        m_coordinate.x -= direction();
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
                    change_dir();
                    --move_count;
                }
                else
                {
                    win();
                    --move_count;
                }
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