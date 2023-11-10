#include<iostream>
#include <stack>
#include <vector>

void printNextGreaterElement(std::vector<int> arr, int size)
{
	std::stack<int> stk;
	stk.push(arr[0]);

	for (int i = 1; i < size; ++i)
	{
		while (!stk.empty() && arr[i] > stk.top())
		{
			std::cout << stk.top() << " - " << arr[i] << std::endl;
			stk.pop();
		}
		stk.push(arr[i]);
	}

	while (!stk.empty())
	{
		std::cout << stk.top() << " - " << -1 << std::endl;
		stk.pop();
	}
}

int main()
{
	std::vector<int> arr = { 4, 5, 2, 13, 25 };
	int size = arr.size();
	printNextGreaterElement(arr, size);
	return 0;
}