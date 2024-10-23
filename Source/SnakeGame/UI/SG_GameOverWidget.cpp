// Snake Game. Copyright Fozzy. All rights reserved

#include "UI/SG_GameOverWidget.h"
#include "Components/TextBlock.h"
#include "World/SG_WorldUtils.h"
#include "Components/Button.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetSystemLibrary.h"

void USG_GameOverWidget::NativeOnInitialized()
{
    Super::NativeOnInitialized();

    check(BackToMenuButton);
    BackToMenuButton->OnClicked.AddDynamic(this, &ThisClass::OnBackToMenu);

    check(CloseGameButton);
    CloseGameButton->OnClicked.AddDynamic(this, &ThisClass::OnCloseGame);
}

void USG_GameOverWidget::OnCloseGame()
{
    UKismetSystemLibrary::QuitGame(GetWorld(), GetOwningPlayer(), EQuitPreference::Quit, false);
}

void USG_GameOverWidget::SetScore(uint32 Score)
{
    if (ScoreText)
    {
        ScoreText->SetText(SnakeGame::WorldUtils::FormatScore(Score));
    }
}

void USG_GameOverWidget::SetResetGameKeyName(const FString& ResetGameKeyName)
{
    if (ResetGameText)
    {
        const FString ResetGameInfo = FString::Printf(TEXT("press <%s> to reset"), *ResetGameKeyName.ToLower());
        ResetGameText->SetText(FText::FromString(ResetGameInfo));
    }
}

void USG_GameOverWidget::OnBackToMenu()
{
    if (!MenuLevel.IsNull())
    {
        UGameplayStatics::OpenLevel(GetWorld(), FName(MenuLevel.GetAssetName()));
    }
}