#include <iostream>
#include <map>

int main()
{
	std::map<int, int> numbersMap;
	int key;
	int value;

	int n;
	std::cout << "How many pairs of elements do you want to add in the Map? " << std::endl;
	std::cin >> n;
	std::cout << "Enter elements: " << std::endl;

	for (int i = 0; i < n; i++)
	{
		std::cout << "Enter first element: " << std::endl;
		std::cin >> key;
		std::cout << "Enter second element: " << std::endl;
		std::cin >> value;
		numbersMap[key] = value;
	}

	int m;
	std::cout << "How many elements do you check if they are in the Map? " << std::endl;
	std::cin >> m;
	std::cout << "Enter elements: " << std::endl;

	for (int i = 0; i < m; i++)
	{
		std::cin >> key;
		if (numbersMap.find(key) != numbersMap.end())
		{
			std::cout << key << std::endl;
		}
		else
		{
			std::cout << "No" << std::endl;
		}
	}
	return 0;
}