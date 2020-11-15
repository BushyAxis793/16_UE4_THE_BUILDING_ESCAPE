// Copyright Mikolaj Nawrocki 2020

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Components/InputComponent.h"
#include "PhysicsEngine/PhysicsHandleComponent.h"
#include "Grabber.generated.h"

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class THEBUILDINGESCAPE_API UGrabber : public UActorComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UGrabber();

	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction *ThisTickFunction) override;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

private:
	float Reach = 100.f;
	
	UPROPERTY()
	UPhysicsHandleComponent *PhysicsHandle = nullptr;
	UPROPERTY()
	UInputComponent *InputComponent = nullptr;

	void Grab();
	void Release();
	void FindPhysicsHandle();
	void SetupInputComponent();

	//Return the first Actor within reach with physics body
	FHitResult GetFirstPhysicsBodyInReach() const;

	//return the line trace End
	FVector GetPlayersReach() const;

	//Get Players Position In World
	FVector GetPlayersWorldPos() const;
};
