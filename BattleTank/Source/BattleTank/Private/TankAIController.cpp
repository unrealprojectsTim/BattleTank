// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "Engine/World.h"
#include "GameFramework/PlayerController.h"
#include "TankAIController.h"

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();

	auto ControlledTank = GetControlledTank();
	auto PlayerTank = GetPlayerTank();

	if (!PlayerTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("AI Controller can't find player tank"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("AI Controller found: %s"), *(PlayerTank->GetName()));
	}
	UE_LOG(LogTemp, Warning, TEXT("AIController Find Tank"));
}

ATank* ATankAIController::GetPlayerTank()
{
	auto PlayerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();
	
	if (!PlayerPawn) { return nullptr; }
	return Cast<ATank>(PlayerPawn);

}

ATank* ATankAIController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}
