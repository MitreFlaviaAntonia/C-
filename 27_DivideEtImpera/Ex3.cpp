#include <iostream>
#include <vector>
#include <algorithm>

int maxCrossingSubarray(std::vector<int>& nums, int left, int mid, int right)
{
	int leftSum = INT_MIN;
	int sum = 0;
	for (int i = mid; i >= left; --i)
	{
		sum += nums[i];
		leftSum = std::max(leftSum, sum);
	}

	int rightSum = INT_MIN;
	sum = 0;
	for (int i = mid + 1; i <= right; ++i)
	{
		sum += nums[i];
		rightSum = std::max(rightSum, sum);
	}

	return leftSum + rightSum;
}

int maxSubarray(std::vector<int>& nums, int left, int right)
{
	if (left == right)
	{
		return nums[left];
	}

	int mid = (left + right) / 2;

	int leftSum = maxSubarray(nums, left, mid);
	int rightSum = maxSubarray(nums, mid + 1, right);
	int crossSum = maxCrossingSubarray(nums, left, mid, right);

	return std::max({ leftSum, rightSum, crossSum });
}

int maxSubArray(std::vector<int>& nums)
{
	return maxSubarray(nums, 0, nums.size() - 1);
}

int main()
{
	std::vector<int> nums = { -2, 1, -3, 4, -1, 2, 1, -5, 4 };
	int result = maxSubArray(nums);
	std::cout << "Largest sum of sub array: " << result << std::endl;

	nums = { 1 };
	result = maxSubArray(nums);
	std::cout << "Largest sum of sub array: " << result << std::endl;

	nums = { 5, 4, -1, 7, 8 };
	result = maxSubArray(nums);
	std::cout << "Largest sum of sub array: " << result << std::endl;

	return 0;
}