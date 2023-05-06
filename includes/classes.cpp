enum Color
{
    red,
    green,
    blue,
    yellow
};
class Board
{


private:
    int m_height{};
    int m_width{};

};
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