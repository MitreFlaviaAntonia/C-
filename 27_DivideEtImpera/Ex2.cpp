#include <iostream>
#include <vector>
#include <unordered_map>

void merge(std::vector<std::pair<int, int>>& arr, int left, int mid, int right)
{
	std::vector<std::pair<int, int>> temp(right - left + 1);
	int i = left;
	int j = mid + 1;
	int k = 0;

	while (i <= mid && j <= right)
	{
		if (arr[i].second > arr[j].second)
		{
			temp[k++] = arr[i++];
		}
		else
		{
			temp[k++] = arr[j++];
		}
	}

	while (i <= mid)
	{
		temp[k++] = arr[i++];
	}

	while (j <= right)
	{
		temp[k++] = arr[j++];
	}

	for (int p = 0; p < k; ++p)
	{
		arr[left + p] = temp[p];
	}
}

void quicksort(std::vector<std::pair<int, int>>& arr, int left, int right, int k)
{
	if (left >= right)
	{
		return;
	}

	int pivot = arr[left + (right - left) / 2].second;
	int i = left;
	int j = right;

	while (i <= j)
	{
		while (arr[i].second > pivot)
		{
			i++;
		}
		while (arr[j].second < pivot)
		{
			j--;
		}

		if (i <= j)
		{
			std::swap(arr[i], arr[j]);
			i++;
			j--;
		}
	}

	if (left + k - 1 <= j)
	{
		quicksort(arr, left, j, k);
	}
	if (left + k - 1 >= i)
	{
		quicksort(arr, i, right, k - (i - left));
	}
}

std::vector<int> topKFrequent(std::vector<int>& nums, int k)
{
	std::unordered_map<int, int> frequencyMap;
	for (int num : nums)
	{
		frequencyMap[num]++;
	}

	std::vector<std::pair<int, int>> frequencyPairs;
	for (auto & it : frequencyMap)
	{
		frequencyPairs.emplace_back(it.first, it.second);
	}

	quicksort(frequencyPairs, 0, frequencyPairs.size() - 1, k);

	std::vector<int> result;
	for (int i = 0; i < k; ++i)
	{
		result.push_back(frequencyPairs[i].first);
	}

	return result;
}

int main()
{
	std::vector<int> nums = { 1, 1, 1, 2, 2, 3 };
	int k = 2;
	std::vector<int> result = topKFrequent(nums, k);

	std::cout << "Top " << k << " frequent elements: ";
	for (int num : result)
	{
		std::cout << num << " ";
	}
	std::cout << std::endl;

	nums = { 1 };
	k = 1;
	result = topKFrequent(nums, k);

	std::cout << "Top " << k << " frequent elements: ";
	for (int num : result)
	{
		std::cout << num << " ";
	}
	std::cout << std::endl;

	return 0;
}