#include "ADoor.h"

void ADoor::Interact_Implementation(AActor* Interactor)
{
	if (bIsOpen)
	{
		Close();
	}
	else
	{
		Open();
	}
}

bool ADoor::CanInteract_Implementation(AActor* Interactor) const
{
	return true;
}


void ADoor::Open()
{
	bIsOpen = true;
	PlayOpenAnimation();
}

void ADoor::Close()
{
	bIsOpen = false;
	PlayCloseAnimation();
}
