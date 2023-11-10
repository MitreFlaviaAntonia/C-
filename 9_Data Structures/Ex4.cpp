#include <iostream>
#include <stack>

int main()
{
	std::stack<int> numbersStack;
	int element;

	std::cout << "Enter elements: ";

	for (int i = 0; i < 5; i++)
	{
		std::cin >> element;
		numbersStack.push(element);
	}

	for (int i = 0; i < 3; i++)
	{
		if (!numbersStack.empty())
		{
			std::cout << numbersStack.top() << std::endl;
			numbersStack.pop();
		}
	}

	std::cout << "Enter elements: ";
	// Add two more elements into the stack
	for (int i = 0; i < 2; i++)
	{
		std::cin >> element;
		numbersStack.push(element);
	}

	// Print all elements in the stack
	while (!numbersStack.empty())
	{
		std::cout << numbersStack.top() << " ";
		numbersStack.pop();
	}

	return 0;
}