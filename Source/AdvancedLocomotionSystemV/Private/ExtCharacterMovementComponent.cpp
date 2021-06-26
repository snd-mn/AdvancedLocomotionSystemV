


#include "ExtCharacterMovementComponent.h"

#include "GameFramework/Character.h"




bool UExtCharacterMovementComponent::DoWallJump_Implementation(bool bReplayingMoves)
{
	UE_LOG(LogTemp, Warning, TEXT("CharacterOwner: %i, IsWallJump %i"), CharacterOwner, IsWallJump)
	if (CharacterOwner && IsWallJump)
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
