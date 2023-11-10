#include <iostream>

void bubbleSort(int arr[], int size)
{
	if (size == 1)
		return;

	int count = 0;

	for (int i = 0; i < size - 1; i++)
	{
		if (arr[i] > arr[i + 1])
		{
			std::swap(arr[i], arr[i + 1]);
			count++;
		}
	}

	if (count == 0)
		return;

	bubbleSort(arr, size - 1);
}

void printArray(int arr[], int size)
{
	for (int i = 0; i < size; i++)
	{
		std::cout << arr[i] << " ";
	}
}

int main()
{
	int arr[] = { 64, 34, 25, 12, 22, 11, 90 };
	int size = sizeof(arr) / sizeof(arr[0]);
	bubbleSort(arr, size);
	std::cout << "Sorted array : \n";
	printArray(arr, size);
	return 0;
}