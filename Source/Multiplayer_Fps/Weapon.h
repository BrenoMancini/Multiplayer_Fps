// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "gamedata.h"
#include "GameFramework/Actor.h"
#include "Weapon.generated.h"

UCLASS()
class MULTIPLAYER_FPS_API AWeapon : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AWeapon();
	UFUNCTION(BlueprintPure, Category = "Character Attributes")
	static void SplitWeaponAttributes(const FWeaponAttributes& InAttributes, float& OutCadency, float& OutBaseDamage, int& OutMaxAmmo, float& OutRange)
	{
		OutCadency = InAttributes.Cadency;
		OutBaseDamage = InAttributes.BaseDamage;
		OutMaxAmmo = InAttributes.MaxAmmo;
		OutRange =InAttributes.Range;
	}

	UFUNCTION(BlueprintPure, Category = "Character Attributes")
	static void SplitWeaponData(const FWeapons& InWeaponData, FName& OutCharID, FText& OutWeaponName, float& OutCadency, float& OutBaseDamage, int& OutMaxAmmo,  float& OutRange)
	{
		OutWeaponName =  InWeaponData.WeaponName;
		SplitWeaponAttributes(InWeaponData.WeaponAttributes, OutCadency,OutBaseDamage,OutMaxAmmo, OutRange);
	
	}

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Weapon")
	FWeapons WeaponData;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data")
	UDataTable* WeaponDataTable;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Weapon")
	FName WeaponRowID;

public:	
	// Called every frame

	virtual void Tick(float DeltaTime) override;

};
