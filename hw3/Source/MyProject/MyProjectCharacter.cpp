// Fill out your copyright notice in the Description page of Project Settings.


#include "MyProjectCharacter.h"
#include "Components/CapsuleComponent.h"

// Sets default values
AMyProjectCharacter::AMyProjectCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Ball = false;
	bGenerateOverlapEventsDuringLevelStreaming = true;

	Cap = this->GetCapsuleComponent();
	if (Cap) 
	{
		Cap->OnComponentHit.AddDynamic(this, &AMyProjectCharacter::OnHit);
	}
}

// Called when the game starts or when spawned
void AMyProjectCharacter::BeginPlay()
{
	Super::BeginPlay();

	check(GEngine != nullptr);

	// Display a debug message for five seconds. 
	// The -1 "Key" value argument prevents the message from being updated or refreshed.
	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, TEXT("We are using FPSCharacter."));
	
}

// Called every frame
void AMyProjectCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (SpawnedBalls < 15) {
		DeltaSecond += DeltaTime;
		if (DeltaSecond > SpawnInterval) {
			DeltaSecond -= SpawnInterval;
			SpawnBalls();
		}
	}
}

// Called to bind functionality to input
void AMyProjectCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	// Set up "movement" bindings.
	PlayerInputComponent->BindAxis("MoveForward", this, &AMyProjectCharacter::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &AMyProjectCharacter::MoveRight);
	// Set up "look" bindings.
	PlayerInputComponent->BindAxis("Turn", this, &AMyProjectCharacter::AddControllerYawInput);
	PlayerInputComponent->BindAxis("LookUp", this, &AMyProjectCharacter::AddControllerPitchInput);

	PlayerInputComponent->BindAction("Fire", IE_Pressed, this, &AMyProjectCharacter::Fire);

}

void AMyProjectCharacter::MoveForward(float Value)
{
	// Find out which way is "forward" and record that the player wants to move that way.
	FVector Direction = FRotationMatrix(Controller->GetControlRotation()).GetScaledAxis(EAxis::X);
	FVector location = GetActorLocation();
	if (location.Component(0) > 3210 || ((Direction.Component(0) > 0 && Value > 0) || (Direction.Component(0) < 0 && Value < 0)))
		AddMovementInput(Direction, Value);
}

void AMyProjectCharacter::MoveRight(float Value)
{
	// Find out which way is "right" and record that the player wants to move that way.
	FVector Direction = FRotationMatrix(Controller->GetControlRotation()).GetScaledAxis(EAxis::Y);
	FVector location = GetActorLocation();
	if (location.Component(0) > 3210 || ((Direction.Component(0) > 0 && Value > 0) || (Direction.Component(0) < 0 && Value < 0)))
		AddMovementInput(Direction, Value);
}

float AMyProjectCharacter::TakeDamage(float DamageAmount, FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser)
{
	if (DamageAmount != 3.0f && !Ball)
	{
		Ball = true;
		DamageCauser->Destroy();
		return 0.0f;
	}
	else if (DamageAmount == 3.0f)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, "DEAD");
		Destroy();
		return 0.0f;
	}
	return 0.0f;
}

void AMyProjectCharacter::Fire()
{
	// Attempt to fire a projectile.
	if (ProjectileClass && Ball)
	{
		// Get the camera transform.
		FVector CameraLocation;
		FRotator CameraRotation;
		GetActorEyesViewPoint(CameraLocation, CameraRotation);

		// Set MuzzleOffset to spawn projectiles slightly in front of the camera.
		MuzzleOffset.Set(100.0f, 0.0f, 0.0f);

		// Transform MuzzleOffset from camera space to world space.
		FVector MuzzleLocation = CameraLocation + FTransform(CameraRotation).TransformVector(MuzzleOffset);

		// Skew the aim to be slightly upwards.
		FRotator MuzzleRotation = CameraRotation;
		MuzzleRotation.Pitch += 0.0f;

		UWorld* World = GetWorld();
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Yellow, TEXT("FIRE!"));
		if (World)
		{
			FActorSpawnParameters SpawnParams;
			SpawnParams.Owner = this;
			SpawnParams.Instigator = GetInstigator();

			// Spawn the projectile at the muzzle.
			AMyProjectProjectile* Projectile = World->SpawnActor<AMyProjectProjectile>(ProjectileClass, MuzzleLocation, MuzzleRotation, SpawnParams);
			if (Projectile)
			{
				Projectile->SetDamage(2);
				// Set the projectile's initial trajectory.
				FVector LaunchDirection = MuzzleRotation.Vector();
				Projectile->FireInDirection(LaunchDirection);
				Ball = false;
			}
		}
	}
}


