// 


#include "ExtCharacter.h"

#include "ExtCharacterMovementComponent.h"
#include "Components/ArrowComponent.h"
#include "Components/CapsuleComponent.h"
#include "Engine/CollisionProfile.h"

FName AExtCharacter::MeshComponentName(TEXT("CharacterMesh"));
FName AExtCharacter::CharacterMovementComponentName(TEXT("ExtCharMoveComp"));
FName AExtCharacter::CapsuleComponentName(TEXT("CollisionCylinder"));

// Sets default values
AExtCharacter::AExtCharacter(const FObjectInitializer& ObjectInitializer)
: Super(ObjectInitializer.SetDefaultSubobjectClass<UExtCharacterMovementComponent>(ACharacter::CharacterMovementComponentName))
{
// 	// Structure to hold one-time initialization
// 	struct FConstructorStatics
// 	{
// 		FName ID_Characters;
// 		FText NAME_Characters;
// 		FConstructorStatics()
// 			: ID_Characters(TEXT("Characters"))
// 			, NAME_Characters(NSLOCTEXT("SpriteCategory", "Characters", "Characters"))
// 		{
// 		}
// 	};
// 	static FConstructorStatics ConstructorStatics;
//
// 	// Character rotation only changes in Yaw, to prevent the capsule from changing orientation.
// 	// Ask the Controller for the full rotation if desired (ie for aiming).
// 	bUseControllerRotationPitch = false;
// 	bUseControllerRotationRoll = false;
// 	bUseControllerRotationYaw = true;
// 	UCapsuleComponent* parentCapsulePtr = GetCapsuleComponent();
// 	UCapsuleComponent* newCapsulePtr = CreateDefaultSubobject<UCapsuleComponent>(AExtCharacter::CapsuleComponentName);
// 	UCapsuleComponent* swapCapsulePtr = parentCapsulePtr;
// 	parentCapsulePtr = newCapsulePtr;
// 	//TODO not sure which is the right one.
// 	// swapCapsulePtr->DestroyComponent();
// 	// swapCapsulePtr->MarkPendingKill();
//
// 	newCapsulePtr->InitCapsuleSize(34.0f, 88.0f);
// 	newCapsulePtr->SetCollisionProfileName(UCollisionProfile::Pawn_ProfileName);
//
// 	newCapsulePtr->CanCharacterStepUpOn = ECB_No;
// 	newCapsulePtr->SetShouldUpdatePhysicsVolume(true);
// 	newCapsulePtr->SetCanEverAffectNavigation(false);
// 	newCapsulePtr->bDynamicObstacle = true;
// 	RootComponent = newCapsulePtr;
//
// 	bClientCheckEncroachmentOnNetUpdate = true;
// 	JumpKeyHoldTime = 0.0f;
// 	JumpMaxHoldTime = 0.0f;
//     JumpMaxCount = 1;
//     JumpCurrentCount = 0;
// 	JumpCurrentCountPreJump = 0;
//     bWasJumping = false;
//
// 	AnimRootMotionTranslationScale = 1.0f;
//
// #if WITH_EDITORONLY_DATA
// 	UArrowComponent* parentArrowComponent = GetArrowComponent();
// 	UArrowComponent* newArrayComponent = CreateEditorOnlyDefaultSubobject<UArrowComponent>(TEXT("Arrow123"));
// 	UArrowComponent* swapArrayComponent = parentArrowComponent;
// 	parentArrowComponent = newArrayComponent;
// 	//todo remove swap 
// 	if (newArrayComponent)
// 	{
// 		newArrayComponent->ArrowColor = FColor(150, 200, 255);
// 		newArrayComponent->bTreatAsASprite = true;
// 		newArrayComponent->SpriteInfo.Category = ConstructorStatics.ID_Characters;
// 		newArrayComponent->SpriteInfo.DisplayName = ConstructorStatics.NAME_Characters;
// 		newArrayComponent->SetupAttachment(newCapsulePtr);
// 		newArrayComponent->bIsScreenSizeScaled = true;
// 	}
// #endif // WITH_EDITORONLY_DATA
//
// 	UCharacterMovementComponent* parentCharMovementComp = this->GetCharacterMovement();
// 	UCharacterMovementComponent* newCharmovementComp =  CreateSubobject<UExtCharacterMovementComponent>(AExtCharacter::CharacterMovementComponentName);
// 	UCharacterMovementComponent* swapCharMovementComp = parentCharMovementComp;
// 	parentCharMovementComp = newCharmovementComp;
// 	// swapCharMovementComp->DestroyComponent();
// 	// swapCharMovementComp->MarkPendingKill();
// 	
// 	if (newCharmovementComp)
// 	{
// 		newCharmovementComp->UpdatedComponent = newCapsulePtr;
// 		CrouchedEyeHeight = newCharmovementComp->CrouchedHalfHeight * 0.80f;
// 	}
//
// 	USkeletalMeshComponent* parentMesh = this->GetMesh();
// 	USkeletalMeshComponent* newMesh = CreateOptionalDefaultSubobject<USkeletalMeshComponent>(AExtCharacter::MeshComponentName); 
// 	USkeletalMeshComponent* swapMesh = parentMesh;
// 	parentMesh = newMesh;
// 	// swapMesh->DestroyComponent();
// 	// swapMesh->MarkPendingKill();
// 	
// 	if (newMesh)
// 	{
// 		newMesh->AlwaysLoadOnClient = true;
// 		newMesh->AlwaysLoadOnServer = true;
// 		newMesh->bOwnerNoSee = false;
// 		newMesh->VisibilityBasedAnimTickOption = EVisibilityBasedAnimTickOption::AlwaysTickPose;
// 		newMesh->bCastDynamicShadow = true;
// 		newMesh->bAffectDynamicIndirectLighting = true;
// 		newMesh->PrimaryComponentTick.TickGroup = TG_PrePhysics;
// 		newMesh->SetupAttachment(newCapsulePtr);
// 		static FName MeshCollisionProfileName(TEXT("CharacterMesh"));
// 		newMesh->SetCollisionProfileName(MeshCollisionProfileName);
// 		newMesh->SetGenerateOverlapEvents(false);
// 		newMesh->SetCanEverAffectNavigation(false);
// 	}
//
// 	BaseRotationOffset = FQuat::Identity;
}

// Called when the game starts or when spawned
void AExtCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AExtCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void AExtCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

void AExtCharacter::PostInitializeComponents()
{
	Super::PostInitializeComponents();
	ExtCharacterMovement = Cast<UExtCharacterMovementComponent>(GetCharacterMovement());
}

