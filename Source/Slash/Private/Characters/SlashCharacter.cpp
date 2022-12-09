// Fill out your copyright notice in the Description page of Project Settings.


#include "Characters/SlashCharacter.h"

#include "Components/InputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"

// Sets default values
ASlashCharacter::ASlashCharacter()
{
	PrimaryActorTick.bCanEverTick = true;
 
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>( TEXT( "CameraBoom" ) );
	CameraBoom->SetupAttachment( GetRootComponent( ) );
	CameraBoom->TargetArmLength = 300.f;

	ViewCamera = CreateDefaultSubobject<UCameraComponent>( TEXT( "ViewCamera" ) );
	ViewCamera->SetupAttachment( CameraBoom );
}

void ASlashCharacter::BeginPlay()
{
	Super::BeginPlay();
	
	APlayerController* PlayerController = Cast<APlayerController>( GetController( ) );
	if ( PlayerController )
	{
		UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>( PlayerController->GetLocalPlayer( ) );
		if ( Subsystem )
		{
			Subsystem->AddMappingContext( SlashContext, 0 );
		}
	}
}

void ASlashCharacter::Move( const FInputActionValue& Value )
{
	//if( ActionState != EActionState::EAS_Unoccupied ) return;

	const FVector2D MovementVector = Value.Get<FVector2D>( );

	const FRotator Rotation = Controller->GetControlRotation( );
	const FRotator YawRotation( 0.f, Rotation.Yaw, 0.f );

	const FVector ForwardDirection = FRotationMatrix( YawRotation ).GetUnitAxis( EAxis::X );
	AddMovementInput( ForwardDirection, MovementVector.Y );

	const FVector RightDirection = FRotationMatrix( YawRotation ).GetUnitAxis( EAxis::Y );
	AddMovementInput( RightDirection, MovementVector.X );

}

void ASlashCharacter::Look( const FInputActionValue& Value )
{
	const FVector2D LookAxisVector = Value.Get<FVector2D>( );
	AddControllerPitchInput( LookAxisVector.Y );
	AddControllerYawInput( LookAxisVector.X );
}


void ASlashCharacter::Jump( ) 
{

}

void ASlashCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ASlashCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	if ( UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>( PlayerInputComponent ) )
	{
		EnhancedInputComponent->BindAction( MovementAction, ETriggerEvent::Triggered, this, &ASlashCharacter::Move );
		EnhancedInputComponent->BindAction( LookAction, ETriggerEvent::Triggered, this, &ASlashCharacter::Look );
		EnhancedInputComponent->BindAction( JumpAction, ETriggerEvent::Triggered, this, &ASlashCharacter::Jump );
	}
}

