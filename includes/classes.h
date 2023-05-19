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
    void win() const;
//given the right number(== 6), it will make player be able to move
    void make_movable(int num);
//returns if it is possible to move player or not
    bool is_movable() const;
//change coordinates directly
    void change_coordinates(int x, int y);
//show coordinates on terminal screen in proper formatting
    void show_coordinates() const;
//changes player's direction of movement
    void change_dir();
//getter
    Coordinate get_coordinate() const;
    int direction() const;

private:
    Color m_color{};
    Coordinate m_coordinate;
    bool sixhappened{};
//left and right are represented by false and true respectively
    bool m_direction{};
    static int s_id;
};
///////////////////////////////
//class for the game's Board
class Board
{
public:

    Board(int length = 10);
    ~Board() = default;
    //for checking if player is on end coordnates
    bool player_is_on_end(const Player& player);
private:
    int m_length{};
    Coordinate m_end;
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

//getters
    Coordinate get_start()
    {
        return m_start;
    }
    Coordinate get_end()
    {
        return m_end;
    }
private:
    static int s_id;
    Coordinate m_start;
    Coordinate m_end;
};
//class outline for snake in game
class Snake
{
public:
//constructor
    Snake(Coordinate start, Coordinate end);
//default destructor
    ~Snake() = default;
//move player character down
    void move_player(Player& player);
//getters
    Coordinate get_start() const;
    Coordinate get_end() const;
private:
    Coordinate m_start;
    Coordinate m_end;
    static int s_id;
};
#endif