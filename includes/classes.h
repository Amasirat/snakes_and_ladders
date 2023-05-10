#ifndef CLASSES_H
#define CLASSES_H
#include <iostream>
//enum for all possible colors for players
enum Color
{
    red,
    green,
    blue,
    yellow
};
//coordinate struct for entire program
struct Coordinate
{
    int x;
    int y;
};
/////////////////////////////////////
/////////////////////////////////////
//Class for the Player characters

///////////////////////////////
//class for the game's Board
class Board
{
public:

    Board(int length = 10);
    ~Board() = default;
//get direction of board movement
    static int get_dir()
    {
        if(direction)
            return 1;
        else
            return -1;
    }
    static void change_dir()
    {
        direction = !(direction);
    }
private:
    int m_length{};
    Coordinate m_end;
//left and right are represented by false and true respectively
    static bool direction;
};

class Player
{
public:
//constructor
    Player(Color p_color);
//destructor
    ~Player() = default;
    void move(int dice);
    void win(const Board& game_board);
    void make_movable(int num);
    bool is_movable() const;
    void change_coordinates(int x, int y);
    void show_coordinates() const;

//getter
    Coordinate get_coordinate() const;
private:
    Color m_color{};
    Coordinate m_coordinate;
    int m_score;
    bool sixhappened{};
};
//////////////////////
/////////////////////
//a class outline for Dice in game
class Dice
{
public:
    Dice(int sides = 6);
    ~Dice() = default;
//to throw dice and return a number from 1 to m_sides
    int throw_dice(Player& Player);
    void move_player(Player& player, int dice_throw);
private:
    int m_sides{};
};

////////////////////////////////////////
//ladder class
class Ladder
{
public:
    Ladder(Coordinate start, Coordinate end);
    ~Ladder() = default;

    void move(Player& player);
private:
    Coordinate m_start;
    Coordinate m_end;
};
#endif