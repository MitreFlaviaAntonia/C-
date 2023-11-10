#include <vector>

void findMax(const std::vector<int>& arr, int start, int end, int& result)
{
	int maxVal = arr[start];
	for (int i = start + 1; i < end; ++i)
	{
		if (arr[i] > maxVal)
		{
			maxVal = arr[i];
		}
	}

	result = maxVal;
}

void findMin(const std::vector<int>& arr, int start, int end, int& result)
{
	int minVal = arr[start];
	for (int i = start + 1; i < end; ++i)
	{
		if (arr[i] < minVal)
		{
			minVal = arr[i];
		}
	}

	result = minVal;
}

void calculateSquares(std::vector<int>& arr, int start, int end, std::vector<int>& result)
{
	for (int i = start; i < end; ++i)
	{
		result[i] = pow(arr[i], 2);
	}
}

void calculateCubes(std::vector<int>& arr, int start, int end, std::vector<int>& result)
{
	for (int i = start; i < end; ++i)
	{
		result[i] = pow(arr[i], 3);
	}
}

void calculateSum(const std::vector<int>& arr, int start, int end, long& result)
{
	long partialSum = 0;

	for (int i = start; i < end; ++i)
	{
		partialSum = partialSum + arr[i];
	}

	result = result + partialSum;
}