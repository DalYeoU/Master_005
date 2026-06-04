#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "FoxDelegate.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FHealthDeadSignature, AController*, Instigator);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FHealthDamagedSignature, float, NewHealth, float, MaxHealth, float, HealthChange);

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class STUDY_005_MASTER_API UFoxDelegate : public UActorComponent
{
	GENERATED_BODY()

public:	
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UFoxDelegate();

	UPROPERTY(BlueprintAssignable)
	FHealthDeadSignature OnHealthDead;

	UPROPERTY(BlueprintAssignable)
	FHealthDamagedSignature OnHealthDamaged;

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float _MaxHealth;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	float _CurrentHealth;
	
	virtual void BeginPlay() override;

private:	
	UFUNCTION()
	void DamageTake(AActor* DamagedActor, float Damage, const UDamageType* DamageType, AController* Instigator, AActor* Causer);
	
	float ReduceHealth(float Amount);
	
	void CheckIsDead(AController* Instigator);
	
};
