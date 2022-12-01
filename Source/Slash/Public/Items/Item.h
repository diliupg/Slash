// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Item.generated.h"

UCLASS()
class SLASH_API AItem : public AActor
{
	GENERATED_BODY()
	
public:	

	AItem();

	virtual void Tick( float DeltaTime ) override;

protected:

	virtual void BeginPlay() override;

	UPROPERTY( EditAnywhere, BlueprintReadWrite, Category = SineParameters )
	float TimeConstant = 5.f;

	UPROPERTY( EditAnywhere, BlueprintReadWrite, Category = SineParameters )
	float Amplitude = 0.25;

	UFUNCTION(BlueprintPure)
	float TransformedSin( );

	UFUNCTION( BlueprintPure )
	float TransformedCos( );
private:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true" ))
	float RunningTime = 5.f;
};
