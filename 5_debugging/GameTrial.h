#pragma once
#include <iostream>
#include "MainCharacter.h"
#include "Defines.h"
#include "Timer.h"

class GameTrial
{
public:
	void Init();
	void Shutdown();
	void Update();
	
	bool Finished();

private:
	void PlayAttackSequence();
	void AdvanceSeason();
	Character* ChooseEnemyTarget();
	void ExecuteAttack(Character* attacker, Character* target);

private:
	Season m_CurrentSeason{ Season::Spring };
	MainCharacter* m_MainCharacter;
	Character* m_Enemies[4];
	Timer m_SeasonChangeTimer;
	int m_SeasonsPassed{ 0 };
};