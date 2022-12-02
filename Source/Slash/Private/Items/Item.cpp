// Fill out your copyright notice in the Description page of Project Settings.


#include "Items/Item.h"
#include "Slash/DebugMacros.h"
#include "Components/CapsuleComponent.h"

// Sets default values
AItem::AItem()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	ItemMesh = CreateDefaultSubobject<UStaticMeshComponent>( TEXT( "ItemMeshComponent" ) );
	RootComponent = ItemMesh;
}

void AItem::BeginPlay()
{
	Super::BeginPlay();

	int32 AvgInt = Avg<int32>( 5, 3 );
	UE_LOG( LogTemp, Warning, TEXT( "The average of 5 and 3 is: %d" ), AvgInt );

	int32 AvgFloat= Avg<float>( 4.34, 6.67 );
	UE_LOG( LogTemp, Warning, TEXT( "The average of  4.34 and 6.67 is: %f" ), AvgFloat );
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
	
	RunningTime += DeltaTime;
}

