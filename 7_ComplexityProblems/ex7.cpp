#include <iostream>

void printCommonElements(int arr1[], int size1, int arr2[], int size2)
{
	int i = 0;
	int j = 0;

	while (i < size1 && j < size2)
	{
		if (arr1[i] < arr2[j])
		{
			i++;
		}
		else
		{
			if (arr1[i] > arr2[j])
			{
				j++;
			}
			else
			{
				std::cout << arr1[i] << " ";
				i++;
				j++;
			}
		}
	}
}

int main()
{
	int arr1[] = { 1, 2, 4, 7, 9 };
	int size1 = std::size(arr1);

	int arr2[] = { 2, 4, 6, 8, 10 };
	int size2 = std::size(arr2);

	printCommonElements(arr1, size1, arr2, size2);

	return 0;
}