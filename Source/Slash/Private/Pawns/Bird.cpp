// Fill out your copyright notice in the Description page of Project Settings.


#include "Pawns/Bird.h"
#include "Components/CapsuleComponent.h"
#include "Components/SkeletalMeshComponent.h"
#include "Components/InputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"

// Sets default values
ABird::ABird()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Capsule = CreateDefaultSubobject<UCapsuleComponent>( TEXT( "Capsule" ) );
	Capsule->SetCapsuleHalfHeight( 20.f );
	Capsule->SetCapsuleRadius( 15.f );
	SetRootComponent(Capsule);

	BirdMesh = CreateDefaultSubobject<USkeletalMeshComponent>( TEXT( "BirdMesh" ) );
	BirdMesh->SetupAttachment( GetRootComponent( ) );

	AutoPossessPlayer = EAutoReceiveInput::Player0;
}

// Called when the game starts or when spawned
void ABird::BeginPlay()
{
	Super::BeginPlay();

	APlayerController* PlayerController = Cast<APlayerController>( GetController() );
	if ( PlayerController )
	{
		UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>( PlayerController->GetLocalPlayer( ) );
		if ( Subsystem )
		{
			Subsystem->AddMappingContext( BirdMappingContext, 0 );
		}
	}
	
}

void ABird::Move( const FInputActionValue& Value )
{
	const bool CurrentValue = Value.Get<bool>( );
	if ( CurrentValue )
	{
		UE_LOG( LogTemp, Warning, TEXT("IA_Move triggered") );
	}
}

// Called every frame
void ABird::Tick(float DeltaTime)
{ 
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ABird::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	if ( UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>( PlayerInputComponent ) )
	{
		EnhancedInputComponent->BindAction( MoveAction, ETriggerEvent::Triggered, this, &ABird::Move );
	}

}

