// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "gamedata.h"
#include "GameFramework/Character.h"
#include "Fps_Character.generated.h"

UCLASS()
class MULTIPLAYER_FPS_API AFps_Character : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AFps_Character();


	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	//Logic variables
	bool bCanDoubleJump;
	int32 JumpsCounter;

	UPROPERTY(Replicated, VisibleAnywhere, BlueprintReadWrite, Category = "Character")
	float fDamagePercentage;
	UPROPERTY(Replicated, VisibleAnywhere, BlueprintReadOnly, Category = "Character")
	FCharacters CharacterData;

	UFUNCTION(BlueprintPure, Category = "Character Attributes")
	static void SplitCharAttributes(const FCharAttributes& InAttributes, FText& OutName, float& OutSpeed, float& OutMass, float& OutJumpVelocity, float& OutAirControl, float& OutDefense, float
	                                & OutGravity)
	{
		OutName = InAttributes.Name;
		OutSpeed = InAttributes.Speed;
		OutMass = InAttributes.Mass;
		OutGravity = InAttributes.Gravity;
		OutJumpVelocity = InAttributes.JumpVelocity;
		OutAirControl = InAttributes.AirControl;
		OutDefense = InAttributes.Defense;
	}

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Character")
	FName CharacterRowID;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Character")
	AWeapon* ActiveWeapon;

	void Jump();
	virtual void Landed(const FHitResult& Hit) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data")
	UDataTable* CharDataTable;
	
	UFUNCTION(BlueprintPure, Category = "Character Attributes")
	static void SplitCharData(const FCharacters& InCharacterData, FName& OutCharID, FText& OutCharacterName, FText& OutName, float& OutSpeed, float& OutMass, float& OutJumpVelocity, float& OutAirControl, float& OutDefense, float& OutGravity, TSubclassOf<AWeapon>& OutMainWeapon)
	{
		OutCharID = InCharacterData.CharID;

		SplitCharAttributes(InCharacterData.Attributes, OutName, OutSpeed, OutMass, OutJumpVelocity, OutAirControl, OutDefense, OutGravity);
		OutCharacterName = InCharacterData.CharacterName;
		OutMainWeapon = InCharacterData.MainWeapon;
	}
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	UFUNCTION(BlueprintCallable,Category="Damage")
	void ApplySpikeDamage(const FVector& DamagePoint, float SpikeDamageAmount);
	UFUNCTION(BlueprintCallable,Category="Character")
	
	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
