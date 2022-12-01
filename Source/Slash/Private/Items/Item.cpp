// Fill out your copyright notice in the Description page of Project Settings.


#include "Items/Item.h"
#include "Slash/DebugMacros.h"

// Sets default values
AItem::AItem()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

void AItem::BeginPlay()
{
	Super::BeginPlay();

	/*UWorld* World = GetWorld( );
	
	SetActorLocation( FVector( 10.f, 50.f, 100.f ) );
	SetActorRotation( FRotator( 0.f, 120.f, 120.f ) ); 
	FVector Location = GetActorLocation( );
	FVector Forward = GetActorForwardVector( );

	DRAW_SPHERE( Location );
	DRAW_LINE( Location, Location + Forward * 100.f );
	DRAW_POINT( Location + Forward * 100.f );
	DRAW_VECTOR( Location, Location + Forward * 100.f );*/
}

float AItem::TransformedSin( )
{
	return Amplitude* FMath::Sin( RunningTime * TimeConstant );
}

float AItem::TransformedCos( )
{
	return Amplitude * FMath::Cos( RunningTime * TimeConstant );
}

void AItem::Tick(float DeltaTime)

{
	Super::Tick(DeltaTime);
	/*float MovementRate = 50;
	float RotationRate = 45;

	AddActorWorldOffset( FVector( MovementRate * DeltaTime, 0.f, 0.f ) );
	AddActorWorldRotation( FRotator( 0.f, RotationRate * DeltaTime, 0.f ) );*/

	RunningTime += DeltaTime;

	/*float DeltaZ = Amplitude * FMath::Sin( RunningTime * TimeConstant );
	AddActorWorldOffset( FVector( 0.f, 0.f, DeltaZ ) );*/

	DRAW_SPHERE_SingleFrame( GetActorLocation( ) );
	DRAW_VECTOR_SingleFrame( GetActorLocation( ), GetActorLocation( ) + GetActorForwardVector( ) * 100 );
	  
	 /*if ( GEngine )
	 {
		 FString Message = FString::Printf( TEXT( "Delta Time: %f" ), DeltaTime );
		 GEngine->AddOnScreenDebugMessage( 1, 1.f, FColor::Yellow, Message );
	 }	*/
}

