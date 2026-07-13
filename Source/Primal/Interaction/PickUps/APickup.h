#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Interaction/Interfaces/Interactable.h"
#include "APickup.generated.h"

UCLASS(Abstract)
class APickup : public AActor, public IInteractable
{
	GENERATED_BODY()
	
public:
	
	virtual void Interact_Implementation(AActor* Interactor) override;
	virtual bool CanInteract_Implementation(AActor* Interactor) const override;
	virtual FText GetInteractionText_Implementation() const override;
	
	
protected:
	
	virtual void PickUp();
};