// Fill out your copyright notice in the Description page of Project Settings.


#include "Trap.h"
#include "Components/BoxComponent.h"
#include "Engine.h"

// Sets default values
ATrap::ATrap()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	BoxComponent = CreateDefaultSubobject<UBoxComponent>(TEXT("Box"));
	SetRootComponent(BoxComponent);
	
}

// Called when the game starts or when spawned
void ATrap::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATrap::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ATrap::NotifyActorBeginOverlap(AActor* OtherActor)
{
	GEngine->AddOnScreenDebugMessage(-1, 5, FColor::Emerald, TEXT("Actor hits the collider"));
	UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), Explosion, GetActorLocation());
	const auto character = Cast<ACharacter>(OtherActor);
	if(character != nullptr)
	{
		character->GetCharacterMovement()->AddImpulse(Impulse);
	}

}
