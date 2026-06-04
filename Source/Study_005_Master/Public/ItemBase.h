#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ItemBase.generated.h"

UCLASS()
class STUDY_005_MASTER_API AItemBase : public AActor
{
	GENERATED_BODY()
	
public:	
	AItemBase();

protected:
	virtual void BeginPlay() override;
	
	UFUNCTION()
	void PlayerDeathReceive(AController* InstigatorController);

};
