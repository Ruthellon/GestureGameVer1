#include "TrainWidget.h"

// Sets default values
ATrainWidget::ATrainWidget()
{
	// Set this empty to call Tick() every frame. You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void ATrainWidget::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void ATrainWidget::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void ATrainWidget::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}
