// Fill out your copyright notice in the Description page of Project Settings.

#include "Enemy.h"
#include "PaperFlipbookComponent.h"
#include "Components/BoxComponent.h"
#include "Personagem.h"

// Sets default values
AEnemy::AEnemy()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	CollisionComp = CreateDefaultSubobject<UBoxComponent>(TEXT("CollisionComp"));
	CollisionComp->bGenerateOverlapEvents = true;
	CollisionComp->SetCollisionProfileName("OverlapAllDynamic");
	CollisionComp->OnComponentBeginOverlap.AddDynamic(this, &AEnemy::OnOverlapBegin);
	RootComponent = CollisionComp;

	Sprite = CreateDefaultSubobject <UPaperFlipbookComponent>(TEXT("Sprite"));
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
UBoxComponent * AEnemy::GetCollisionComp()
{
	return CollisionComp;
}

void AEnemy::OnOverlapBegin(UPrimitiveComponent * OverlappedComp, AActor * OtherActor, UPrimitiveComponent * OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult)
{

	if (OtherActor != nullptr && OtherActor->IsA(APersonagem::StaticClass())) {
		APersonagem* Personagem = Cast<APersonagem>(OtherActor);

		APersonagem* Jogador = Cast<APersonagem>(OtherActor);

		Jogador->SetVidas(Jogador->GetVidas() - 1);

		Destroy();

	}

}


