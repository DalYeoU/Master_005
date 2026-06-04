#include "FoxTorchlight.h"
#include "FoxInterface.h"

void AFoxTorchlight::BeginPlay()
{
	Super::BeginPlay();
	
	for (const TWeakObjectPtr<AActor>& Item : Items)
	{
		IFoxInterface* foxInterface = Cast<IFoxInterface>(Item.Get());
		
		if (foxInterface)
		{
			foxInterface->OnFireDetected(100.0f, FVector::ZeroVector);
		}
	}
}

