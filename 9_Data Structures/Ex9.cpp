#include <iostream>
#include <unordered_set>

int main()
{
	std::unordered_set<int> numbersUnorderedSet;
	int element;

	std::cout << "Enter elements: " << std::endl;

	while (true)
	{
		std::cout << "Enter an integer: ";
		std::cin >> element;
		if (numbersUnorderedSet.count(element) > 0)
		{
			std::cout << "Duplicate number detected. Stopping input." << std::endl;
			break;
		}
		numbersUnorderedSet.insert(element);
	}

	std::cout << "Resulting set: ";
	for (const auto& num : numbersUnorderedSet)
	{
		std::cout << num << " ";
	}
	std::cout << std::endl;

	return 0;
}