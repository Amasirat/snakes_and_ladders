#include "classes.h"
#include <iostream>

void Board::initializer()
{
    srand((unsigned) time(NULL));
    m_end_coordinates[0] = rand() % m_length;
    m_end_coordinates[1] = m_length - 1;
}
Board::Board(bool direction, int length) : m_length{length}, m_direction{direction}
{
    initializer();
}
Board::Board(int length) : m_length{length}
{
    initializer();
}