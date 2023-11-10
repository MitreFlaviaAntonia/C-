#include <iostream>
#include <unordered_map>

int main()
{
	std::unordered_map<int, int> numbersUnorderedMap;
	int key;
	int value;

	int n;
	std::cout << "How many pairs of elements do you want to add in the Map? " << std::endl;
	std::cin >> n;
	std::cout << "Enter elements: " << std::endl;

	for (int i = 0; i < n; i++)
	{
		std::cout << "Enter pair of elements: " << std::endl;
		std::cin >> key;
		std::cin >> value;
		numbersUnorderedMap[key] = value;
	}

	std::cout << "Enter integers to remove from the map: " << std::endl;

	while (std::cin >> key)
	{
		if (numbersUnorderedMap.find(key) != numbersUnorderedMap.end())
		{
			numbersUnorderedMap.erase(key);
		}
		else
		{
			break;
		}
	}

	// Print the values remaining in the map
	std::cout << "Values remaining in the map: ";
	for (const auto& pair : numbersUnorderedMap)
	{
		std::cout << pair.second << " ";
	}
	std::cout << std::endl;

	return 0;
}