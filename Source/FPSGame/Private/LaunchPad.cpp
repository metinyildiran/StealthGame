// Fill out your copyright notice in the Description page of Project Settings.


#include "LaunchPad.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/Character.h"

// Sets default values
ALaunchPad::ALaunchPad()
{
	LaunchPadBase = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("LaunchPadBase"));
	LaunchPadBase->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	LaunchPadBase->SetCollisionResponseToAllChannels(ECR_Overlap);
	RootComponent = LaunchPadBase;

	LaunchPad = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("LaunchPad"));
	LaunchPad->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	LaunchPad->SetupAttachment(LaunchPadBase);

	LaunchStrength = 1500.0f;
	LaunchPitchAngle = 35.0f;
}

void ALaunchPad::NotifyActorBeginOverlap(AActor* OtherActor)
{
	FRotator LaunchDirection = GetActorRotation();
	LaunchDirection.Pitch = LaunchPitchAngle;
	FVector LaunchVelocity = LaunchDirection.Vector() * LaunchStrength;

	ACharacter* Character = Cast<ACharacter>(OtherActor);
	if (Character)
	{
		Character->LaunchCharacter(LaunchVelocity, true, true);

		UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), LaunchPadEffect, GetActorLocation());
	}
}
