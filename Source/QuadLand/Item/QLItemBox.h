// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Item/QLItem.h"
#include "QLItemBox.generated.h"

UCLASS()
class QUADLAND_API AQLItemBox : public AQLItem
{
	GENERATED_BODY()
	
public:
	// Sets default values for this actor's properties
	AQLItemBox();

	class USkeletalMeshComponent* GetMesh() const { return Mesh; }

	void InitPosition();
	uint8 bIsInitialized : 1;
protected:

	UPROPERTY(VisibleAnywhere, Category = Collision)
	TObjectPtr<class UBoxComponent> Trigger;

	UPROPERTY(VisibleAnywhere, Category = Mesh)
	TObjectPtr<class USkeletalMeshComponent> Mesh;
	
	
	UPROPERTY(EditAnywhere,Category = Position)
	float Radius; //��ǥ���� cos, sin

	UPROPERTY(EditAnywhere, Category = Power)
	float Power; //��ǥ���� cos, sin

	UFUNCTION()
	void OnActorOverlap(AActor* SelfActor, AActor* OtherActor, FVector NormalImpulse, const FHitResult& Hit);
};
