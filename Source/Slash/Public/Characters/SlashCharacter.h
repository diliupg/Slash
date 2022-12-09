// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "InputActionValue.h"
#include "SlashCharacter.generated.h"

#include "UObject/ObjectPtr.h"

class UInputMappingContext;
class UInputAction;
class USpringArmComponent;
class UCameraComponent;


UCLASS()
class SLASH_API ASlashCharacter : public ACharacter
{
	GENERATED_BODY()

public:

	ASlashCharacter();

	virtual void Tick( float DeltaTime ) override;

	virtual void SetupPlayerInputComponent( class UInputComponent* PlayerInputComponent ) override;

protected:

	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, Category = Input )
	TObjectPtr<UInputMappingContext> SlashContext;
	
	UPROPERTY( EditAnywhere, Category = Input )
	TObjectPtr<UInputAction> MovementAction;

	void Move( const FInputActionValue& Value );

private:

	UPROPERTY( VisibleAnywhere )
	//USpringArmComponent* CameraBoom;
	TObjectPtr<USpringArmComponent>CameraBoom;

	UPROPERTY( VisibleAnywhere )
	UCameraComponent* ViewCamera;

};
