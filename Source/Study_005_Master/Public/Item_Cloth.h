#pragma once

#include "CoreMinimal.h"
#include "ItemBase.h"
#include "FoxInterface.h"
#include "Item_Cloth.generated.h"

UCLASS()
class STUDY_005_MASTER_API AItem_Cloth : public AItemBase, public IFoxInterface
{
	GENERATED_BODY()
public:
	virtual void OnFireDetected(float Temperature, FVector HitLocation) override;
	
protected:
	UPROPERTY(EditAnywhere, Category = "Effects")
	class UParticleSystem* FireEffect;
};
