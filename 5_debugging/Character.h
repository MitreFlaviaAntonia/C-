#pragma once

#include <iostream>
#include "Timer.h"

class Character
{
public:
	Character(const char* name, uint32_t health, uint32_t attackPower, float attackCooldown);

	bool CanAttack();
	void OnHasAttacked();
	uint32_t GetAttackPower() { return m_AttackPower; }

	uint32_t GetHealth() { return m_Health; }
	void SetHealth(uint32_t health) { m_Health = health; }

	bool IsDead();
	bool IsAlive();

	void TakeDamage(uint32_t damage);

	char* GetName() { return m_Name; }

protected:
	uint32_t m_Health{ 100 };

private:
	uint32_t m_AttackPower{ 1 };
	float m_AttackCooldown{ 1.f };
	char m_Name[20];
	Timer m_AttackCooldownTimer;
};

