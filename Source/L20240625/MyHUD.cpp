// Fill out your copyright notice in the Description page of Project Settings.


#include "MyHUD.h"
#include "MyPlayerController.h"
#include "MyCharacter.h"
#include "Engine/Canvas.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/Character.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Kismet/KismetMathLibrary.h"

AMyHUD::AMyHUD()
{
	CrosshairMaxOpen = 30;
	CrosshairHalfSize = 15;
}

void AMyHUD::DrawHUD()
{
	Super::DrawHUD();

	int32 CenterX = Canvas->SizeX / 2;
	int32 CenterY = Canvas->SizeY / 2;
	
	APlayerController* PlayerController = UGameplayStatics::GetPlayerController(GetWorld(), 0);
	if (PlayerController)
	{
		APawn* ControlledPawn = PlayerController->GetPawn();
		if (ControlledPawn)
		{
			ACharacter* Character = Cast<ACharacter>(ControlledPawn);
			if (Character)
			{
				UCharacterMovementComponent* Movement = Character->GetCharacterMovement();
				FVector Velocity = Movement->Velocity;
				float VelocityXY = FVector(Velocity.X, Velocity.Y, 0).Size();
				float MaxVelocity = Movement->GetMaxSpeed();
				CrosshairOpen = VelocityXY / MaxVelocity * CrosshairMaxOpen;

				DrawLine(CenterX - CrosshairHalfSize - CrosshairOpen, CenterY, CenterX - CrosshairOpen, CenterY, FLinearColor(1, 0, 0, 0), 3.f);
				DrawLine(CenterX + CrosshairOpen, CenterY, CenterX + CrosshairOpen + CrosshairHalfSize, CenterY, FLinearColor(1, 0, 0, 0), 3.f);
				DrawLine(CenterX, CenterY - CrosshairHalfSize - CrosshairOpen, CenterX, CenterY - CrosshairOpen, FLinearColor(1, 0, 0, 0), 3.f);
				DrawLine(CenterX, CenterY + CrosshairOpen, CenterX, CenterY + CrosshairOpen + CrosshairHalfSize, FLinearColor(1, 0, 0, 0), 3.f);
			}
			else
			{

			}
		}
	}
}