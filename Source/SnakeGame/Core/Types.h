// Snake Game. Copyright Fozzy. All rights reserved

#pragma once

#include "CoreMinimal.h"

namespace SnakeGame
{
struct Dim
{
    int32 width;
    int32 height;
};

enum class CellType
{
    Empty = 0,
    Wall
    // Food
    // Snake
};

struct Settings
{
    Dim gridDims;
};
}  // namespace SnakeGame