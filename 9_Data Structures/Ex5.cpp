#include <iostream>
#include <deque>

int main()
{
	std::deque<int> numbersDeque;
	int element;

	std::cout << "Enter elements: ";

	for (int i = 0; i < 5; i++)
	{
		std::cin >> element;
		numbersDeque.push_back(element);
	}

	for (int i = 0; i < 3; i++)
	{
		if (!numbersDeque.empty())
		{
			std::cout << numbersDeque.front() << std::endl;
			numbersDeque.pop_front();
		}
	}

	std::cout << "Enter elements: ";
	// Add two more elements into the stack
	for (int i = 0; i < 2; i++)
	{
		std::cin >> element;
		numbersDeque.push_back(element);
	}

	// Print all elements in the stack
	while (!numbersDeque.empty())
	{
		std::cout << numbersDeque.front() << " ";
		numbersDeque.pop_front();
	}

	return 0;
}