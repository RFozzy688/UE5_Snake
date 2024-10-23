// Snake Game. Copyright Fozzy. All rights reserved

#include "Framework/SG_MenuGameMode.h"
#include "World/SG_WorldUtils.h"

void ASG_MenuGameMode::StartPlay()
{
    Super::StartPlay();

    SnakeGame::WorldUtils::SetUIInput(GetWorld(), true);
}