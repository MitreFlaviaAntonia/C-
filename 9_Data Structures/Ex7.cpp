#include <iostream>
#include <set>

int main()
{
	std::set<int> numbersSet;
	int element;

	int n;
	std::cout << "How many elements do you want to add in the set? " << std::endl;
	std::cin >> n;
	std::cout << "Enter elements: " << std::endl;

	for (int i = 0; i < n; i++)
	{
		std::cin >> element;
		numbersSet.insert(element);
	}

	int m;
	std::cout << "How many elements do you check if they are in the set? " << std::endl;
	std::cin >> m;
	std::cout << "Enter elements: " << std::endl;

	for (int i = 0; i < m; i++)
	{
		std::cin >> element;
		if (numbersSet.find(element) != numbersSet.end())
		{
			std::cout << "Yes" << std::endl;
		}
		else
		{
			std::cout << "No" << std::endl;
		}
	}
	return 0;
}