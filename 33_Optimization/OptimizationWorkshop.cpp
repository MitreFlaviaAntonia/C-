#include <iostream>
#include <map>
#include <vector>
#include <string>
#include "src/optick.h"
#include "PlayerData.h"
#include "Weapon.h"

void CreateAndAddPlayer(std::map<int, PlayerData>& players, int playerID, Weapon* weapon)
{
	OPTICK_EVENT();
	PlayerData player;

	player.SetName("Player" + std::to_string(playerID));//assign the values directly to the functions, without creating variables
	player.SetHealth(rand() % 10);
	player.SetWeapon(weapon);
	players[playerID] = player;
}

std::vector<int> SearchDeadPlayers(std::map<int, PlayerData> players)
{
	OPTICK_EVENT();

	std::vector<int> filteredPlayers;

	std::map<int, PlayerData>::iterator it;
	for (it = players.begin(); it != players.end(); it++)
	{
		if (it->second.IsDead())
		{
			filteredPlayers.push_back(it->first);
		}
	}

	return filteredPlayers;
}

int main()
{
	// CreateWeapons
	std::vector<Weapon> weapons;
	weapons.emplace_back("dagger", 1, 1, false);//emplace_back instead of push_back
	weapons.emplace_back("axe", 6, 8, true);
	weapons.emplace_back("bow", 4, 6, true);
	weapons.emplace_back("spear", 2, 3, true);
	weapons.emplace_back("sword", 5, 4, false);
	weapons.emplace_back("mace", 10, 7, true);

	// Create players
	std::map<int, PlayerData> players;

	for (int i = 0; i < 100000; i++)
	{
		Weapon weapon = weapons[rand() % weapons.size()];
		CreateAndAddPlayer(players, i, &weapon);
 	}

	int playersSize = players.size();

	int counter = 0;

	while (true && counter < 100)
	{
		OPTICK_FRAME("MainThread");
		std::cout << counter << std::endl;
	
		for (int i = 0; i < playersSize; i++)
		{
			//int index = rand() % players.size();
			players[i].OnPlayerAttack();
			//players[index].WasAttacked(players[i].GetWeapon());
			PlayerData player = players[rand() % playersSize];
			while (player.IsDead())
			{
				player = players[rand() % playersSize];
			}

			if(!players[i].IsDead())
			{
				player.WasAttacked(players[i].GetWeapon());
			}
		}

		// -------------
		std::cout << "Searching players" << std::endl;
		
		std::vector<int> filteredPlayers = SearchDeadPlayers(players);;

		std::cout << filteredPlayers.size() << " players died" << std::endl;
		//---------------------

		// Replace players
		for (int i = 0; i < filteredPlayers.size(); i++)
		{
			Weapon weapon = weapons[rand() % weapons.size()];
			CreateAndAddPlayer(players, i, &weapon);
		}

		std::cout << "Created players" << std::endl;

		for (int i = 0; i < playersSize; i++)
		{
			players[i].PassTime();
		}

		counter = (counter + 1) % 10000;
	}
	
	std::cout << "Program Ended" << std::endl;
}
