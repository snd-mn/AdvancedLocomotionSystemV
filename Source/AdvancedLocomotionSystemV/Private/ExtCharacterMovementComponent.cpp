


#include "ExtCharacterMovementComponent.h"

#include "GameFramework/Character.h"

#include "ExtCharacter.h"

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
		DotAngleForRightAngleJumpsNeg = DotAngleForRightAngleJumps * -1.0f;
		ReflectWithYaw = ReflectWithYaw * -1.0f;

		rightRotator = FRotator(0.0f,ReflectWithYaw,0.0f);
		leftRotator = FRotator(0.0f,ReflectWithYaw * -1.0f,0.0f);
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
		//todo as member
		// AExtCharacter* extChar = Cast<AExtCharacter>(CharacterOwner);
		
		FVector JumpVector = GetJumpVector();
  		if (!bConstrainToPlane || FMath::Abs(PlaneConstraintNormal.Z) != 1.f)
		{
  			Velocity.X = JumpVector.X * JumpZVelocity;
  			Velocity.Y = JumpVector.Y * JumpZVelocity;
  			Velocity.Z = JumpZVelocity;
			
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
	WallJumpResetTimerHandle.Invalidate();
}

FVector UExtCharacterMovementComponent::GetJumpVector_Implementation()
{
	float DotRightAndWall = FVector::DotProduct(CharacterOwner->GetActorRightVector(), WallNormal);
	
	if(DotRightAndWall > DotAngleForRightAngleJumpsNeg &&
		DotRightAndWall < DotAngleForRightAngleJumps)
	{
		//the middle lalala
		return WallNormal;
	}
	else if(DotRightAndWall < DotAngleForRightAngleJumpsNeg)
	{
		//left
		return leftRotator.RotateVector(WallNormal);
	}
	else
	{
		//right
		return FVector(rightRotator.RotateVector(WallNormal));	
	}
}