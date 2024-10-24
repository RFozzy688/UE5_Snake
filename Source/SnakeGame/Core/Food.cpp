// Snake Game. Copyright Fozzy. All rights reserved

#include "Core/Food.h"

using namespace SnakeGame;

void Food::setPosition(const Position& position)
{
    m_position = position;
}

Position Food::position() const
{
    return m_position;
}
