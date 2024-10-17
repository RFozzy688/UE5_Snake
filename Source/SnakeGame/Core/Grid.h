// Snake Game. Copyright Fozzy. All rights reserved

#pragma once

#include "CoreMinimal.h"
#include "Types.h"
// #include "Utils.h"

namespace SnakeGame
{

class Grid
{
public:
    Grid(const Dim& dim /*, const IPositionRandomizerPtr& randomizer = MakeShared<PositionRandomizer>()*/);

    /**
     * Returns grid dimensions including walls (width + 2; height + 2)
     * @return Dim  grid dimensions
     */
    Dim dim() const { return c_dim; }

private:
    const Dim c_dim;
    TArray<CellType> m_cells;

    void initWalls();
    void printDebug();

    FORCEINLINE uint32 posToIndex(uint32 x, uint32 y) const;

    // FORCEINLINE uint32 posToIndex(const Position& position) const;
};

}  // namespace SnakeGame
