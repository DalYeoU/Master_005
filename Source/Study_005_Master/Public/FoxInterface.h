#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "FoxInterface.generated.h"

UINTERFACE(MinimalAPI)
class UFoxInterface : public UInterface
{
	GENERATED_BODY()
};

class STUDY_005_MASTER_API IFoxInterface
{
	GENERATED_BODY()

public:
	virtual void OnFireDetected(float Temperature, FVector HitLocation) = 0;
};
