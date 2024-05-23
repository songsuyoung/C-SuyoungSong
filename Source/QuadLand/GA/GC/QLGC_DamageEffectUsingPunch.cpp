// Fill out your copyright notice in the Description page of Project Settings.


#include "GA/GC/QLGC_DamageEffectUsingPunch.h"
#include "Kismet/GameplayStatics.h"
#include "Sound/SoundCue.h"

UQLGC_DamageEffectUsingPunch::UQLGC_DamageEffectUsingPunch()
{
	static ConstructorHelpers::FObjectFinder<USoundCue> SoundRef(TEXT("/Script/Engine.SoundWave'/Game/Movies/Punch.Punch'"));
	if (SoundRef.Object)
	{
		Sound = SoundRef.Object;
	}
}

bool UQLGC_DamageEffectUsingPunch::OnExecute_Implementation(AActor* Target, const FGameplayCueParameters& Parameters) const
{

	UE_LOG(LogTemp, Log, TEXT("1"));
	if (Parameters.EffectContext.GetHitResult())
	{

		UE_LOG(LogTemp, Log, TEXT("2"));
		UGameplayStatics::SpawnSoundAtLocation(Target, Sound, Parameters.Location, FRotator::ZeroRotator);

	}
	return false;
}
