

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Kismet/GameplayStaticsTypes.h"

#include "ExtBlueprintLibrary.generated.h"

UCLASS()
class ADVANCEDLOCOMOTIONSYSTEMV_API UExtBlueprintLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	
public:	
	//ProjectileRadius of FPredictProjectilePathParams gets ignored, use the capsule values instead
	UFUNCTION(BlueprintCallable, Category = "Game", DisplayName="Predict Projectile Path (Advanced) For Capsule", meta = (WorldContext = "WorldContextObject"))
	static bool PredictProjectilePathForCapsule(const UObject* WorldContextObject, const FPredictProjectilePathParams& PredictParams, FPredictProjectilePathResult& PredictResult, float CapsuleHalfHeight, float CapsuleRadius);

};
