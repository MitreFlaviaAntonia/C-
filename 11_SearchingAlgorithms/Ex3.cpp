#include <iostream>
#include <vector>

int binarySearch(std::vector<int>& arr, int low, int high)
{
	if (high >= low)
	{
		int mid = low + (high - low) / 2;
		if (mid == arr[mid])
		{
			return mid;
		}
		int res = -1;
		if (mid + 1 <= arr[high])
		{
			res = binarySearch(arr, (mid + 1), high);
		}
		if (res != -1)
		{
			return res;
		}
		if (mid - 1 >= arr[low])
		{
			return binarySearch(arr, low, (mid - 1));
		}
	}

	return -1;
}

int main()
{
	std::vector<int> arr = { -10, -1, 0, 3, 10, 11, 30, 50, 100 };
	int size = arr.size();
	std::cout << "Fixed Point is " << binarySearch(arr, 0, size - 1);
	return 0;
}