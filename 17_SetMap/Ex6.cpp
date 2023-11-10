#include <iostream>
#include <fstream>
#include <map>

void NewScore(std::map<std::string, float>& scoreMap, std::string name, float score)
{
	scoreMap[name] = score;
}

void GetScore(std::map<std::string, float> scoreMap, const std::string name)
{
	std::cout << scoreMap[name] << std::endl;
}


int main()
{
	std::map<std::string, float> scoreMap;
	int option = 1;
	std::string playerName;
	int score = 0;

	while (option)
	{
		std::cout << "Choose the option: 1 - newScore, 2 - getScore, anything else - exit" << std::endl;
		std::cin >> option;

		switch (option)
		{
		case 1:
		{
			std::cout << "Enter player name: " << std::endl;
			std::cin >> playerName;
			std::cout << "Enter score: " << std::endl;
			std::cin >> score;

			NewScore(scoreMap, playerName, score);
			break;
		}
		case 2:
		{
			std::cout << "Enter player name: " << std::endl;
			std::cin >> playerName;

			GetScore(scoreMap, playerName);
			break;
		}
		default: //exit
		{
			option = 0;
			break;
		}
		}
	}

}
