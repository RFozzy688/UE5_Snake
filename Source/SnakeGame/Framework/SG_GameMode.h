// Snake Game. Copyright Fozzy. All rights reserved

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "SnakeGame/Core/Game.h"
#include "World/SG_Grid.h"
#include "World/SG_WorldTypes.h"
#include "SG_GameMode.generated.h"

class ASG_Grid;
class AExponentialHeightFog;

UCLASS()
class SNAKEGAME_API ASG_GameMode : public AGameModeBase
{
    GENERATED_BODY()

public:
    // ASG_GameMode();
    virtual void StartPlay() override;

protected:
    UPROPERTY(EditDefaultsOnly, meta = (ClampMin = "10", ClampMax = "100"))
    FUintPoint GridDims{10, 10};

    UPROPERTY(EditDefaultsOnly, meta = (ClampMin = "10", ClampMax = "100"))
    uint32 CellSize;

    UPROPERTY(EditDefaultsOnly)
    TSubclassOf<ASG_Grid> GridVisualClass;

    UPROPERTY(EditDefaultsOnly, Category = "Design")
    UDataTable* ColorsTable;

private:
    UPROPERTY()
    ASG_Grid* GridVisual;

    UPROPERTY()
    AExponentialHeightFog* Fog;

    UFUNCTION(Exec, Category = "Console command")
    void NextColor();

private:
    TUniquePtr<SnakeGame::Game> Game;
    uint32 ColorTableIndex{0};

    void FindFog();

    /**
     * Updates Grid and ExponentialFog colours
     * according to the ColorsTable property
     */  
    void UpdateColors();
};
