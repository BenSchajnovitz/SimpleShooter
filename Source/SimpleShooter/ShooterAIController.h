// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "ShooterAIController.generated.h"

/**
 * 
 */
UCLASS()
class SIMPLESHOOTER_API AShooterAIController : public AAIController
{
	GENERATED_BODY()
	
private:
	UPROPERTY(EditAnywhere)
		class UBehaviorTree* AIBehavior;

	APawn* PlayerPawn;

	UBlackboardComponent* BlackBoard;
 
protected:
	virtual void BeginPlay() override;

public:
	bool isDead() const;
	virtual void Tick(float DeltaTime) override;
};

