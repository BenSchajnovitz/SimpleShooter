// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTaskNode_Shoot.h"
#include "AIController.h"
#include "Characters/ShooterCharacter.h"

UBTTaskNode_Shoot::UBTTaskNode_Shoot() {
	NodeName = "Shoot";
}

EBTNodeResult::Type UBTTaskNode_Shoot::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) {
	Super::ExecuteTask(OwnerComp, NodeMemory);

	AAIController* Controller = OwnerComp.GetAIOwner();
	
	if (!Controller) return EBTNodeResult::Failed;

	AShooterCharacter* Character = Cast<AShooterCharacter>(Controller->GetPawn());

	if (!Character) return EBTNodeResult::Failed;

	Character->Shoot();

	return EBTNodeResult::Succeeded;
}
