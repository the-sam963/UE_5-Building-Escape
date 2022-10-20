// Copyright Acepic Studio 2022


#include "OpenDoor.h"

// Sets default values for this component's properties
UOpenDoor::UOpenDoor()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UOpenDoor::BeginPlay()
{
	Super::BeginPlay();

	actorThatOpens = GetWorld()->GetFirstPlayerController()->GetPawn();
	

}

void UOpenDoor::OpenTheDoor()
{
	AActor* Owner = GetOwner();								// Get Owner (door)
	FRotator newRotation = FRotator(0.f, -70.f, 0.f);		// Create Rotation of Owner (door)
	Owner->SetActorRotation(newRotation);					// Set the door rotation
}


// Called every frame
void UOpenDoor::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if (pressurPlate->IsOverlappingActor(actorThatOpens))
	{
		OpenTheDoor();
	}
}

