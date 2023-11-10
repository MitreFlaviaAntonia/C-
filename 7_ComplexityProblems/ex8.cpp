#include <iostream>
#include <vector>

int findElement(std::vector<int>& nums)
{
	int n = nums.size();
	// Create two arrays to store the maximum element from the left and minimum element from the right
	std::vector<int> leftMax(n);
	std::vector<int> rightMin(n);
	leftMax[0] = nums[0];
	for (int i = 1; i < n; i++)
	{
		leftMax[i] = std::max(leftMax[i - 1], nums[i]);
	}

	rightMin[n - 1] = nums[n - 1];
	for (int i = n - 2; i >= 0; i--)
	{
		rightMin[i] = std::min(rightMin[i + 1], nums[i]);
	}
	for (int i = 1; i < n - 1; i++)
	{
		if (nums[i] > leftMax[i - 1] && nums[i] < rightMin[i + 1])
		{
			return nums[i];
		}
	}
	return -1;
}
int main()
{
	std::vector<int> nums = { 1, 3, 5, 4, 7, 9 };
	int element = findElement(nums);
	if (element != -1)
	{
		std::cout << "Element found: " << element << std::endl;
	}
	else
	{
		std::cout << "No element has been found" << std::endl;
	}
	return 0;
}