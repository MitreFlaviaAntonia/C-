#include "GameTrial.h"
#include "Utils.h"

void GameTrial::Init()
{
	m_MainCharacter = new MainCharacter("Main Character", 800, 31, 0.7f, 39, 2.6f);
	m_Enemies[0] = new Character("Enemy1", 300, 23, 1.2f);
	m_Enemies[1] = new Character("Enemy2", 300, 19, 2.5f);
	m_Enemies[2] = new Character("Enemy3", 500, 9, 1.3f);
	m_Enemies[3] = new Character("Enemy4", 100, 41, 2.9f);

	m_SeasonChangeTimer.Start(2.5f);

	srand(static_cast<uint32_t>(time(0)));
}

void GameTrial::Shutdown()
{
	if (m_MainCharacter->IsDead())
	{
		std::cout << "Enemies defeated the main character in " << m_SeasonsPassed << " seasons" << std::endl;
	}
	else
	{
		std::cout << "Main character defeated the enemies in " << m_SeasonsPassed << " seasons" << std::endl;
	}

	delete m_MainCharacter;
	delete m_Enemies[0];
	delete m_Enemies[1];
	delete m_Enemies[2];
	delete m_Enemies[3];
}

void GameTrial::Update()
{
 	AdvanceSeason();
	PlayAttackSequence();
}

void GameTrial::PlayAttackSequence()
{
	if (m_MainCharacter->CanAttack())
	{
		Character* target = ChooseEnemyTarget();
		ExecuteAttack(m_MainCharacter, target);
	}

	for (int i = 0; i < 4; ++i)
	{
		Character* enemy = m_Enemies[i];
		if (enemy->CanAttack() && enemy->IsAlive())
		{
			ExecuteAttack(enemy, m_MainCharacter);
		}
	}

	m_MainCharacter->TryHeal();
}

Character* GameTrial::ChooseEnemyTarget()
{
	Character* target = nullptr;
	do
	{
		target = m_Enemies[rand() % 4];
	} while (target->IsDead());
	return target;
}

void GameTrial::ExecuteAttack(Character* attacker, Character* target)
{
	std::cout << attacker->GetName() << " has attacked " << target->GetName() << std::endl << std::endl;
	target->TakeDamage(attacker->GetAttackPower());
	attacker->OnHasAttacked();
}

void GameTrial::AdvanceSeason()
{
	if (m_SeasonChangeTimer.HasFinished())
	{
		m_CurrentSeason = static_cast<Season>((static_cast<int>(m_CurrentSeason) + 1) % 4);
		m_SeasonChangeTimer.Start(2.5f);
		std::cout << "Season has changed to: " << std::endl;
		std::cout << ">> " << Utils::GetSeasonName(m_CurrentSeason) << " <<" << std::endl << std::endl;
		m_SeasonsPassed++;
	}
}

bool GameTrial::Finished()
{
	if (m_MainCharacter->IsDead())
	{
		return true;
	}
	
	int deadEnemiesNumber = 0;

	for (int i = 0; i < std::size(m_Enemies); i++)
	{
		if (m_Enemies[i]->IsDead())
		{
			deadEnemiesNumber++;
			if (deadEnemiesNumber == std::size(m_Enemies))
				return true;
		}
	}
	
	return false;
}