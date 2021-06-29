// 

#pragma once

#include "CoreMinimal.h"

#include "ExtCharacter.h"
#include "ExtCharacterMovementComponent.h"
#include "UObject/Object.h"
#include "ExtPlayerController.generated.h"





/**
 * 
 */
UCLASS()
class ADVANCEDLOCOMOTIONSYSTEMV_API AExtPlayerController : public APlayerController
{
	GENERATED_BODY()

	public:
	
	UPROPERTY(BlueprintReadOnly,VisibleAnywhere)
	AExtCharacter* ExtCharacter;
	
	void BeginPlay() override;
	
	void PlayerTick(float DeltaTime) override;

	//make some stuff like camera changes etc.
	UFUNCTION(BlueprintImplementableEvent)
	void OnTickWhileInWalljumpSate(float DeltaTime);
	
};
