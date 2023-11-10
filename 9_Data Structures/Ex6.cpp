#include <iostream>
#include <queue>

int main()
{
	std::priority_queue<int> numbersPriorityQueue;
	int element;

	std::cout << "Enter elements: ";

	for (int i = 0; i < 5; i++)
	{
		std::cin >> element;
		numbersPriorityQueue.push(element);
	}

	for (int i = 0; i < 3; i++)
	{
		if (!numbersPriorityQueue.empty())
		{
			std::cout << numbersPriorityQueue.top() << std::endl;
			numbersPriorityQueue.pop();
		}
	}

	std::cout << "Enter elements: ";
	// Add two more elements into the stack
	for (int i = 0; i < 2; i++)
	{
		std::cin >> element;
		numbersPriorityQueue.push(element);
	}

	// Print all elements in the stack
	while (!numbersPriorityQueue.empty())
	{
		std::cout << numbersPriorityQueue.top() << " ";
		numbersPriorityQueue.pop();
	}

	return 0;
}