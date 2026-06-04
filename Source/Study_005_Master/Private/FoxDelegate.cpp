#include "FoxDelegate.h"
#include "GameFramework/Character.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/CharacterMovementComponent.h"

UFoxDelegate::UFoxDelegate()
{
	PrimaryComponentTick.bCanEverTick = true;

	_MaxHealth = 100.f;
}

void UFoxDelegate::BeginPlay()
{
	Super::BeginPlay();

	_CurrentHealth = _MaxHealth;
	GetOwner()->OnTakeAnyDamage.AddDynamic(this, &UFoxDelegate::DamageTake);
}

void UFoxDelegate::DamageTake(AActor* DamagedActor, float Damage, const UDamageType* DamageType, AController* Instigator, AActor* Causer)
{
	float FinalDamage = ReduceHealth(Damage);
	OnHealthDamaged.Broadcast(_CurrentHealth, _MaxHealth, FinalDamage);
	CheckIsDead(Instigator);
}

// 체력을 안전하게 감소시키고, 실제 최종 입은 대미지 양을 반환합니다.
float UFoxDelegate::ReduceHealth(float Amount)
{
	float FinalDamage = FMath::Min(Amount, _CurrentHealth);
	_CurrentHealth -= FinalDamage;
	
	return FinalDamage;
}

// 체력이 0인지 검사하고 사망 처리를 트리거합니다.
void UFoxDelegate::CheckIsDead(AController* Instigator)
{
	if (_CurrentHealth == 0.f)
	{
		OnHealthDead.Broadcast(Instigator);
		ACharacter* OwnerCharacter = Cast<ACharacter>(GetOwner());
		
		OwnerCharacter->GetCapsuleComponent()->SetCollisionEnabled(ECollisionEnabled::NoCollision);
		OwnerCharacter->GetMesh()->SetCollisionProfileName(TEXT("Ragdoll"));
		OwnerCharacter->GetMesh()->SetSimulatePhysics(true);
		
		OwnerCharacter->GetCharacterMovement()->DisableMovement();
	}
}

void UFoxDelegate::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}
