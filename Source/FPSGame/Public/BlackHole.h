// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "Components/SphereComponent.h"
#include "GameFramework/Actor.h"
#include "BlackHole.generated.h"

UCLASS()
class FPSGAME_API ABlackHole : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ABlackHole();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, Category="Mesh")
	UStaticMeshComponent* SphereComp;

	UPROPERTY(VisibleAnywhere, Category="Collider")
	USphereComponent* InnerSphereComponent;

	UPROPERTY(VisibleAnywhere, Category="Collider")
	USphereComponent* OuterSphereComponent;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
};
