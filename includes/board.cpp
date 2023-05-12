#include "classes.h"
#include <iostream>

bool Board::direction{true};
Board::Board(int length) : m_length{length}
{
    m_end.y = m_length - 1;
    if(m_end.y % 2 == 0)
    {
        m_end.x = m_length - 1;
    }
    else
    {
        m_end.x = 0;
    }
}
void Board::print()
{
    for(int j{m_length - 1}; j >= 0; --j)
    {
        for(int i{0}; i < m_length; ++i)
        {
            std::cout << "(" << i << "," << j << ")\t\t";
        }
        std::cout << '\n';
    }  
}
