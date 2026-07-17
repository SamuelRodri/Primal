#include "InteractionComponent.h"

#include "AssetTypeCategories.h"
#include "Primal.h"
#include "Camera/CameraComponent.h"
#include "Engine/World.h"
#include "GameFramework/Actor.h"
#include "Interfaces/Interactable.h"
#include "Logging/LogMacros.h"


UInteractionComponent::UInteractionComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
}

void UInteractionComponent::TickComponent(float DeltaTime, enum ELevelTick TickType,
                                          FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	
	UpdateCurrentInteractable();
}


void UInteractionComponent::TryInteract() const
{
	UE_LOG(LogPrimal, Warning, TEXT("TryInteract called"));

	if (CurrentInteractableFocused &&
		CurrentInteractableFocused->Implements<UInteractable>())
	{
		UE_LOG(LogPrimal, Warning, TEXT("Interacting with: %s"), *CurrentInteractableFocused->GetName());

		IInteractable::Execute_Interact(CurrentInteractableFocused, GetOwner());
	}
}


void UInteractionComponent::UpdateCurrentInteractable()
{
	AActor* OwnerActor = GetOwner();

	if (!IsValid(OwnerActor))
	{
		return;
	}

	UCameraComponent* OwnerCamera = OwnerActor->FindComponentByClass<UCameraComponent>();

	if (!IsValid(OwnerCamera))
	{
		CurrentInteractableFocused = nullptr;
		return;
	}

	const FVector Start = OwnerCamera->GetComponentLocation();
	const FVector End = Start + OwnerCamera->GetForwardVector() * 500.0f;

	FHitResult Hit;

	FCollisionQueryParams QueryParams;
	QueryParams.AddIgnoredActor(GetOwner());

	const bool bHit = GetWorld()->LineTraceSingleByChannel(
		Hit,
		Start,
		End,
		ECC_Visibility,
		QueryParams
	);

	AActor* HitActor = bHit ? Hit.GetActor() : nullptr;

	if (IsValid(HitActor) && HitActor->Implements<UInteractable>())
	{
		DrawDebugLine(
			GetWorld(),
			Start,
			bHit ? Hit.ImpactPoint : End,
			bHit ? FColor::Green : FColor::Red,
			false,
			0.0f,
			0,
			1.0f
		);

		CurrentInteractableFocused = HitActor;
	}
	else
	{
		CurrentInteractableFocused = nullptr;
	}
}

AActor* UInteractionComponent::GetCurrentInteractable() const
{
	return CurrentInteractableFocused;
}

FText UInteractionComponent::GetCurrentInteractableText() const
{
	if (!IsValid(CurrentInteractableFocused))
	{
		UE_LOG(
			LogPrimal,
			Warning,
			TEXT("CurrentInteractableFocused es null")
		);

		return FText::GetEmpty();
	}

	const FText Result =
		IInteractable::Execute_GetInteractionText(
			CurrentInteractableFocused
		);
	
	return Result;
}