#include <iostream>
#include <vector>

std::vector<int> bubbleSort(std::vector<int> arr)
{
	int i;
	int j;
	int size = arr.size();
	bool swapped;
	for (i = 0; i < size - 1; i++)
	{
		swapped = false;
		for (j = 0; j < size - i - 1; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				std::swap(arr[j], arr[j + 1]);
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

int main()
{
	std::vector<int> arr = { 64, 34, 25, 12, 22, 11, 90 };
	int k = 3;
	int size = arr.size();
	arr = bubbleSort(arr);
	std::cout << "Element at position " << k << " is " << arr[k];
	return 0;
}