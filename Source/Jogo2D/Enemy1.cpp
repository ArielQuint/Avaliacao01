// Fill out your copyright notice in the Description page of Project Settings.

#include "Enemy1.h"
#include "Personagem.h"
#include "Components/BoxComponent.h"



AEnemy1::AEnemy1() {
	CollisionComp->OnComponentBeginOverlap.AddDynamic(this, &AEnemy1::OnOverlapBegin);
}


void AEnemy1::Move() {
	
}

void AEnemy1::OnOverlapBegin(UPrimitiveComponent * OverlappedComp, AActor * OtherActor, UPrimitiveComponent * OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult)
{

	if (OtherActor != nullptr && OtherActor->IsA(APersonagem::StaticClass())) {
		APersonagem* Personagem = Cast<APersonagem>(OtherActor);
		Personagem->Life--;
	}

}