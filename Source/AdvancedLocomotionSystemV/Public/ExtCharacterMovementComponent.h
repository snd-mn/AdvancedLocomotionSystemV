

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
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool IsWallJump;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FVector WallJumpForwardVector;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FTimerHandle WallJumpResetTimerHandle;

	bool DoJump(bool bReplayingMoves) override;
	
	
};
