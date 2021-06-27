

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

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FVector WallJumpForwardVector;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FTimerHandle WallJumpResetTimerHandle;

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	bool DoWallJump(bool bReplayingMoves);
	
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	void ResetWallJump();

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	int32 MaxCountWallJumps = 3;

	UPROPERTY(BlueprintReadOnly)
	int32 CurrentCountWallJumps = 0; 

	UFUNCTION()
	void ReactOnCharacterLandedDelegate(const FHitResult& Hit);
};
