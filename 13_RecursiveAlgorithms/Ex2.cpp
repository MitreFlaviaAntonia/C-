#include <iostream>

int binarySearch(int arr[], int left, int right, int searchedNumber)
{
	if (right >= left)
	{
		int mid = left + (right - left) / 2;

		if (arr[mid] == searchedNumber)
		{
			return mid;
		}

		if (arr[mid] > searchedNumber)
		{
			return binarySearch(arr, left, mid - 1, searchedNumber);
		}

		return binarySearch(arr, mid + 1, right, searchedNumber);
	}

	return -1;
}

int main()
{
	int arr[] = { 2, 3, 4, 10, 40 };
	int searchedNumber = 4;
	int size = sizeof(arr) / sizeof(arr[0]);
	int result = binarySearch(arr, 0, size - 1, searchedNumber);

	if (result == -1)
		std::cout << "Element is not present in array";
	else
		std::cout << "Element is present at index " << result;
	return 0;
}