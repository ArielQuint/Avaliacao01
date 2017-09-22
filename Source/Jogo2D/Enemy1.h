// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Enemy.h"
#include "Enemy1.generated.h"

/**
 * 
 */
UCLASS()
class JOGO2D_API AEnemy1 : public AEnemy
{
	GENERATED_BODY()
	
public:
	AEnemy1();

	UPROPERTY(BlueprintReadWrite, VisibleAnywhere)
		int Life = 3;
	
	UFUNCTION(BlueprintCallable, Category = "Move")
		void Move();

	UFUNCTION()
		void OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

};
