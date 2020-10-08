// Fill out your copyright notice in the Description page of Project Settings.


#include "Gun.h"
#include "Components/SkeletalMeshComponent.h"
#include "Kismet/GameplayStatics.h"
#include "DrawDebugHelpers.h"

// Sets default values
AGun::AGun()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Root = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	SetRootComponent(Root);

	Mesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Mesh"));
	Mesh->SetupAttachment(Root);
	
}

// Called when the game starts or when spawned
void AGun::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AGun::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


void AGun::PullTrigger() {
	UGameplayStatics::SpawnEmitterAttached(MuzzleFlash, Mesh, TEXT("MuzzleFlashSocket"));

	APawn* OwnerPawn = Cast<APawn>(GetOwner());
	if (!OwnerPawn) return;
	AController* OwnerController = OwnerPawn->GetController();
	if (!OwnerController) return;

	FVector ViewLocation;
	FRotator ViewRotation;

	OwnerController->GetPlayerViewPoint(ViewLocation, ViewRotation);

	FVector End = ViewLocation + ViewRotation.Vector() * MaxRange;

	FHitResult Hit;

	bool bSuccess = GetWorld()->LineTraceSingleByChannel(
		Hit,
		ViewLocation,
		End, ECollisionChannel::ECC_GameTraceChannel1
	);

	if (bSuccess)
	{
		FVector ShotDirection = -ViewRotation.Vector();

		UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), ImpactParticle, Hit.ImpactPoint, ShotDirection.Rotation());
	
		AActor* HitActor = Hit.GetActor();

		if (!HitActor) return;

		FPointDamageEvent DamageEvent(Damage, Hit, ShotDirection, nullptr);
		HitActor->TakeDamage(Damage, DamageEvent, OwnerController, this);

		//DrawDebugPoint(GetWorld(), Hit.ImpactPoint, 20, FColor::Red, true);
	}

	//DrawDebugCamera(GetWorld(), ViewLocation, ViewRotation, 90, 2, FColor::Red, true);
}
