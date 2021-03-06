// Fill out your copyright notice in the Description page of Project Settings.

#include "Coin.h"
#include "Components/SphereComponent.h"
#include "PaperFlipbookComponent.h"
#include "Personagem.h"
#include "NextLevel.h"
#include "Runtime/CoreUObject/Public/UObject/ConstructorHelpers.h"


// Sets default values
ACoin::ACoin()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	CollisionComp = CreateDefaultSubobject<USphereComponent>
		(TEXT("CollisionComp"));
	CollisionComp->bGenerateOverlapEvents = true;
	CollisionComp->SetCollisionProfileName("OverlapAllDynamic");
	CollisionComp->OnComponentBeginOverlap.AddDynamic(
		this, &ACoin::OnOverlapBegin);
	RootComponent = CollisionComp;

	Sprite = CreateDefaultSubobject<UPaperFlipbookComponent>
		(TEXT("Sprite"));
	Sprite->SetupAttachment(CollisionComp);

	ConstructorHelpers::FObjectFinder<UBlueprint> NextLevel(TEXT("Blueprint'/Game/Blueprints/MyNextLevel.MyNextLevel'"));
	if (NextLevel.Object) {
		MyItemBlueprint = (UClass*)NextLevel.Object->GeneratedClass;
	}


}

// Called when the game starts or when spawned
void ACoin::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACoin::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ACoin::OnOverlapBegin(UPrimitiveComponent * OverlappedComp,
	AActor * OtherActor, UPrimitiveComponent * OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult)
{

	if (OtherActor != nullptr &&
		OtherActor->IsA(APersonagem::StaticClass())) {

		APersonagem* Jogador = Cast<APersonagem>(OtherActor);

		Jogador->SetMoedas(Jogador->GetMoedas() + 1);

		if (Jogador->GetMoedas() == 5) {
			UWorld* World = GetWorld();
			if (World) {
				FActorSpawnParameters SpawnParameters;
				FVector Location(6050.0f, 0.0f, 620.0f);
				World->SpawnActor<ANextLevel>(MyItemBlueprint, Location,
					FRotator::ZeroRotator, SpawnParameters);

			}
			
		}
		Destroy();
	}
}

