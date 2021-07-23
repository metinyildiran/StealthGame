// Fill out your copyright notice in the Description page of Project Settings.

#include "BlackHole.h"

#include <iostream>
#include <string>

// Sets default values
ABlackHole::ABlackHole()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SphereComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BlackHoleMesh"));
	SphereComp->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	RootComponent = SphereComp;

	InnerSphereComponent = CreateDefaultSubobject<USphereComponent>(TEXT("SmallCollision"));
	InnerSphereComponent->SetupAttachment(SphereComp);

	OuterSphereComponent = CreateDefaultSubobject<USphereComponent>(TEXT("BigCollision"));
	OuterSphereComponent->AttachToComponent(SphereComp, FAttachmentTransformRules::KeepRelativeTransform);

	TArray<UPrimitiveComponent*> Result;
	OuterSphereComponent->GetOverlappingComponents(Result);

}

// Called when the game starts or when spawned
void ABlackHole::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void ABlackHole::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}
