// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "Runtime/Engine/Classes/Engine/UserInterfaceSettings.h"
#include "Runtime/Engine/Classes/Engine/RendererSettings.h"
#include "UnistrokeRecognizer.h"
#include "UnistrokeDataTable.h"
#include "PaintWidget.h"
#include "MyPlayerController.generated.h"

/**
 * 
 */

enum Action { Idle, Paint, Recognize, Train };

UCLASS()
class MYPROJECT_API AMyPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	UFUNCTION(Exec)
	void TrainMode(const bool Is);

public:
	AMyPlayerController();
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

public:
	void ShowTrainWidget();
	void HideTrainWidget();
	void AddTemplateToDataTable(const FString Name);

private:
	void PressedToPaint();
	void ReleasedToPaint();
	void LoadTemplates();
	void Spell();

private:
	UDataTable* UnistrokeTable;
	UPaintWidget* PaintWidget;
	UUserWidget* TrainWidget;
	TSubclassOf<UUserWidget> TrainWidgetClass;
	FUnistrokeRecognizer* Recognizer;
	int CurrentAction;
	bool IsTraining;
	
};
