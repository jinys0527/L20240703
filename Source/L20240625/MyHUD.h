// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "MyHUD.generated.h"

/**
 * 
 */
UCLASS()
class L20240625_API AMyHUD : public AHUD
{
	GENERATED_BODY()
public:
	AMyHUD();

	UFUNCTION()
	virtual void DrawHUD() override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, category = "Crosshair")
	int32 CrosshairMaxOpen;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, category = "Crosshair")
	int32 CrosshairHalfSize;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, category = "Crosshair")
	float CrosshairOpen;
};
