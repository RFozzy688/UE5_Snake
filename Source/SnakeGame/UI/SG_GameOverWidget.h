// Snake Game. Copyright Fozzy. All rights reserved

#pragma once
#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "SG_GameOverWidget.generated.h"

class UTextBlock;
class UButton;

UCLASS()
class SNAKEGAME_API USG_GameOverWidget : public UUserWidget
{
    GENERATED_BODY()

public:
    void SetScore(uint32 Score);
    void SetResetGameKeyName(const FString& ResetGameKeyName);

protected:
    UPROPERTY(meta = (BindWidget))
    TObjectPtr<UTextBlock> ScoreText;

    UPROPERTY(meta = (BindWidget))
    TObjectPtr<UTextBlock> ResetGameText;

    UPROPERTY(meta = (BindWidget))
    TObjectPtr<UButton> BackToMenuButton;

    UPROPERTY(EditDefaultsOnly)
    TSoftObjectPtr<UWorld> MenuLevel;

    UPROPERTY(meta = (BindWidget))
    TObjectPtr<UButton> CloseGameButton;

    virtual void NativeOnInitialized() override;

private:
    UFUNCTION()
    void OnBackToMenu();

    UFUNCTION()
    void OnCloseGame();
};
