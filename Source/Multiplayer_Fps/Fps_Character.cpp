// Fill out your copyright notice in the Description page of Project Settings.


#include "Fps_Character.h"

#include "Weapon.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Net/UnrealNetwork.h"

// Sets default values
AFps_Character::AFps_Character()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}
void AFps_Character::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &ACharacter::Jump);
}

void AFps_Character::GetLifetimeReplicatedProps(TArray< FLifetimeProperty > & OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	// Replicar a propriedade CameraRotation
	DOREPLIFETIME(AFps_Character,CharacterData);
}

void AFps_Character::Jump()
{
	if (JumpsCounter > 0)
	{
		Super::Jump();
		LaunchCharacter(FVector(0.f, 0.f, CharacterData.Attributes.JumpVelocity), false, true);
		JumpsCounter--;
	}
}

void AFps_Character::Landed(const FHitResult& Hit)
{
	Super::Landed(Hit);
    JumpsCounter = CharacterData.Attributes.Jumps;
	
}

// Called when the game starts or when spawned
void AFps_Character::BeginPlay()
{
	Super::BeginPlay();
	FCharacters* CharacterDataRow = CharDataTable->FindRow<FCharacters>(FName(CharacterRowID), "");

	if (CharacterDataRow)
	{
		CharacterData.CharID = CharacterDataRow->CharID;
		CharacterData.CharacterName = CharacterDataRow->CharacterName;
		CharacterData.Attributes = CharacterDataRow->Attributes;
		CharacterData.MainWeapon = CharacterDataRow->MainWeapon;
		JumpsCounter = CharacterData.Attributes.Jumps;
		ActiveWeapon = Cast<AWeapon>(GetComponentByClass(AWeapon::StaticClass()));
		if (GetCharacterMovement())
		{
			GetCharacterMovement()->MaxWalkSpeed = CharacterData.Attributes.Speed;
			GetCharacterMovement()->Mass = CharacterData.Attributes.Mass;
			GetCharacterMovement()->JumpZVelocity = CharacterData.Attributes.JumpVelocity;
			GetCharacterMovement()->AirControl = CharacterData.Attributes.AirControl;
		}
	}
	else
	{
	}
	ActiveWeapon = Cast<AWeapon>(GetComponentByClass(AWeapon::StaticClass()));
}

// Called every frame
void AFps_Character::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input

