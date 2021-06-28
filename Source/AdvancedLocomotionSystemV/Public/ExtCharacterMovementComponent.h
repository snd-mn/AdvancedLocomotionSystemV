

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
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float ReflectWithYaw = 45.0f;
	UPROPERTY()
	FRotator leftRotator;
	UPROPERTY()
	FRotator rightRotator;
	
};
