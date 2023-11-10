#include <iostream>
#include <list>

int main()
{
	std::list<int> numbersList;
	int element;

	std::cout << "Enter the elements of the list: ";
	std::cin >> element;
	while (element != -1)
	{
		numbersList.push_back(element);
		std::cin >> element;
	}

	int numToRemove;
	std::cout << "Enter an element to find it's occurrences in the list: ";
	std::cin >> numToRemove;

	auto it = std::find(numbersList.begin(), numbersList.end(), numToRemove);
	while (it != numbersList.end())
	{
		auto numToRemovePos = std::next(it);
		numbersList.erase(it);
		it = std::find(numToRemovePos, numbersList.end(), numToRemove);
	}

	for (int i : numbersList)
	{
		std::cout << i << " ";
	}
	std::cout << std::endl;

	return 0;
}
