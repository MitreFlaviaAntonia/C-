#pragma once
#include <string>
#include "Weapon.h"

class PlayerData
{
public:
	PlayerData();
	PlayerData(std::string name, int health, Weapon* weapon);

	std::string GetName();
	int GetHealth();
	Weapon* GetWeapon();
	bool GetCanAttack();

	void SetName(std::string name);
	void SetHealth(int health);
	void SetWeapon(Weapon* weapon);

	void PassTime();
	void OnPlayerAttack();
	void WasAttacked(Weapon* weapon);
	bool IsDead();

private:
	std::string m_Name;
	Weapon* m_Weapon;
	int m_Cooldown;
	short int m_Health;
	bool m_CanAttack;
};