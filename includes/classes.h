#include <iostream>
//enum for the character's colors
enum Color
{
    red,
    green,
    blue,
    yellow
};
//class for the games Board
class Board
{
public:
    Board(int n = 10, bool direction = 1);
    ~Board();

private:
    int m_n{};
    bool m_direction{}; //left and right are represented by false and true respectively
    int m_end_coordinates[2]{};
};
//a class outline for Dice in game
class Dice
{
public:
    Dice(int sides = 6);
    ~Dice() = default;
//to throw dice and return a number from 1 to m_sides
    int throw_dice();

private:
    const int m_sides{6};
    
};
//Class for the Player characters
class Player
{
public:
//constructor
    Player(Color p_color);
//destructor
    ~Player();
    void change_coordinates(int x, int y);
private:
Color m_color{};
int m_coordinates[2];
};