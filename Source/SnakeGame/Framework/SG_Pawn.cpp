// Snake Game. Copyright Fozzy. All rights reserved

#include "Framework/SG_Pawn.h"
#include "Camera/CameraComponent.h"

namespace
{
double HalfFOVTan(double FOVDegrees)
{
    return FMath::Tan(FMath::DegreesToRadians(FOVDegrees * 0.5));
}

double VerticalFOV(double HorFOVDegrees, double ViewportAspectHW)
{
    return FMath::RadiansToDegrees(2.0 * FMath::Atan(FMath::Tan(FMath::DegreesToRadians(HorFOVDegrees) * 0.5) * ViewportAspectHW));
}

constexpr double GridMargin = 2.0;

}  // namespace

ASG_Pawn::ASG_Pawn()
{
    PrimaryActorTick.bCanEverTick = false;

    Origin = CreateDefaultSubobject<USceneComponent>("Origin");
    check(Origin);
    SetRootComponent(Origin);

    Camera = CreateDefaultSubobject<UCameraComponent>("Camera");
    check(Camera);
    Camera->SetupAttachment(Origin);
}

void ASG_Pawn::UpdateLocation(const SnakeGame::Dim& InDim, int32 InCellSize, const FTransform& InGridOrigin)
{
    Dim = InDim;
    CellSize = InCellSize;
    GridOrigin = InGridOrigin;

    check(GEngine);
    check(GEngine->GameViewport);
    check(GEngine->GameViewport->Viewport);

    auto* Viewport = GEngine->GameViewport->Viewport;
    Viewport->ViewportResizedEvent.Remove(ResizedHandle);
    ResizedHandle = Viewport->ViewportResizedEvent.AddUObject(this, &ASG_Pawn::OnViewportResized);

#if WITH_EDITOR
    OnViewportResized(Viewport, 0);
#endif
}

void ASG_Pawn::OnViewportResized(FViewport* Viewport, uint32 Val)
{
    if (!Viewport || Viewport->GetSizeXY().Y == 0 || Dim.height == 0) return;

    const double WorldWidth = Dim.width * CellSize;
    const double WorldHeight = Dim.height * CellSize;

    const double ViewportAspect = static_cast<double>(Viewport->GetSizeXY().X) / Viewport->GetSizeXY().Y;
    const double GridtAspect = static_cast<double>(Dim.width) / Dim.height;

    double LocationZ = 0.0;

    if (ViewportAspect <= GridtAspect)
    {
        const double MarginWidth = (Dim.width + GridMargin) * CellSize;
        LocationZ = (MarginWidth * 0.5) / HalfFOVTan(Camera->FieldOfView);
    }
    else
    {
        check(ViewportAspect);

        const double MarginHeight = (Dim.height + GridMargin) * CellSize;
        const double VerFOV = VerticalFOV(Camera->FieldOfView, 1.0 / ViewportAspect);
        LocationZ = (MarginHeight * 0.5) / HalfFOVTan(VerFOV);
    }
    const FVector NewPawnLocation = GridOrigin.GetLocation() + FVector(0.5f * WorldHeight, 0.5f * WorldWidth, LocationZ);
    SetActorLocation(NewPawnLocation);
}
