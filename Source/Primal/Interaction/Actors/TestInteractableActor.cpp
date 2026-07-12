#include "TestInteractableActor.h"

void ATestInteractableActor::Interact_Implementation(AActor* Interactor)
{
	UE_LOG(LogTemp, Warning, TEXT("Interactuando con TestInteractableActor"));
}

bool ATestInteractableActor::CanInteract_Implementation(AActor* Interactor) const
{
	return true;
}
