#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>

//with map
std::vector<int> findDuplicatesMap(std::vector<int>& nums)
{
	std::vector<int> twice;
	std::unordered_map<int, int> numsMap;

	for (int i = 0; i < nums.size(); ++i)
	{
		if (numsMap.find(nums[i]) != numsMap.end())
		{
			if (numsMap[nums[i]] == 1)
			{
				twice.push_back(nums[i]);
			}
		}
		numsMap[nums[i]]++;
	}
	return twice;
}

//with set
std::vector<int> findDuplicatesSet(std::vector<int>& nums)
{
	std::vector<int> twice;
	std::unordered_set<int> numsSet;

	for (int i = 0; i < nums.size(); ++i)
	{
		if (numsSet.count(nums[i]) > 0) //count returns the number of elements in the set that are equal to the given value
		{
			twice.push_back(nums[i]);
		}
		numsSet.insert(nums[i]);
	}

	return twice;
}

int main()
{
	std::vector<int> nums = { 4,3,2,7,8,2,3,1 };
	std::vector<int> result;
	result = findDuplicatesMap(nums);
	if (!result.empty())
	{
		std::cout << result[0] << " " << result[1] << std::endl;
	}
	result = findDuplicatesSet(nums);
	if (!result.empty())
	{
		std::cout << result[0] << " " << result[1] << std::endl;
	}
	return 0;
}