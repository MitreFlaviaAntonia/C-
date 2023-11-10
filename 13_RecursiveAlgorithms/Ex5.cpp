#include <iostream>
#include <vector>

void printOddEven(const std::vector<int>& arr, int index)
{
	if (index < 0 || index >= arr.size())
	{
		return;
	}

	if (arr[index] % 2 != 0)
	{
		std::cout << arr[index] << " ";
	}

	printOddEven(arr, index + 1);

	if (arr[index] % 2 == 0)
	{
		std::cout << arr[index] << " ";
	}
}

int main()
{
	std::vector<int> arr = { 2, 2, 1, 3, 4, 5, 3, 8, 6, 9, 2 };
	printOddEven(arr, 0);

	return 0;
}