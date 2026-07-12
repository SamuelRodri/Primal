#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Interaction/Interfaces/Interactable.h"
#include "TestInteractableActor.generated.h"

UCLASS()
class ATestInteractableActor : public AActor, public IInteractable
{
	GENERATED_BODY()
	
public:
	
	virtual void Interact_Implementation(AActor* Interactor) override;
	
	virtual bool CanInteract_Implementation(AActor* Interactor) const override;
};



