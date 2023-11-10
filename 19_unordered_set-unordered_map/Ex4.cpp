#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

std::vector<int> topKFrequent(std::vector<int>& nums, int k)
{
	std::unordered_map<int, int> freqMap;
	for (int num : nums)
	{
		freqMap[num]++;
	}

	std::priority_queue<std::pair<int, int>> elemQueue;
	for (auto it = freqMap.begin(); it != freqMap.end(); ++it)
	{
		elemQueue.push({ it->second, it->first });
	}

	std::vector<int> result;
	for (int i = 0; i < k; ++i)
	{
		result.push_back(elemQueue.top().second);
		elemQueue.pop();
	}

	return result;
}

int main()
{
	std::vector<int> nums = { 1,1,1,2,2,3 };
	int k = 2;
	std::vector<int> result;
	result = topKFrequent(nums, k);
	for (int i = 0; i < result.size(); i++)
	{
		std::cout << result[i] << " ";
	}
	return 0;
}