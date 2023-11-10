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

std::vector<int> relativeSort(std::vector<int> arr1, std::vector<int> arr2)
{
	int i;
	int j;
	int k = 0;
	int size1 = arr1.size();
	int size2 = arr2.size();
	std::vector<int> arr3(size1, 0);

	for (j = 0; j < size2; j++)
	{
		for (i = 0; i < size1; i++)
		{
			if (arr2[j] == arr1[i])
			{
				arr3[k] = arr1[i];
				k++;
			}
		}
	}

	for (i = 0; i < size1; i++)
	{
		bool isFound = false;
		for (j = 0; j < size2; j++)
		{
			if (arr1[i] == arr2[j])
			{
				isFound = true;
			}
		}
		if (isFound == false)
		{
			arr3[k] = arr1[i];
			k++;
		}
	}

	return arr3;
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
	std::vector<int> arr1 = { 2, 3, 1, 3, 2, 4, 6, 19, 9, 2, 7 };
	std::vector<int> arr2 = { 2, 1, 4, 3, 9, 6 };
	int size1 = arr1.size();
	int size2 = arr2.size();

	arr1 = bubbleSort(arr1);
	arr1 = relativeSort(arr1, arr2);
	printArray(arr1);
	return 0;
}