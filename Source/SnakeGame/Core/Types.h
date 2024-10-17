// Snake Game. Copyright Fozzy. All rights reserved

#pragma once

#include "CoreMinimal.h"

namespace SnakeGame
{
struct Dim
{
    uint32 width;
    uint32 height;
};

enum class CellType
{
    Empty = 0,
    Wall,
    Snake,
    Food
};

struct Settings
{
    Dim gridDims{40, 10};
    // struct Snake
    //{
    //     uint32 defaultSize{4};
    //     Position startPosition{0, 0};
    // } snake;
    // float gameSpeed{1.0f};
};
}  // namespace SnakeGame