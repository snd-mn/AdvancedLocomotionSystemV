// 


#include "ExtCharacter.h"

#include "ExtCharacterMovementComponent.h"
#include "Components/ArrowComponent.h"
#include "Components/CapsuleComponent.h"
#include "Engine/CollisionProfile.h"

FName AExtCharacter::MeshComponentName(TEXT("CharacterMesh"));
FName AExtCharacter::CharacterMovementComponentName(TEXT("ExtCharMoveComp"));
FName AExtCharacter::CapsuleComponentName(TEXT("CollisionCylinder"));

// Sets default values
AExtCharacter::AExtCharacter(const FObjectInitializer& ObjectInitializer)
: Super(ObjectInitializer.SetDefaultSubobjectClass<UExtCharacterMovementComponent>(ACharacter::CharacterMovementComponentName))
{
}

// Called when the game starts or when spawned
void AExtCharacter::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AExtCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void AExtCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

void AExtCharacter::PostInitializeComponents()
{
	Super::PostInitializeComponents();
	ExtCharacterMovement = Cast<UExtCharacterMovementComponent>(GetCharacterMovement());
}

// //TODO can be removed?
// bool AExtCharacter::CanJump() const
// {
// 	
// 	return CanJumpInternal() || ExtCharacterMovement->IsWallJump;
// }

FVector AExtCharacter::GetJumpVector_Implementation()
{
	return FVector();
}
