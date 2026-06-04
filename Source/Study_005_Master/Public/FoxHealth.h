#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "FoxHealth.generated.h"

UCLASS()
class STUDY_005_MASTER_API AFoxHealth : public AActor
{
	GENERATED_BODY()
	
public:	
	AFoxHealth();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	TObjectPtr<class UFoxDelegate> HealthComponent;
protected:
	virtual void BeginPlay() override;
	void HandleActorDead(class AController* InstigatorController);
};
