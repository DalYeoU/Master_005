#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "FoxTorchlight.generated.h"

UCLASS()
class STUDY_005_MASTER_API AFoxTorchlight : public AActor
{
	GENERATED_BODY()
	
public:	
	UPROPERTY(EditAnywhere)
	TArray<TWeakObjectPtr<AActor>> Items;
	
protected:
	virtual void BeginPlay() override;
	
};
