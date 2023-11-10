#include "Character.h"
#include <string.h>

Character::Character(const char* name, uint32_t health, uint32_t attackPower, float attackCooldown)
	: m_AttackCooldown(attackCooldown)
	, m_AttackPower(attackPower)
	, m_Health(health)
{
	strcpy_s(m_Name, name);
	m_AttackCooldownTimer.Start(m_AttackCooldown);
}

void Character::TakeDamage(uint32_t damage)
{
	if (m_Health >= damage)
		m_Health -= damage;
	else
		m_Health = 0;

	if (IsDead())
	{
		std::cout << GetName() << " has died." << std::endl << std::endl;
	}
}

bool Character::IsDead()
{
	return m_Health == 0;
}

bool Character::IsAlive()
{
	return m_Health > 0;
}

bool Character::CanAttack()
{
	return m_AttackCooldownTimer.HasFinished();
}

void Character::OnHasAttacked()
{
	m_AttackCooldownTimer.Start(m_AttackCooldown);
}