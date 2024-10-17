// Snake Game. Copyright Fozzy. All rights reserved

#pragma once

#include "CoreMinimal.h"
#include "Types.h"

namespace SnakeGame
{

class Grid;
// class Snake;
// class Food;

class Game
{
public:
    Game(const Settings& settings /*, const IPositionRandomizerPtr& randomizer = MakeShared<PositionRandomizer>()*/);

    /**
     * Returns the pointer to the grid object
     * @return TSharedPtr<Grid>  pointer to the grid object
     */
    TSharedPtr<Grid> grid() const { return m_grid; }

private:
    const Settings c_settings;
    TSharedPtr<Grid> m_grid;
};
}  // namespace SnakeGame
