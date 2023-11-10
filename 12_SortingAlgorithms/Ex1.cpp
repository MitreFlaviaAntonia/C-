#include <iostream>
#include <vector>

std::vector<int> bubbleSortPosParity(std::vector<int> arr)
{
	int i;
	int j;
	int size = arr.size();
	bool swapped;
	for (i = 0; i < size - 1; i++)
	{
		swapped = false;
		for (j = 0; j < size - i - 2; j++)
		{
			if (j % 2 == 0 && arr[j] > arr[j + 2])
			{
				std::swap(arr[j], arr[j + 2]);
				swapped = true;
			}
			if (j % 2 != 0 && arr[j] < arr[j + 2])
			{
				std::swap(arr[j], arr[j + 2]);
				swapped = true;
			}
		}
		if (swapped == false)
		{
			break;
		}
	}
	return arr;
}

std::vector<int> orderElements(std::vector<int> arr)
{
	int i;
	int j = 0;
	int size = arr.size();
	if (size % 2 != 0)
	{
		j = 1;
	}
	std::vector<int> arr2(size, 0);

	for (i = 0; i < size; i++)
	{
		if (i % 2 == 0)
		{
			arr2[i / 2] = arr[i];
		}
		if (i % 2 != 0)
		{
			arr2[size / 2 + j] = arr[i];
			j++;
		}
	}
	return arr2;
}

void printArray(std::vector<int> arr)
{
	int i;
	for (i = 0; i < arr.size(); i++)
	{
		std::cout << " " << arr[i];
	}
}

int main()
{
	std::vector<int> arr = { 3, 1, 2, 4, 5, 9, 13, 14, 12 };
	arr = bubbleSortPosParity(arr);
	arr = orderElements(arr);
	printArray(arr);
	return 0;
}