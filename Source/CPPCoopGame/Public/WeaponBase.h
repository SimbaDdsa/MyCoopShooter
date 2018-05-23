// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "WeaponBase.generated.h"

USTRUCT()
struct ReplicatedTrace
{
	GENERATED_BODY()
public :
	FVector TraceStart;
	FVector TraceEnd;
	//surface normal
	FVector SurfaceNormal;
	//trace from start to end, normalized
	FVector TraceDirection;
	bool SurfaceType;
};

UCLASS()
class CPPCOOPGAME_API AWeaponBase : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AWeaponBase();
	UPROPERTY(VisibleAnywhere, Category = "Gun Property")
	int32 AmmoClip;
	UPROPERTY(EditDefaultsOnly, Category = "Gun Property")
	int32 ClipMax;
	UPROPERTY(EditAnywhere, Category = "Gun Property")
	bool AutoFire;
	UPROPERTY(EditAnywhere, Category = "Gun Property")
	bool AutoReload;


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	bool trigger;
	bool Cooldown;
	void Fire();

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;


	void TriggerDown();
	void TriggerUp();

	void Reload(int32 Ammo);
	void Equip(bool equip);

	bool TryReload();
	void GetStatus(int32* Clip, int32* Max);
	
	
};
