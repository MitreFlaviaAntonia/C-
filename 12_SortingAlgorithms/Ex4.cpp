#include <iostream>
#include <vector>

int countSort(std::vector<int>& heights)
{
	int heightsSize = heights.size();
	std::vector<int> count(heightsSize, 0);
	std::vector<int> prefixSum(heightsSize, 0);

	for (int i = 0; i < heightsSize; i++)
	{
		count[heights[i]]++;
	}

	prefixSum[0] = count[0];
	int prefixSumSize = prefixSum.size();
	for (int i = 1; i < prefixSumSize; i++)
	{
		prefixSum[i] = prefixSum[i - 1] + count[i];
	}

	std::vector<int> expected(heightsSize + 1, 0);
	for (int i = 0; i < heightsSize; i++)
	{
		expected[prefixSum[heights[i]]] = heights[i];
		prefixSum[heights[i]] = prefixSum[heights[i]] - 1;
	}

	int mismatchCount = 0;
	for (int i = 0; i < heightsSize; i++)
	{
		if (heights[i] != expected[i+1])
		{
			mismatchCount++;
		}
	}

	return mismatchCount;
}

int main()
{
	std::vector<int> heights = { 1, 1, 4, 2, 1, 3 };
	int mismatchCount = countSort(heights);
	std::cout << "Number of mismatched indices: " << mismatchCount << std::endl;
	return 0;
}