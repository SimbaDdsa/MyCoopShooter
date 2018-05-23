// Fill out your copyright notice in the Description page of Project Settings.

#include "Public/PlayerBase.h"
#include "Kismet/GameplayStatics.h"
#include "Public/WeaponBase.h"


//UClass AWeaponBase;
// Sets default values
APlayerBase::APlayerBase()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	

	//GetWorld()->SpawnActor<AWeaponBase>();
	//UGameplayStatics::BeginSpawningActorFromClass(this, TSubclassOf<AWeaponBase>* Rifle, );

}

// Called when the game starts or when spawned
void APlayerBase::BeginPlay()
{
	Super::BeginPlay();
	
}

void APlayerBase::MoveForward(float Value)
{
	APlayerBase::AddMovementInput(GetActorForwardVector(), Value);
}

void APlayerBase::MoveRight(float Value)
{
	APlayerBase::AddMovementInput(GetActorRightVector(), Value);
}

void APlayerBase::ViewPitch(float Value)
{
	APlayerBase::AddControllerPitchInput(Value);
}

void APlayerBase::ViewYaw(float Value)
{
	APlayerBase::AddControllerYawInput(Value);
}



// Called every frame
void APlayerBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void APlayerBase::SetupPlayerInputComponent(UInputComponent* PIC)
{
	Super::SetupPlayerInputComponent(PIC);
	//Super::SetupPlayerInputComponent(PlayerInputComponent);
	PIC -> BindAxis("MoveForward",this, &APlayerBase::MoveForward);
	PIC -> BindAxis("MoveRight", this, &APlayerBase::MoveRight);
	PIC -> BindAxis("TurnPitch", this, &APlayerBase::ViewPitch);
	PIC -> BindAxis("TurnYaw", this, &APlayerBase::ViewYaw);
}

