// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "LaunchPad.generated.h"


UCLASS()
class FPSGAME_API ALaunchPad : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ALaunchPad();

	virtual void NotifyActorBeginOverlap(AActor* OtherActor) override;

protected:
	UPROPERTY(BlueprintReadWrite, Category="LaunchPad")
	UStaticMeshComponent* LaunchPadBase;

	UPROPERTY(BlueprintReadWrite, Category="LaunchPad")
	UStaticMeshComponent* LaunchPad;

	UPROPERTY(EditInstanceOnly, Category="LaunchPad")
	float LaunchStrength;

	UPROPERTY(EditInstanceOnly, Category="LaunchPad")
	float LaunchPitchAngle;

	UPROPERTY(EditDefaultsOnly, Category="LaunchPad")
	UParticleSystem* LaunchPadEffect;
};
