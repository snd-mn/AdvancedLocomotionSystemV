


#include "ExtCharacterMovementComponent.h"

#include "ExtBlueprintLibrary.h"
#include "GameFramework/Character.h"

#include "ExtCharacter.h"
#include "Components/CapsuleComponent.h"

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
	CurrentCountWallJumps  = 0;
	WallJumpDuration = 0.0f;
	IsWallJumping = false;
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

  			//Prediction stuff
  			const UObject* WorldContextObject = GetWorld();
  			FPredictProjectilePathParams& PredictParams = *new FPredictProjectilePathParams();
  			PredictParams.StartLocation = CharacterOwner->GetTransform().GetLocation();
  			PredictParams.LaunchVelocity = Velocity;
  			TArray<AActor*> ActorsToIgnore = TArray<AActor*>();
  			ActorsToIgnore.Add(CharacterOwner);
  			PredictParams.ActorsToIgnore = ActorsToIgnore;
			PredictParams.bTraceWithCollision = true;
  			PredictParams.MaxSimTime = 2.0f;
  			PredictParams.bTraceWithChannel = true;
  			PredictParams.TraceChannel = ECC_WorldDynamic;
  			PredictParams.SimFrequency = 40.0f;
  			PredictParams.DrawDebugType = EDrawDebugTrace::ForDuration;
  			PredictParams.DrawDebugTime = 1.0f;
  			FPredictProjectilePathResult& PredictResult = *new FPredictProjectilePathResult();
  			const float CapsuleHalfHeight = CharacterOwner->GetCapsuleComponent()->GetScaledCapsuleHalfHeight(); 
  			const float CapsuleRadius = CharacterOwner->GetCapsuleComponent()->GetScaledCapsuleRadius();
  			UExtBlueprintLibrary::PredictProjectilePathForCapsule(WorldContextObject, PredictParams, PredictResult,CapsuleHalfHeight, CapsuleRadius);

  			WallJumpDuration = PredictResult.LastTraceDestination.Time;
  			
  			IsWallJumping = true;

  			
  			//cleanup
  			delete &PredictParams;
  			delete &PredictResult;
  			
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