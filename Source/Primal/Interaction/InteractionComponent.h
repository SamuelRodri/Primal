#pragma once

#include "Components/ActorComponent.h"
#include "InteractionComponent.generated.h"

UCLASS()
class UInteractionComponent : public UActorComponent
{
	GENERATED_BODY()
	
public:
	
	UInteractionComponent();
	
	void TryInteract() const;
	
protected:
	
	virtual void TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	
private:
	
	void UpdateCurrentInteractable();
	
	UPROPERTY()
	AActor* CurrentInteractableFocused;
	
	UFUNCTION(BlueprintPure)
	AActor* GetCurrentInteractable() const;
	
	UFUNCTION(BlueprintPure)
	FText GetCurrentInteractableText() const;
};
