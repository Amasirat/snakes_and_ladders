#include "classes.h"
#include <iostream>

Board::Board(int n, bool direction) : m_n{n}, m_direction{direction}
{
    srand((unsigned) time(NULL));
    m_end_coordinates[0] = rand() % m_n;
    m_end_coordinates[1] = n - 1;
}