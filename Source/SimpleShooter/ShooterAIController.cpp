// Fill out your copyright notice in the Description page of Project Settings.


#include "ShooterAIController.h"
#include "Kismet/GameplayStatics.h"
#include "BehaviorTree/BlackBoardComponent.h"

void AShooterAIController::BeginPlay() {

	Super::BeginPlay();

	if (AIBehavior)
	{
		RunBehaviorTree(AIBehavior);

		BlackBoard = GetBlackboardComponent();
		PlayerPawn = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);

		BlackBoard->SetValueAsVector(TEXT("StartLocation"), GetPawn()->GetActorLocation());

	}
}

void AShooterAIController::Tick(float DeltaTime) {
	Super::Tick(DeltaTime);

	//APawn* PlayerPawn = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);

	/*if (LineOfSightTo(PlayerPawn))
	{
		BlackBoard->SetValueAsVector(TEXT("PlayerLocation"), PlayerPawn->GetActorLocation());
		BlackBoard->SetValueAsVector(TEXT("LastKnownPlayerLocation"), PlayerPawn->GetActorLocation());
		//MoveToActor(PlayerPawn, AcceptanceRadius);
		//SetFocus(PlayerPawn);
	}
	else
	{
		BlackBoard->ClearValue(TEXT("PlayerLocation"));
		//StopMovement();
		//ClearFocus(EAIFocusPriority::Gameplay);
	}*/
}