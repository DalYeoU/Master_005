#include "FoxHUDWidget.h"
#include "Components/ProgressBar.h"
#include "FoxDelegate.h"
#include "Components/TextBlock.h"

void UFoxHUDWidget::NativeConstruct()
{
	Super::NativeConstruct();
	
	InitializeDefaultUI();
	BindToPlayerCharacter();
}

// UI 기본 수치를 채우는 헬퍼 함수
void UFoxHUDWidget::InitializeDefaultUI()
{
	if (HPProgressBar != nullptr && HPText != nullptr)
	{
		HPProgressBar->SetPercent(1.0f);
		HPText->SetText(FText::FromString(TEXT("100 / 100")));
	}
}

// 캐릭터의 체력 델리게이트에 바인딩하는 헬퍼 함수
void UFoxHUDWidget::BindToPlayerCharacter()
{
	APawn* OwningPawn = GetOwningPlayerPawn();
	if (OwningPawn != nullptr)
	{
		UFoxDelegate* HealthComp = OwningPawn->FindComponentByClass<UFoxDelegate>();
		if (HealthComp != nullptr)
		{
			HealthComp->OnHealthDamaged.AddDynamic(this, &UFoxHUDWidget::UpdateHPBar);
		}
	}
}

void UFoxHUDWidget::UpdateHPBar(float NewHealth, float MaxHealth, float HealthChange)
{
	if (HPProgressBar != nullptr && MaxHealth > 0.0f)
	{
		float HealthPercent = NewHealth / MaxHealth;

		HPProgressBar->SetPercent(HealthPercent);
		
		if (HPText != nullptr)
		{
			HPText->SetText(FText::FromString(FString::Printf(TEXT("%.0f / %.0f"), NewHealth, MaxHealth)));
		}
	}
}