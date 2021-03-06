// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PaperCharacter.h"
#include "Personagem.generated.h"

/**
 * 
 */
UCLASS()
class JOGO2D_API APersonagem : public APaperCharacter
{
	GENERATED_BODY()
	
public:

	APersonagem();

	virtual void BeginPlay() override;

	virtual void SetupPlayerInputComponent(class UInputComponent*
		PlayerInputComponent) override;

	virtual void Tick(float DeltaSeconds) override;

	void UpdateFlipbook();

	UFUNCTION(BlueprintCallable, Category="Shoot")
	void StartFire();
	UFUNCTION(BlueprintCallable, Category = "Shoot")
	void StopFire();

	void AddGunToArray(class AGun* Gun);
	void LeftGun();
	int GetSelectedGun();
	TArray<class AGun*> GetGuns();


		

	UFUNCTION(BlueprintCallable, Category = "Jogador")
		int GetVidas();
	UFUNCTION(BlueprintCallable, Category = "Jogador")
		void SetVidas(int NewMoedas);

	UFUNCTION(BlueprintCallable, Category = "Jogador")
		int GetMoedas();
	UFUNCTION(BlueprintCallable, Category = "Jogador")
		void SetMoedas(int NewMoedas);


private:

	UPROPERTY(EditAnywhere)
		class USpringArmComponent* CameraBoom;

	UPROPERTY(EditAnywhere)
		class UCameraComponent* Camera;

	UPROPERTY(EditAnywhere)
		class UPaperFlipbook* Idle;

	UPROPERTY(EditAnywhere)
		class UPaperFlipbook* Walking;

	UPROPERTY(EditAnywhere)
		TArray<class AGun*> Guns;

	UPROPERTY(EditAnywhere)
		int SelectedGun;

	UPROPERTY(EditAnywhere)
	TSubclassOf<class UUserWidget> HUDMobile;

	void Move(float Value);

	void TouchStarted(const ETouchIndex::Type FinderIndex,
		const FVector Location);

	void TouchStopped(const ETouchIndex::Type FinderIndex,
		const FVector Location);

	void SwitchGun();

	int Moedas = 0;

	int Vidas;
	
};
