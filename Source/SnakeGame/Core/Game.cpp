// Snake Game. Copyright Fozzy. All rights reserved

#include "SnakeGame/Core/Game.h"
#include "SnakeGame/Core/Grid.h"
// #include "Core/Snake.h"
// #include "Core/Food.h"

DEFINE_LOG_CATEGORY_STATIC(LogGame, All, All);

using namespace SnakeGame;

Game::Game(const Settings& settings) : c_settings(settings)
{
    m_grid = MakeShared<Grid>(settings.gridDims /*, randomizer*/);
}
