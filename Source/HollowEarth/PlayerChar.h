// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "PlayerChar.generated.h"

UCLASS()
class HOLLOWEARTH_API APlayerChar : public ACharacter
{
	GENERATED_BODY()

protected:

	virtual void BeginPlay() override;



public:	
	
	APlayerChar();
	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	void InitializePlayer();
};
