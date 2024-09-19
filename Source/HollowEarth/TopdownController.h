// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "PlayerChar.h"
#include "TopdownController.generated.h"

// Forward declarations
class UInputMappingContext;
class UInputAction;

/**
 * 
 */
UCLASS()
class HOLLOWEARTH_API ATopdownController : public APlayerController
{
	GENERATED_BODY()
	
protected:

	APlayerChar* PlayerChar{};

	virtual void BeginPlay() override;
	virtual void SetupInputComponent() override;
	void OnInputStarted();
	void OnMoveTriggered();
	void OnMoveReleased();

	void OnClickMove();
	void MovePlayer(FVector destination);

public:

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input)
	UInputMappingContext* defaultMappintContext{};

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input)
	UInputAction* setDestinationClick{};
};
