#include <iostream>
#include <unordered_map>
#include <vector>

std::vector<int> twoSum(std::vector<int>& nums, int target)
{
	std::vector<int> result;
	std::unordered_map<int, int> numMap;

	for (int i = 0; i < nums.size(); ++i)
	{
		int numsj = target - nums[i];

		if (numMap.find(numsj) != numMap.end())
		{
			result.push_back(numMap[numsj]);
			result.push_back(i);
			return result;
		}
		numMap[nums[i]] = i;
	}
	return result;
}

int main()
{
	std::vector<int> nums = { 2,7,11,15 };
	std::vector<int> result;
	result = twoSum(nums, 9);
	if(!result.empty())
	{
		std::cout << result[0] << " " << result[1] << std::endl;
	}
	return 0;
}