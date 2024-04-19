// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/QLPlayerHpBarWidget.h"
#include "Components/ProgressBar.h"
UQLPlayerHpBarWidget::UQLPlayerHpBarWidget(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	MaxHP = -1;
}

void UQLPlayerHpBarWidget::UpdateHPPercentage(float InHP, float InMaxHP)
{
	MaxHP = InMaxHP;
	CurrentHP = InHP;

	if (HP)
	{
		HP->SetPercent(CurrentHP / MaxHP);
	}
}

void UQLPlayerHpBarWidget::NativeConstruct()
{
	Super::NativeConstruct();

	HP = Cast<UProgressBar>(GetWidgetFromName(TEXT("HP")));
}