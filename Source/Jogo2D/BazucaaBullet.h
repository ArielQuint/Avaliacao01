// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Bullet.h"
#include "BazucaaBullet.generated.h"

/**
 * 
 */
UCLASS()
class JOGO2D_API ABazucaaBullet : public ABullet
{
	GENERATED_BODY()
	
		virtual void BeginPlay() override;
	
	
};
