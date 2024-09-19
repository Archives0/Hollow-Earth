// Fill out your copyright notice in the Description page of Project Settings.


#include "TopdownController.h"
#include "Movement.h"
#include "Kismet/GameplayStatics.h"
#include "EnhancedInputComponent.h"
#include "InputActionValue.h"
#include "EnhancedInputSubsystems.h"

void ATopdownController::BeginPlay()
{
	Super::BeginPlay();

	bShowMouseCursor = true;
	bEnableClickEvents = true;
	bEnableMouseOverEvents = true;

	PlayerChar = Cast<APlayerChar>(UGameplayStatics::GetActorOfClass(GetWorld(), APlayerChar::StaticClass()));
}

void ATopdownController::SetupInputComponent()
{
	Super::SetupInputComponent();

	// Add IMC.

	if (UEnhancedInputLocalPlayerSubsystem* subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer()))
	{
		subsystem->AddMappingContext(defaultMappintContext, 0);
	}

	// Set up action binding.

	if (UEnhancedInputComponent* enhancedInputComponent = Cast<UEnhancedInputComponent>(InputComponent))
	{
		enhancedInputComponent->BindAction(setDestinationClick, ETriggerEvent::Started, this, &ATopdownController::OnInputStarted);
		enhancedInputComponent->BindAction(setDestinationClick, ETriggerEvent::Triggered, this, &ATopdownController::OnMoveTriggered);
		enhancedInputComponent->BindAction(setDestinationClick, ETriggerEvent::Completed, this, &ATopdownController::OnMoveReleased);
		enhancedInputComponent->BindAction(setDestinationClick, ETriggerEvent::Canceled, this, &ATopdownController::OnMoveReleased);
	}


}

void ATopdownController::OnInputStarted()
{
	StopMovement();
}

void ATopdownController::OnMoveTriggered()
{
	FHitResult hit{};
	bool hitSuccess = GetHitResultUnderCursor(ECC_Visibility, false, hit);

	if (hitSuccess)
	{
		MovePlayer(hit.ImpactPoint);
	}
}

void ATopdownController::OnMoveReleased()
{

}

void ATopdownController::OnClickMove()
{
	
}

void ATopdownController::MovePlayer(FVector destination)
{
	if (PlayerChar)
	{
		UMovement* moveComp = PlayerChar->GetComponentByClass<UMovement>();

		if (moveComp)
		{
			moveComp->MoveToPoint(destination);
		}
		else
		{
			UE_LOG(LogTemp, Error, TEXT("Player missing movement component."));
		}
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("Player character ref in controller class is null."));
	}
}
