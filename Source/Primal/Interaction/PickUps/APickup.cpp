#include "APickup.h"

void APickup::Interact_Implementation(AActor* Interactor)
{
	PickUp();
}

FText APickup::GetInteractionText_Implementation() const
{
	return FText::FromString(TEXT("[E] Pickup"));
}

void APickup::PickUp()
{
	UE_LOG(LogTemp, Warning, TEXT("PickUp APickup"));
	
	Destroy();
}

bool APickup::CanInteract_Implementation(AActor* Interactor) const
{
	return true;
}
