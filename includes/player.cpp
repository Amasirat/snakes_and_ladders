#include "classes.h"

#include "config.h"
//constructor
Player::Player(Color p_color) : 
m_color{p_color}, m_coordinate{0,0},
sixhappened{true}
{
    if(m_coordinate.y % 2 == 0)
        m_direction = true;
    else
        m_direction = false;
}
//win method for player
void Player::win() const
{
    std::cout << "Player has won the game! *clap* *clap*\n";
    std::cout << "Congratulations! You deserve it!\n";
    std::cin.get(); 
}
//change player's direction of movement
void Player::change_dir()
{
    m_direction = !(m_direction);
}
//returns 1 if player direction is left and -1 if it's right
int Player::direction() const
{
    if(m_direction) return 1;
    else return -1;
}
//movement of player based on move_count
void Player::move(int move_count)
{
    if(sixhappened)
    {
    //accounting for when player gets close to end coordinates
        if(m_coordinate.y == g_board_number - 1)
        {
            if(m_direction)
            {
                if(m_coordinate.x + move_count > 9)
                {
                    std::cout << "Oooooooh!!!You were so close, "
                    "but the dice number was too big! A shame really! Try Again\n";
                    return;
                }
            }
            else
            {
                if(m_coordinate.x - move_count < 0)
                {
                    std::cout << "Oooooooh!!!You were so close, "
                    "but the dice number was too big! A shame really! Try Again\n";
                    return;
                }
            }
        }
//player movement algorithm given a dice number
        int dice_number{move_count};
        while(m_coordinate.y < g_board_number)
        {
            while(move_count > 0 && m_coordinate.x < g_board_number)
            {
                m_coordinate.x += direction();
                --move_count;
                if(m_coordinate.x >= g_board_number || m_coordinate.x < 0)
                {
                    m_coordinate.x -= direction();
                    break;
                }
            }
            if(move_count == 0)
            {
                std::cout << "You moved by " << dice_number << '\n';
                return;
            }
            else if (m_coordinate.y < (g_board_number - 1))
            {
                ++m_coordinate.y;
                change_dir();
                --move_count;
            }
            else{--move_count;}
        }     
    }
    else
        std::cout << "You are not allowed to move, You still haven't gotten a six, you poor thing\n";
        std::cin.get();
        std::cin.get();
}
//given the right number(== 6), it will make player be able to move
void Player::make_movable(int num)
{
    if(num == 6)
    {
        sixhappened = true;
    }
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