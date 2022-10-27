// Fill out your copyright notice in the Description page of Project Settings.


#include "MyProjectProjectile.h"
#include "MyProjectWolfie.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/DamageType.h"

// Sets default values
AMyProjectProjectile::AMyProjectProjectile()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	if (!Damage)
		Damage = 1;

	if (!RootComponent)
	{
		RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("ProjectileSceneComponent"));
	}
	if (!CollisionComponent)
	{
		// Use a sphere as a simple collision representation.
		CollisionComponent = CreateDefaultSubobject<USphereComponent>(TEXT("SphereComponent"));
		// Set the sphere's collision profile name to "Projectile".
		CollisionComponent->BodyInstance.SetCollisionProfileName(TEXT("Projectile"));
		// Event called when component hits something.
		//CollisionComponent->OnComponentHit.AddDynamic(this, &AMyProjectProjectile::OnHit);
		CollisionComponent->OnComponentBeginOverlap.AddDynamic(this, &AMyProjectProjectile::OnOverlapBegin);
		// Set the sphere's collision radius.
		CollisionComponent->InitSphereRadius(15.0f);
		// Set the root component to be the collision component.
		RootComponent = CollisionComponent;
	}

	if (!ProjectileMovementComponent)
	{
		// Use this component to drive this projectile's movement.
		ProjectileMovementComponent = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("ProjectileMovementComponent"));
		ProjectileMovementComponent->SetUpdatedComponent(CollisionComponent);
		ProjectileMovementComponent->InitialSpeed = 1500.0f;
		ProjectileMovementComponent->MaxSpeed = 2500.0f;
		ProjectileMovementComponent->bRotationFollowsVelocity = true;
		ProjectileMovementComponent->bShouldBounce = true;
		ProjectileMovementComponent->Bounciness = 1.0f;
		ProjectileMovementComponent->ProjectileGravityScale = 1.0f;
	}

	if (!ProjectileMeshComponent)
	{
		ProjectileMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ProjectileMeshComponent"));
		static ConstructorHelpers::FObjectFinder<UStaticMesh>Mesh(TEXT("StaticMesh'/Game/Sphere.Sphere'"));
		if (Mesh.Succeeded())
		{
			ProjectileMeshComponent->SetStaticMesh(Mesh.Object);
		}

		static ConstructorHelpers::FObjectFinder<UMaterial>Material(TEXT("Material'/Game/SphereMaterial.SphereMaterial'"));
		if (Material.Succeeded())
		{
			ProjectileMaterialInstance = UMaterialInstanceDynamic::Create(Material.Object, ProjectileMeshComponent);
		}
		ProjectileMeshComponent->SetMaterial(0, ProjectileMaterialInstance);
		ProjectileMeshComponent->SetRelativeScale3D(FVector(0.09f, 0.09f, 0.09f));
		ProjectileMeshComponent->SetupAttachment(RootComponent);
	}

	bGenerateOverlapEventsDuringLevelStreaming = true;

	// Delete the projectile after 3 seconds.
	// InitialLifeSpan = 3.0f;

}

// Called to set the projectile damage
void AMyProjectProjectile::SetDamage(int Dmg)
{
	Damage = Dmg;
}

// Called when the game starts or when spawned
void AMyProjectProjectile::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMyProjectProjectile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Function that initializes the projectile's velocity in the shoot direction.
void AMyProjectProjectile::FireInDirection(const FVector& ShootDirection)
{
	ProjectileMovementComponent->Velocity = ShootDirection * ProjectileMovementComponent->InitialSpeed;
}

