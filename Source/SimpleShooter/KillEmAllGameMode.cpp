// Fill out your copyright notice in the Description page of Project Settings.

#include "EngineUtils.h"
#include "GameFramework/Controller.h"
#include "ShooterAIController.h"
#include "KillEmAllGameMode.h"

void AKillEmAllGameMode::PawnKilled(APawn* KilledPawn)
{
	Super::PawnKilled(KilledPawn);
	
	APlayerController* PlayerController = Cast<APlayerController>(KilledPawn->GetController());

	if (PlayerController)
	{
		EndGame(false);
	}
	else
	{
		for (AShooterAIController* AIController : TActorRange<AShooterAIController>(GetWorld()))
		{
			if (!AIController->isDead()) { return; }
		}

		EndGame(true);
	}



}

void AKillEmAllGameMode::EndGame(bool bIsPlayerWinner)
{
	for (AController* Controller : TActorRange<AController>(GetWorld()))
	{
		bool isWinner = (Controller->IsPlayerController() == bIsPlayerWinner);
		Controller->GameHasEnded(Controller->GetPawn(), isWinner);
	}
}

