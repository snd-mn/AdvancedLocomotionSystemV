


#include "ExtCharacterMovementComponent.h"

#include "GameFramework/Character.h"

bool UExtCharacterMovementComponent::DoJump(bool bReplayingMoves)
{

	if (CharacterOwner && CharacterOwner->CanJump() && IsWallJump)
	{
		// Don't jump if we can't move up/down.
		if (!bConstrainToPlane || FMath::Abs(PlaneConstraintNormal.Z) != 1.f)
		{
 			Velocity.Z = FMath::Max(Velocity.Z, JumpZVelocity);
            Velocity.X = WallJumpForwardVector.Y * JumpZVelocity;
            Velocity.Y = WallJumpForwardVector.X * JumpZVelocity;
            SetMovementMode(MOVE_Falling);
			//TODO Proof this flag is set correctly
			IsWallJump = false;
			return true;
		}
	}
	
	else if ( CharacterOwner && CharacterOwner->CanJump() )
	{
		// Don't jump if we can't move up/down.
		if (!bConstrainToPlane || FMath::Abs(PlaneConstraintNormal.Z) != 1.f)
		{
			Velocity.Z = FMath::Max(Velocity.Z, JumpZVelocity);
			SetMovementMode(MOVE_Falling);
			return true;
		}
	}
	
	return false;
}
