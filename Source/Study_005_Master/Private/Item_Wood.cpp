#include "Item_Wood.h"
#include "Kismet/GameplayStatics.h"
#include "Particles/ParticleSystem.h"

void AItem_Wood::OnFireDetected(float Temperature, FVector HitLocation)
{
	if (FireEffect)
	{
		UGameplayStatics::SpawnEmitterAttached(
			FireEffect,
			GetRootComponent(),
			NAME_None,
			FVector::ZeroVector,
			FRotator::ZeroRotator,
			EAttachLocation::KeepRelativeOffset,
			true
		);
	}
}
