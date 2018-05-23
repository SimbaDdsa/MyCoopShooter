// Fill out your copyright notice in the Description page of Project Settings.

#include "Public/WeaponBase.h"


// Sets default values
AWeaponBase::AWeaponBase()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;



}

// Called when the game starts or when spawned


void AWeaponBase::BeginPlay()
{
}

void AWeaponBase::Fire()
{
	//Trace
}

// Called every frame
void AWeaponBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (AmmoClip != 0 && Cooldown && trigger)
		Fire();

}

void AWeaponBase::TriggerDown()
{
	trigger = true;
}

void AWeaponBase::TriggerUp()
{
	trigger = false;
}

void AWeaponBase::Reload(int32 Ammo)
{
	AmmoClip += Ammo;
}

void AWeaponBase::Equip(bool equip)
{
}

bool AWeaponBase::TryReload()
{
	return false;
}

void AWeaponBase::GetStatus(int32 * Clip, int32 * Max)
{
}