void AMyProjectCharacter::SpawnBalls()
{
	// Attempt to fire a projectile.
	if (ProjectileClass)
	{
		// Get the camera transform.
		FVector SpawnLocation1 = FVector(4000.0f, 650.0f, 400.0f);
		FVector SpawnLocation2 = FVector(2600.0f, 1200.0f, 400.0f);
		FRotator SpawnRotation1 = FRotator(0.0f, 0.0f, 0.0f);
		SpawnRotation1.Pitch += 45.0f;
		FRotator SpawnRotation2 = FRotator(0.0f, 0.0f, 0.0f);
		SpawnRotation2.Pitch += 135.0f;

		UWorld* World = GetWorld();
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Green, TEXT("Spawn balls!"));
		if (World)
		{
			FActorSpawnParameters SpawnParams;
			SpawnParams.Owner = this;
			SpawnParams.Instigator = GetInstigator();

			// Spawn the projectile at the muzzle.
			AMyProjectProjectile* Projectile1 = World->SpawnActor<AMyProjectProjectile>(ProjectileClass, SpawnLocation1, SpawnRotation1, SpawnParams);
			AMyProjectProjectile* Projectile2 = World->SpawnActor<AMyProjectProjectile>(ProjectileClass, SpawnLocation2, SpawnRotation2, SpawnParams);
			if (Projectile1 && Projectile2)
			{
				// Set the projectile's initial trajectory.
				FVector LaunchDirection1 = SpawnRotation1.Vector();
				FVector LaunchDirection2 = SpawnRotation2.Vector();
				Projectile1->FireInDirection(LaunchDirection1);
				Projectile2->FireInDirection(LaunchDirection2);
				SpawnedBalls++;
			}
		}
	}
}

 //Function that is called when the projectile hits something.
void AMyProjectCharacter::OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, FVector NormalImpulse, const FHitResult& Hit)
{
	//GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Green, TEXT("Hiiiii!"));
	//if (OtherActor != NULL &&)
	//	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Green, "Bad");
	///*else
	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Green, OtherActor->GetActorLabel());
	//if (OtherActor != this && OtherActor != NULL && !OtherActor->GetActorLabel().Contains("BP_MyProjectWolfie", ESearchCase::CaseSensitive, ESearchDir::FromStart) && OtherActor->GetActorLabel() != "TestChar")
	//{
	//	if (!OtherActor->GetActorLabel().Contains("Floor") && !OtherActor->GetActorLabel().Contains("MyProjectProjectile"))
	//		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, OtherActor->GetActorLabel()); 
	//	SetDamage(1);
	//}
	//else if (OtherActor != this && OtherActor != NULL && (OtherActor->GetActorLabel().Contains("BP_MyProjectWolfie", ESearchCase::CaseSensitive, ESearchDir::FromStart) || OtherActor->GetActorLabel() == "TestChar"))
	//{
	//	//OtherComponent->AddImpulseAtLocation(ProjectileMovementComponent->Velocity * 100.0f, Hit.ImpactPoint);
	//	//AMyProjectWolfie* Wolfie = (AMyProjectWolfie *)Hit.GetActor();
	//	AActor* Wolfie = Hit.GetActor();
	//	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, Wolfie->GetActorLabel());
	//	/*GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, this->GetVelocity().ToString());
	//	if (this->GetVelocity().Component(2) != 0)
	//	{
	//		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Black, TEXT("NOOOOO"));
	//		UGameplayStatics::ApplyDamage(Wolfie, 1, this->GetInstigatorController(), this, UDamageType::StaticClass());
	//	}
	//	else
	//	{*/
	//	UGameplayStatics::ApplyDamage(Wolfie, 2, this->GetInstigatorController(), this, UDamageType::StaticClass());
	//	SetDamage(1);
	//	//Destroy();
	//	//Destroy();
	//	/*}*/

	//	//UGameplayStatics::ApplyDamage(Wolfie, 1, )
	//	/*if (temp->test == 123)
	//		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, TEXT("YAYYYY"));*/
	//}
}