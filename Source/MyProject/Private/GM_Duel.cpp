// Fill out your copyright notice in the Description page of Project Settings.


#include "GM_Duel.h"

AGM_Duel::AGM_Duel()
{
	PrimaryActorTick.bStartWithTickEnabled = true;
	PrimaryActorTick.bCanEverTick = true;
	m_dElapsedTime = 0;
	m_eCurrentPhase = ePhase::Intro;


	PlayerControllerClass = AMyPlayerController::StaticClass();
	DefaultPawnClass = AMyPawn::StaticClass();
}

void AGM_Duel::Tick(float deltaTime)
{
	Super::Tick(deltaTime);

	m_dElapsedTime += deltaTime;

	if (m_eCurrentPhase == ePhase::Intro && m_dElapsedTime >= 1.0f)
	{
		m_eCurrentPhase = ePhase::Wait;
		m_dRandomWait = FMath::RandRange(1.0f, 5.0f);

		m_dElapsedTime = 0.0f;

		if (GEngine)
			GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("Wait"));
	}
	else if (m_eCurrentPhase == ePhase::Wait && m_dElapsedTime >= m_dRandomWait)
	{
		m_eCurrentPhase = ePhase::Draw;

		OnDraw();

		if (GEngine)
			GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("Draw"));
	}
}