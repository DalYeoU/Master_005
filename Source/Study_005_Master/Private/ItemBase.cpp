#include "ItemBase.h"
#include "Kismet/GameplayStatics.h"
#include "FoxDelegate.h"
#include "GameFramework/Character.h"

AItemBase::AItemBase()
{

}

void AItemBase::BeginPlay()
{
	Super::BeginPlay();
	
	ACharacter* PlayerCharacter = UGameplayStatics::GetPlayerCharacter(GetWorld(), 0);
	if (PlayerCharacter)
	{
		UFoxDelegate* HealthComp = PlayerCharacter->FindComponentByClass<UFoxDelegate>();
		
		if (HealthComp)
		{
			HealthComp->OnHealthDead.AddDynamic(this, &AItemBase::PlayerDeathReceive);
		}
		else
		{
			UE_LOG(LogTemp, Warning, TEXT("플레이어 캐릭터에 FoxDelegate가 없습니다!"))
		}
	}
	
}

void AItemBase::PlayerDeathReceive(AController* InstigatorController)
{
	UE_LOG(LogTemp, Warning, TEXT("플레이어 캐릭터가 사망했습니다!"));

	Destroy();
}