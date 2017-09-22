// Fill out your copyright notice in the Description page of Project Settings.

#include "Enemy.h"
#include "PaperFlipbookComponent.h"
#include "Components/BoxComponent.h"

// Sets default values
AEnemy::AEnemy()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	CollisionComp = CreateDefaultSubobject
		<UBoxComponent>(TEXT("CollisionComp"));
	CollisionComp->SetCollisionProfileName("OverlapAllDynamic");
	RootComponent = CollisionComp;

	Sprite = CreateDefaultSubobject
		<UPaperFlipbookComponent>(TEXT("Sprite"));
	Sprite->SetCollisionProfileName("NoCollision");
	Sprite->SetupAttachment(RootComponent);

}

// Called when the game starts or when spawned
void AEnemy::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AEnemy::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

