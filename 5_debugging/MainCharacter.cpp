#include "MainCharacter.h"

MainCharacter::MainCharacter(const char* name, uint32_t health, uint32_t attackPower, float attackCooldown, uint32_t healValue, float healCooldown)
	: Character(name, health, attackPower, attackCooldown)
	, m_HealValue(healValue)
	, m_HealCooldown(healCooldown)
{
	m_HealCooldownTimer.Start(m_HealCooldown);
}

void MainCharacter::TryHeal()
{
	if (m_HealCooldownTimer.HasFinished())
	{
		if (m_Health <= m_MaxHealth - m_HealValue)
			m_Health += m_HealValue;
		else
			m_Health = m_MaxHealth;

		m_HealCooldownTimer.Start(m_HealCooldown);
		std::cout << "+ " << GetName() << " healed." << " +" << std::endl << std::endl;
	}
}