// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/BoxComponent.h"
#include "Components/DecalComponent.h"
#include "GameFramework/Actor.h"
#include "FPSExtractionZone.generated.h"

UCLASS()
class FPSGAME_API AFPSExtractionZone : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AFPSExtractionZone();

protected:
	UPROPERTY(VisibleAnywhere, Category="Components")
	UBoxComponent* OverlapComp;

	UPROPERTY(VisibleAnywhere, Category="Components")
	UDecalComponent* DecalComp;

	UFUNCTION()
	void HandleOverlap(UPrimitiveComponent* OnComponentBeginOverlap,
	                   AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep,
	                   const FHitResult& SweepResult);

	UPROPERTY(EditDefaultsOnly, Category="Sounds")
	USoundBase* ObjectiveMissingSound;
};
