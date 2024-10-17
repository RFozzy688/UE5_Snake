// Snake Game. Copyright Fozzy. All rights reserved

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Core/Types.h"
#include "SG_Pawn.generated.h"

class UCameraComponent;

UCLASS()
class SNAKEGAME_API ASG_Pawn : public APawn
{
    GENERATED_BODY()

public:
    ASG_Pawn();

    /**
     * Updates pawn height fitting grid in viewport
     * @param Dim  grid dimensions
     * @param CellSize  world size of the cell
     * @param GridOrigin  world transformation of the grid
     */
    void UpdateLocation(const SnakeGame::Dim& InDim, int32 InCellSize, const FTransform& InGridOrigin);

protected:
    UPROPERTY(VisibleAnywhere)
    USceneComponent* Origin;

    UPROPERTY(VisibleAnywhere)
    UCameraComponent* Camera;

private:
    SnakeGame::Dim Dim;
    int32 CellSize;
    FTransform GridOrigin;

    FDelegateHandle ResizedHandle;

    void OnViewportResized(FViewport* Viewport, uint32 Val);
};
