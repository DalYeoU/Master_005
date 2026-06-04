#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "FoxHUDWidget.generated.h"

UCLASS()
class STUDY_005_MASTER_API UFoxHUDWidget : public UUserWidget
{
	GENERATED_BODY()

protected:
	UPROPERTY(meta = (BindWidget))
	TObjectPtr<class UProgressBar> HPProgressBar;
	
	UPROPERTY(meta = (BindWidget))
	TObjectPtr<class UTextBlock> HPText;

	virtual void NativeConstruct() override;

	UFUNCTION()
	void UpdateHPBar(float NewHealth, float MaxHealth, float HealthChange);
	
private:
	void InitializeDefaultUI();

	void BindToPlayerCharacter();
};