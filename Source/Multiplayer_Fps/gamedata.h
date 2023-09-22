#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "GameFramework/Actor.h"
#include "gamedata.generated.h"


class AWeapon;

// Basic character attributes for data table
USTRUCT()
struct FCharAttributes : public FTableRowBase
{
	GENERATED_BODY()
	
	UPROPERTY(EditAnywhere)
	FText Name;
	UPROPERTY(EditAnywhere)
	float Speed;
	UPROPERTY(EditAnywhere)
	float Mass;
	UPROPERTY(EditAnywhere)
	float JumpVelocity;
	UPROPERTY(EditAnywhere, meta=(ClampMax = 1.0))
	float AirControl;
	UPROPERTY(EditAnywhere)
	int64 Jumps;
	UPROPERTY(EditAnywhere)
	float Defense;
	
	
};

// Weapon Base Attributes, it will be set as variables of the weapons
USTRUCT()
struct FWeaponAttributes : public FTableRowBase
{
	GENERATED_BODY()
	
	UPROPERTY(EditAnywhere)
	float Cadency;
	UPROPERTY(EditAnywhere)
	int MaxAmmo;
	UPROPERTY(EditAnywhere)
	float BaseDamage;
	UPROPERTY(EditAnywhere)
	float Range;
		
};

// Main Character Struct for Data Table
USTRUCT()
struct FCharacters : public FTableRowBase
{
	GENERATED_BODY()
	
	UPROPERTY(EditAnywhere)
	FName CharID;
	UPROPERTY(EditAnywhere)
	FText CharacterName;
	UPROPERTY(EditAnywhere)
	FCharAttributes Attributes;
	UPROPERTY(EditAnywhere)
	TSubclassOf<AWeapon> MainWeapon;
	
};

//Weapon Data for data Table
USTRUCT()
struct FWeapons : public FTableRowBase
{
	GENERATED_BODY()
	
	UPROPERTY(EditAnywhere)
	FName WeaponID;
	UPROPERTY(EditAnywhere)
	FText WeaponName;
	UPROPERTY(EditAnywhere)
	TSubclassOf<AWeapon> MainWeaponClass;
	UPROPERTY(EditAnywhere)
	FWeaponAttributes WeaponAttributes; 
};
