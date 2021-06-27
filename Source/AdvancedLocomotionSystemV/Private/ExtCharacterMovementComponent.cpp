


#include "ExtCharacterMovementComponent.h"

#include "GameFramework/Character.h"
#include <string>
UExtCharacterMovementComponent::UExtCharacterMovementComponent(const FObjectInitializer& ObjectInitializer)
: Super(ObjectInitializer)
{

}

void UExtCharacterMovementComponent::SetUpdatedComponent(USceneComponent* NewUpdatedComponent)
{
	Super::SetUpdatedComponent(NewUpdatedComponent);

	if(IsValid(CharacterOwner))
	{
		CharacterOwner->LandedDelegate.AddDynamic(this, &UExtCharacterMovementComponent::ReactOnCharacterLandedDelegate);
	}
}

void UExtCharacterMovementComponent::ReactOnCharacterLandedDelegate(const FHitResult& Hit)
{
	UE_LOG(LogTemp,Warning,TEXT("UExtCharacterMovementComponent::ReactOnCharacterLandedDelegate"))
	CurrentCountWallJumps  = 0;
}


bool UExtCharacterMovementComponent::DoWallJump_Implementation(bool bReplayingMoves)
{
	UE_LOG(LogTemp, Warning, TEXT("CharacterOwner: %i, IsWallJump %i"), CharacterOwner, IsWallJump)
	if (CharacterOwner && IsWallJump && CurrentCountWallJumps < MaxCountWallJumps)
	{
		// Don't jump if we can't move up/down.
  		if (!bConstrainToPlane || FMath::Abs(PlaneConstraintNormal.Z) != 1.f)
		{
  			Velocity.X = WallJumpForwardVector.X * JumpZVelocity;
  			Velocity.Y = WallJumpForwardVector.Y * JumpZVelocity;
  			Velocity.Z = JumpZVelocity;
			
  			// CharacterOwner->LaunchCharacter(WallJumpForwardVector*1000, true, true);
            SetMovementMode(MOVE_Falling);
			ResetWallJump_Implementation();
  			CurrentCountWallJumps = ++CurrentCountWallJumps;
			return true;
		}
	}
	return false;
}

void UExtCharacterMovementComponent::ResetWallJump_Implementation()
{
	IsWallJump = false;
	WallJumpForwardVector = FVector::ZeroVector;
	WallJumpResetTimerHandle.Invalidate();
}
