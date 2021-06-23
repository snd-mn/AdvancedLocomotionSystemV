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

// 	/** The main skeletal mesh associated with this Character (optional sub-object). */
// 	UPROPERTY(Category=Character, VisibleAnywhere, BlueprintReadOnly, meta=(AllowPrivateAccess = "true"))
// 	USkeletalMeshComponent* Mesh;
//
	/** Movement component used for movement logic in various movement modes (walking, falling, etc), containing relevant settings and functions to control movement. */
	UPROPERTY(Category=Character, VisibleAnywhere, BlueprintReadOnly, meta=(AllowPrivateAccess = "true"))
	UExtCharacterMovementComponent* ExtCharacterMovement;
//
// 	/** The CapsuleComponent being used for movement collision (by CharacterMovement). Always treated as being vertically aligned in simple collision check functions. */
// 	UPROPERTY(Category=Character, VisibleAnywhere, BlueprintReadOnly, meta=(AllowPrivateAccess = "true"))
// 	UCapsuleComponent* CapsuleComponent;
//
// #if WITH_EDITORONLY_DATA
// 	/** Component shown in the editor only to indicate character facing */
// 	UPROPERTY()
// 	UArrowComponent* ArrowComponent;
// #endif

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

private:
	// /** The main skeletal mesh associated with this Character (optional sub-object). */
	// UPROPERTY(Category=Character, VisibleAnywhere, BlueprintReadOnly, meta=(AllowPrivateAccess = "true"))
	// USkeletalMeshComponent* Mesh;
	//
	// /** Movement component used for movement logic in various movement modes (walking, falling, etc), containing relevant settings and functions to control movement. */
	// UPROPERTY(Category=Character, VisibleAnywhere, BlueprintReadOnly, meta=(AllowPrivateAccess = "true"))
	// UCharacterMovementComponent* CharacterMovement;
	//
	// /** The CapsuleComponent being used for movement collision (by CharacterMovement). Always treated as being vertically aligned in simple collision check functions. */
	// UPROPERTY(Category=Character, VisibleAnywhere, BlueprintReadOnly, meta=(AllowPrivateAccess = "true"))
	// UCapsuleComponent* CapsuleComponent;

// #if WITH_EDITORONLY_DATA
// 	/** Component shown in the editor only to indicate character facing */
// 	UPROPERTY()
// 	UArrowComponent* ArrowComponent;
// #endif
};
