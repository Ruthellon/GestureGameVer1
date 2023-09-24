// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "MyPlayerController.h"
#include "MyPawn.h"
#include "GM_Duel.generated.h"

/**
 * 
 */
enum class ePhase { Intro, Wait, Draw, Finished };
UCLASS()
class MYPROJECT_API AGM_Duel : public AGameModeBase
{
	GENERATED_BODY()
private:
	double m_dRandomWait;
	double m_dElapsedTime;
	ePhase m_eCurrentPhase;

public:
	AGM_Duel();
	virtual void Tick(float deltaTime) override;

	UFUNCTION(BlueprintImplementableEvent)
	void OnDraw();
};
