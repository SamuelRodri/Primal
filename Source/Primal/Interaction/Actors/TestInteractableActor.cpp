#include "TestInteractableActor.h"

void ATestInteractableActor::Interact_Implementation(AActor* Interactor)
{
	bIsActive = !bIsActive;
	
	
	if (bIsActive)
	{
		SetActorScale3D(FVector(1.5f));
	}
	else
	{
		SetActorScale3D(FVector(1.0f));
	}
}

bool ATestInteractableActor::CanInteract_Implementation(AActor* Interactor) const
{
	return true;
}
