// Fill out your copyright notice in the Description page of Project Settings.


#include "MyProjectWolfie.h"
#include "Components/CapsuleComponent.h"

// Sets default values
AMyProjectWolfie::AMyProjectWolfie()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	//this->OnActorBeginOverlap.__Internal_AddDynamic(this, &AMyProjectWolfie::OnOverlapBegin)

	UCapsuleComponent* Capsule = this->GetCapsuleComponent();
	/*if (CollisionComponent == NULL && (CollisionComponent = Capsule) != NULL)
	{
		CollisionComponent->BodyInstance.SetCollisionProfileName(TEXT("Capsule"));
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Green, TEXT("Hiiiii!"));
		CollisionComponent->OnComponentHit.AddDynamic(this, &AMyProjectWolfie::OnHit);
		RootComponent = CollisionComponent;
	}*/
	//if (!CollisionComponent) 
	//{
	//	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Green, FString::FromInt(Capsule->GetScaledCapsuleHalfHeight()));
	//	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Green, FString::FromInt(Capsule->GetScaledCapsuleRadius()));
	//	CollisionComponent = CreateDefaultSubobject<UCapsuleComponent>(TEXT("CapsuleComponent"));
	//	//static ConstructorHelpers::FObjectFinder<UPhysicsAsset>Mesh(TEXT("PhysicsAsset'/Game/StarterContent/Mesh/wolfie_PhysicsAsset.wolfie_PhysicsAsset'"));
	//	CollisionComponent->BodyInstance.SetCollisionProfileName(TEXT("Capsule"));
	//	// Event called when component hits something.
	//	CollisionComponent->OnComponentHit.AddDynamic(this, &AMyProjectWolfie::OnHit);
	//	CollisionComponent->InitCapsuleSize(Capsule->GetScaledCapsuleRadius() / 2, Capsule->GetScaledCapsuleHalfHeight() * 2);
	//	// Set the sphere's collision radius.
	//	//CollisionComponent->InitSphereRadius(15.0f);
	//	// Set the root component to be the collision component.
	//	RootComponent = CollisionComponent;
	//	/*if (Mesh.Succeeded())
	//	{
	//		CollisionComponent->SetStaticMesh(Mesh.Object);
	//	
	//	}*/
	//}
	/*if (!WolfieSkeletalMeshComponent) 
	{
		WolfieSkeletalMeshComponent = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("WolfieSkeletalMeshComponent"));
		static ConstructorHelpers::FObjectFinder<USkeletalMesh>SkeletalMesh(TEXT("SkeletalMesh'/Game/StarterContent/Mesh/wolfie.wolfie'"));
		if (SkeletalMesh.Succeeded())
		{
			GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Green, TEXT("Hiiiii!"));
			WolfieSkeletalMeshComponent->SetSkeletalMesh(SkeletalMesh.Object);
			WolfieSkeletalMeshComponent->OnComponentHit.AddDynamic(this, &AMyProjectWolfie::OnHit);
		}
	}*/

	//GetMesh()->OnComponentHit.AddDynamic(this, &AMyProjectWolfie::OnHit);
	Ball = false;
}

// Called when the game starts or when spawned
void AMyProjectWolfie::BeginPlay()
{
	Super::BeginPlay();
	Direction1 = FVector(rand() % 360, rand() % 360, 0);
	Direction2 = rand() % 2 == 1 ? 1 : -1;
	
}

// Called every frame
void AMyProjectWolfie::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	Movement += DeltaTime;
	//Direction1 = FVector(rand() % 360, rand() % 360, 0);
	if (Movement > 1)
	{
		Direction1 = FVector(rand() % 360, rand() % 360, 0);
		Direction2 = rand() % 2 == 1 ? 1 : -1;
		//GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, Direction1.ToString());
		Movement = 0;
	}
	FVector location = GetActorLocation();
	if (location.Component(0) < 3210 || ((Direction1.Component(0) < 0 && Direction2 > 0) || (Direction1.Component(0) > 0 && Direction2 < 0)))
		AddMovementInput(Direction1.GetUnsafeNormal(), Direction2 * 0.5);

	if (Ball)
	{
		Fire();
		Ball = false;
	}
}

// Called to bind functionality to input
void AMyProjectWolfie::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void AMyProjectWolfie::Fire()
{
	// Attempt to fire a projectile.
	if (ProjectileClass && Ball)
	{
		//GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Green, TEXT("FIRETOHELL!"));
		// Get the camera transform.
		/*FVector CameraLocation;
		FRotator CameraRotation;
		GetActorEyesViewPoint(CameraLocation, CameraRotation);*/

		// Set MuzzleOffset to spawn projectiles slightly in front of the camera.
		//MuzzleOffset.Set(100.0f, 0.0f, 0.0f);

		// Transform MuzzleOffset from camera space to world space.
		//FVector MuzzleLocation = CameraLocation + FTransform(CameraRotation).TransformVector(MuzzleOffset);

		// Skew the aim to be slightly upwards.
		//FRotator MuzzleRotation = CameraRotation;
		//MuzzleRotation.Pitch += 0.0f;
		FVector WolfieLocation = GetActorLocation() + FVector(150, 0, 0);
		if (GetWorld()) {
			if (GetWorld()->GetFirstPlayerController()) {
				if (GetWorld()->GetFirstPlayerController()->GetPawn()) {
					FVector PlayerLocation = GetWorld()->GetFirstPlayerController()->GetPawn()->GetActorLocation();

					FRotator WolfieRotation = (PlayerLocation - WolfieLocation).GetUnsafeNormal().Rotation();


					UWorld* World = GetWorld();
					/*GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Yellow, WolfieLocation.ToString());
					GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Yellow, PlayerLocation.ToString());
					GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Yellow, WolfieRotation.ToString());*/
					if (World)
					{
						FActorSpawnParameters SpawnParams;
						SpawnParams.Owner = this;
						SpawnParams.Instigator = GetInstigator();

						// Spawn the projectile at the muzzle.
						AMyProjectProjectile* Projectile = World->SpawnActor<AMyProjectProjectile>(ProjectileClass, WolfieLocation, WolfieRotation, SpawnParams);
						if (Projectile)
						{
							Projectile->SetDamage(3);
							// Set the projectile's initial trajectory.
							FVector LaunchDirection = WolfieRotation.Vector();
							Projectile->FireInDirection(LaunchDirection);
						}
					}
				}
			}
		}
	}
}

void AMyProjectWolfie::OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, FVector NormalImpulse, const FHitResult& Hit)
{
	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, TEXT("Hiiiii!"));
}

float AMyProjectWolfie::TakeDamage(float DamageAmount, FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser)
{

	if (DamageAmount == 1 && !Ball) 
	{
		//GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Green, TEXT("TAKEDAMAGE"));
		Ball = true;
		DamageCauser->Destroy();
		return 0.0f;
	}
	else if (DamageAmount == 2)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Green, FString::FromInt(DamageAmount));
		Destroy();
		return 0.0f;
	}
	return 0.0f;
}

void AMyProjectWolfie::OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) 
{
	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Green, TEXT("Hiiiii!"));
}
