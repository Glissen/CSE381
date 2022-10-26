// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "MyProjectWolfie.generated.h"

UCLASS()
class MYPROJECT_API AMyProjectWolfie : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AMyProjectWolfie();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	//// Wolfie collision component.
	UPROPERTY(VisibleDefaultsOnly, Category = Capsule)
	UCapsuleComponent* CollisionComponent;
	// Projectile mesh
	UPROPERTY(VisibleDefaultsOnly, Category = Character)
	USkeletalMeshComponent* WolfieSkeletalMeshComponent;

	// Function that is called when something hits wolfie
	UFUNCTION()
	void OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, FVector NormalImpulse, const FHitResult& Hit);

	UFUNCTION()
	virtual float TakeDamage(float DamageAmount, struct FDamageEvent const& DamageEvent, class AController* EventInstigator, AActor* DamageCauser);

	UFUNCTION()
	void OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	bool Ball = false;
};
