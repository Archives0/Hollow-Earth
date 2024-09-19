 // Fill out your copyright notice in the Description page of Project Settings.


#include "Movement.h"

// Sets default values for this component's properties
UMovement::UMovement()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	CheckValid();
}


// Called when the game starts
void UMovement::BeginPlay()
{
	Super::BeginPlay();
}

void UMovement::CheckValid()
{
	owner = Cast<APawn>(GetOwner());

	if (!owner)
		UE_LOG(LogTemp, Warning, TEXT("Movement component attached to actor which cannot move."));
}


// Called every frame
void UMovement::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

void UMovement::MoveToPoint(FVector destination)
{
	UE_LOG(LogTemp, Display, TEXT("Move triggered in move comp."));

	if (owner)
	{
		owner->SetActorLocation(destination);
	}
}

