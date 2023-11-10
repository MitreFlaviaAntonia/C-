#include <iostream>
#include <vector>

void closestPair(std::vector<int>& arr, int x)
{
	int pairLeft;
	int pairRight;
	int leftIndex = 0;
	int rightIndex = arr.size() - 1;
	int diff = INT_MAX;

	while (rightIndex > leftIndex)
	{
		if (abs(arr[leftIndex] + arr[rightIndex] - x) < diff)
		{
			pairLeft = leftIndex;
			pairRight = rightIndex;
			diff = abs(arr[leftIndex] + arr[rightIndex] - x);
		}

		if (arr[leftIndex] + arr[rightIndex] > x)
		{
			rightIndex--;
		}
		else
		{
			leftIndex++;
		}
	}

	std::cout << " The closest pair is " << arr[pairLeft] << " and " << arr[pairRight];
}

int main()
{
	std::vector<int> arr = { 13, 15, 21, 77, 87, 90 };
	int x = 35;
	int size = arr.size();;
	closestPair(arr, x);
	return 0;
}