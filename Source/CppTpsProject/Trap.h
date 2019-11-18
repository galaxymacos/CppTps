// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Trap.generated.h"

UCLASS()
class CPPTPSPROJECT_API ATrap : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATrap();

	UPROPERTY(VisibleAnywhere)
	class UBoxComponent* BoxComponent;

	UPROPERTY(EditAnywhere)
	UParticleSystem* Explosion;

	UPROPERTY(EditAnywhere)
	FVector Impulse;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;


	
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;


	void NotifyActorBeginOverlap(AActor* OtherActor) override;
	
};