// Function that is called when the projectile hits something.
//void AMyProjectProjectile::OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, FVector NormalImpulse, const FHitResult& Hit)
//{
//	//GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Green, TEXT("Hiiiii!"));
//	//if (OtherActor != NULL &&)
//	//	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Green, "Bad");
//	///*else
//	//	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Green, OtherActor->GetActorLabel());*/
//	if (OtherActor != this && OtherActor != NULL && !OtherActor->GetActorLabel().Contains("BP_MyProjectWolfie", ESearchCase::CaseSensitive, ESearchDir::FromStart) && OtherActor->GetActorLabel() != "TestChar")
//	{
//		if (!OtherActor->GetActorLabel().Contains("Floor") && !OtherActor->GetActorLabel().Contains("MyProjectProjectile"))
//			GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, OtherActor->GetActorLabel()); 
//		SetDamage(1);
//	}
//	else if (OtherActor != this && OtherActor != NULL && (OtherActor->GetActorLabel().Contains("BP_MyProjectWolfie", ESearchCase::CaseSensitive, ESearchDir::FromStart) || OtherActor->GetActorLabel() == "TestChar"))
//	{
//		//OtherComponent->AddImpulseAtLocation(ProjectileMovementComponent->Velocity * 100.0f, Hit.ImpactPoint);
//		//AMyProjectWolfie* Wolfie = (AMyProjectWolfie *)Hit.GetActor();
//		AActor* Wolfie = Hit.GetActor();
//		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, Wolfie->GetActorLabel());
//		/*GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, this->GetVelocity().ToString());
//		if (this->GetVelocity().Component(2) != 0)
//		{
//			GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Black, TEXT("NOOOOO"));
//			UGameplayStatics::ApplyDamage(Wolfie, 1, this->GetInstigatorController(), this, UDamageType::StaticClass());
//		}
//		else
//		{*/
//		UGameplayStatics::ApplyDamage(Wolfie, 2, this->GetInstigatorController(), this, UDamageType::StaticClass());
//		SetDamage(1);
//		//Destroy();
//		//Destroy();
//		/*}*/
//
//		//UGameplayStatics::ApplyDamage(Wolfie, 1, )
//		/*if (temp->test == 123)
//			GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, TEXT("YAYYYY"));*/
//	}
//}

void AMyProjectProjectile::OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	//GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Green, TEXT("Hiiiii!"));
	//if (OtherActor != this && OtherActor != NULL && !OtherActor->GetActorLabel().Contains("BP_MyProjectWolfie", ESearchCase::CaseSensitive, ESearchDir::FromStart) && OtherActor->GetActorLabel() != "TestChar")
	//{
	/*if (!OtherActor->GetActorLabel().Contains("Floor") && !OtherActor->GetActorLabel().Contains("MyProjectProjectile"))
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, OtherActor->GetActorLabel());*/
	
	//}
	//else 
	if (OtherActor != this && OtherActor != NULL && (OtherActor->GetActorLabel().Contains("BP_MyProjectWolfie", ESearchCase::CaseSensitive, ESearchDir::FromStart) 
		|| OtherActor->GetActorLabel().Contains("MyProjectTrueWolfie", ESearchCase::CaseSensitive, ESearchDir::FromStart) 
		|| OtherActor->GetActorLabel() == "TestChar"))
	{
		//OtherComponent->AddImpulseAtLocation(ProjectileMovementComponent->Velocity * 100.0f, Hit.ImpactPoint);
		//AMyProjectWolfie* Wolfie = (AMyProjectWolfie *)Hit.GetActor();
		AActor* Wolfie = SweepResult.GetActor();
		/*GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, this->GetVelocity().ToString());
		if (this->GetVelocity().Component(2) != 0)
		{
			GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Black, TEXT("NOOOOO"));
			UGameplayStatics::ApplyDamage(Wolfie, 1, this->GetInstigatorController(), this, UDamageType::StaticClass());
		}
		else
		{*/
		UGameplayStatics::ApplyDamage(Wolfie, Damage, this->GetInstigatorController(), this, UDamageType::StaticClass());
		//Destroy();
		//Destroy();
		/*}*/

		//UGameplayStatics::ApplyDamage(Wolfie, 1, )
		/*if (temp->test == 123)
			GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, TEXT("YAYYYY"));*/
	}
	if (OtherActor != this && OtherActor != NULL)
		SetDamage(1);
}



