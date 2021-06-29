

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "ExtCharacterMovementComponent.generated.h"

/**
 * 
 */
UCLASS()
class ADVANCEDLOCOMOTIONSYSTEMV_API UExtCharacterMovementComponent : public UCharacterMovementComponent
{
	GENERATED_BODY()

	public:

	UExtCharacterMovementComponent(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

	virtual void SetUpdatedComponent(USceneComponent* NewUpdatedComponent) override;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool IsWallJump;

	//The world normal ob the wall to jump off
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FVector WallNormal;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FTimerHandle WallJumpResetTimerHandle;

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	bool DoWallJump(bool bReplayingMoves);
	
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	void ResetWallJump();

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	int32 MaxCountWallJumps = 3;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	int32 CurrentCountWallJumps = 0; 

	UFUNCTION()
	void ReactOnCharacterLandedDelegate(const FHitResult& Hit);

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	FVector GetJumpVector();

	//TODO just positiv number by blueprint plz
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float DotAngleForRightAngleJumps = 0.3f;
	UPROPERTY()
	float DotAngleForRightAngleJumpsNeg;
	
	//TODO use the rotator instead and add a vector for the amount of velocity which should be added in this direction
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float ReflectWithYaw = 45.0f;
	UPROPERTY()
	FRotator leftRotator;
	UPROPERTY()
	FRotator rightRotator;

	// shows how long the WallJump take to finish (predicted next hit event)
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float WallJumpDuration;
	//TODO do i realy need two bools for this shit?
	UPROPERTY(BlueprintReadOnly)
	bool IsWallJumping;
	
	
	
};
