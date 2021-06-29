// 


#include "ExtPlayerController.h"


//keep in mind the initialization states of the components
void AExtPlayerController::BeginPlay()
{
	Super::BeginPlay();
	if(IsValid(GetPawn()))
	{
		UE_LOG(LogTemp, Warning, TEXT("Error in AExtPlayerController::ReceivePossess, got class %s"), *GetPawn()->GetClass()->GetName())
		ExtCharacter = Cast<AExtCharacter>(GetPawn());
		if(!IsValid(ExtCharacter))
		{
			UE_LOG(LogTemp, Warning, TEXT("Error in AExtPlayerController::ReceivePossess"))
		}
	}
}

void AExtPlayerController::PlayerTick(float DeltaTime)
{
	Super::PlayerTick(DeltaTime);

	if(ExtCharacter->ExtCharacterMovement->IsWallJump)
	{
		UE_LOG(LogTemp, Warning, TEXT("Got walljump in AExtPlayerController"))
		OnTickWhileInWalljumpSate();
	}
	
}
