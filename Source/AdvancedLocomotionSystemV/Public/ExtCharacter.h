// 

#pragma once

#include "CoreMinimal.h"

#include "ExtCharacterMovementComponent.h"
#include "GameFramework/Character.h"
#include "ExtCharacter.generated.h"

UCLASS()
class ADVANCEDLOCOMOTIONSYSTEMV_API AExtCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AExtCharacter(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

	virtual void PostInitializeComponents() override;
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	/** Movement component used for movement logic in various movement modes (walking, falling, etc), containing relevant settings and functions to control movement. */
	UPROPERTY(Category=Character, VisibleAnywhere, BlueprintReadOnly, meta=(AllowPrivateAccess = "true"))
	UExtCharacterMovementComponent* ExtCharacterMovement;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	/** Name of the MeshComponent. Use this name if you want to prevent creation of the component (with ObjectInitializer.DoNotCreateDefaultSubobject). */
	static FName MeshComponentName;

	/** Name of the CharacterMovement component. Use this name if you want to use a different class (with ObjectInitializer.SetDefaultSubobjectClass). */
	static FName CharacterMovementComponentName;

	/** Name of the CapsuleComponent. */
	static FName CapsuleComponentName;

	// // UFUNCTION(BlueprintCallable, Category=Character)
	// bool CanJump() const;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	FVector GetJumpVector();

private:

};
