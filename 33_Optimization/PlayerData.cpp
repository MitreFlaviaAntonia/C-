#include "PlayerData.h"
#include "src/optick.h"

PlayerData::PlayerData()
{
	m_Name = "";
	m_Health = 0;
	m_Weapon = nullptr;
	m_CanAttack = true;
}

PlayerData::PlayerData(std::string name, int health, Weapon* weapon)
{
	SetName(name);
	SetHealth(health);
	SetWeapon(weapon);
}

std::string PlayerData::GetName()
{
	return m_Name;
}

int PlayerData::GetHealth()
{
	return m_Health;
}

Weapon* PlayerData::GetWeapon()
{
	return m_Weapon;
}

bool PlayerData::GetCanAttack()
{
	return m_CanAttack;
}

void PlayerData::SetName(std::string name)
{
	m_Name = name;
}

void PlayerData::SetHealth(int health)
{
	m_Health = health;
}

void PlayerData::SetWeapon(Weapon* weapon)
{
	m_Weapon = weapon;
}

void PlayerData::PassTime()
{
	OPTICK_EVENT();
	if (m_Cooldown == 0)
	{
		m_CanAttack = true;
	}
	else
	{
		m_Cooldown--;
	}
}

void PlayerData::OnPlayerAttack()
{
	OPTICK_EVENT();
	if (m_Weapon->my_IsTwoHanded)
	{
		m_Cooldown = m_Weapon->my_Weight * 2;
	}
	else
	{
		m_Cooldown = m_Weapon->my_Weight;
	}
}

void PlayerData::WasAttacked(Weapon* weapon)
{
	m_Health -= weapon->my_Damage;
	if (m_Health < 0)
	{
		m_Health = 0;
	}
	m_CanAttack = false;
}

bool PlayerData::IsDead()
{
	return m_Health == 0;
}