#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Interaction/Interfaces/Interactable.h"
#include "ADoor.generated.h"

UCLASS(Abstract)
class ADoor : public AActor, public IInteractable
{
	GENERATED_BODY()
	
public:
	
	virtual void Interact_Implementation(AActor* Interactor) override;
	virtual bool CanInteract_Implementation(AActor* Interactor) const override;

protected:
	
	virtual void Open();
	virtual void Close();
	
	UFUNCTION(BlueprintImplementableEvent, Category="Door")
	void PlayOpenAnimation();
	
	UFUNCTION(BlueprintImplementableEvent, Category="Door")
	void PlayCloseAnimation();
	
	bool bIsOpen = false;
	
};