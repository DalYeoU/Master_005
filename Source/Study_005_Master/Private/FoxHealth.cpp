#include "FoxHealth.h"
#include "FoxDelegate.h"

AFoxHealth::AFoxHealth()
{
	HealthComponent = CreateDefaultSubobject<UFoxDelegate>(TEXT("HealthComponent"));
}

void AFoxHealth::BeginPlay()
{
	Super::BeginPlay();
	
	if (HealthComponent)
	{
		HealthComponent->OnHealthDead.AddDynamic(this, &AFoxHealth::HandleActorDead);
	}
}

void AFoxHealth::HandleActorDead(AController* InstigatorController)
{
	UE_LOG(LogTemp, Warning, TEXT("TestMyActor가 사망했습니다!"));
}
