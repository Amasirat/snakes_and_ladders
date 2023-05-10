#include "classes.h"
#include <iostream>

bool Board::direction{true};
Board::Board(int length) : m_length{length}
{
    srand((unsigned) time(NULL));
    m_end.x = rand() % m_length;
    m_end.y = m_length - 1;
}
