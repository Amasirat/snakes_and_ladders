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
//struct representing coordinates in the entire program
struct Coordinate
{
    int x;
    int y;
};

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

/////////////////////////////////////
/////////////////////////////////////
//Class for the Player characters
class Player
{
public:
//constructor
    Player(Color p_color);
//destructor
    ~Player() = default;

//moving the player correctly through the board based on a number of movements
    void move(int move_count);
//player's win state
    void win(const Board& game_board);
//given the right number(== 6), it will make player be able to move
    void make_movable(int num);
//returns if it is possible to move player or not
    bool is_movable() const;
//change coordinates directly
    void change_coordinates(int x, int y);
//show coordinates on terminal screen in proper formatting
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
//class outline for snake in game
class Snake
{
public:
//constructor
    Snake();
//default destructor
    ~Snake() = default;
private:
    Coordinate m_start;
    Coordinate m_end;
};
#endif