// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "PlayerBase.generated.h"

UCLASS()
class CPPCOOPGAME_API APlayerBase : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	APlayerBase();
	bool CharacterActive;

	UPROPERTY(VisibleAnywhere, Category = "Movement")
	float ForwardMove;
	float RightMove;
	float PitchMove;
	float YawMove;



protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	void MoveForward(float Value);
	void MoveRight(float Value);
	void ViewPitch(float Value);
	void ViewYaw(float Value);
	

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PIC) override;
	//PlayerInputComponent->BindAxis("MoveForward", this, &APlayerBase::MoveForward);
	
	
};
