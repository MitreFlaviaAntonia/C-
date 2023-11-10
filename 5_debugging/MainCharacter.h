#pragma once

#include "Character.h"

class MainCharacter : public Character
{
public:
	MainCharacter(const char* name, uint32_t health, uint32_t attackPower, float attackCooldown, uint32_t healValue, float healCooldown);

	void TryHeal();

private:
	uint32_t m_HealValue{ 0 };
	uint32_t m_MaxHealth{ 800 };
	float m_HealCooldown{ 0 };
	Timer m_HealCooldownTimer;
};

