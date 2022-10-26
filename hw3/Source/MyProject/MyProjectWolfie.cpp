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

}

// Called when the game starts or when spawned
void AMyProjectWolfie::BeginPlay()
{
	Super::BeginPlay();

	
}

// Called every frame
void AMyProjectWolfie::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AMyProjectWolfie::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void AMyProjectWolfie::OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, FVector NormalImpulse, const FHitResult& Hit)
{
	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, TEXT("Hiiiii!"));
}

float AMyProjectWolfie::TakeDamage(float DamageAmount, FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser)
{
	if (DamageAmount == 0.0f && !Ball) 
	{
		Ball = true;
		DamageCauser->Destroy();
		return 0.0f;
	}
	else if (DamageAmount == 1.0f)
	{
		Destroy();
		return 0.0f;
	}
	return 0.0f;
}

void AMyProjectWolfie::OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) 
{
	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Green, TEXT("Hiiiii!"));
}
