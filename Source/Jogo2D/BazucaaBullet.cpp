// Fill out your copyright notice in the Description page of Project Settings.

#include "BazucaaBullet.h"

void ABazucaaBullet::BeginPlay() {
	Super::BeginPlay();

	Damage = FMath::RandRange(5, 20);
}


