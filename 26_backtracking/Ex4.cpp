#include <iostream>
#include <vector>
#include <algorithm>

bool areVectorsEqual(const std::vector<int> vector1, const std::vector<int> vector2)
{
	if (vector1.size() != vector2.size())
	{
		return false;
	}

	std::vector<int> sortedVector1 = vector1;
	std::vector<int> sortedVector2 = vector2;

	std::sort(sortedVector1.begin(), sortedVector1.end());
	std::sort(sortedVector2.begin(), sortedVector2.end());
	if (!(sortedVector1 == sortedVector2))
		return false;

	return true;
}

void foundSolution(const std::vector<int>& arr, const std::vector<int>& sol, std::vector<std::vector<int>>& result)
{
	if (areVectorsEqual(arr, sol))
	{
		if (std::find(result.begin(), result.end(), sol) == result.end())
		{
			result.push_back(sol);
		}
	}
}

void backtracking(const std::vector<int>& arr, std::vector<int>& sol, std::vector<std::vector<int>>& result)
{
	if (sol.size() == arr.size())
	{
		foundSolution(arr, sol, result);
		return;
	}

	for (int i = 0; i < arr.size(); i++)
	{
		sol.push_back(arr[i]);
		backtracking(arr, sol, result);
		sol.pop_back();
	}
}

std::vector<std::vector<int>> permuteUnique(std::vector<int>& nums)
{
	std::vector<std::vector<int>> result;
	std::vector<int> sol;
	backtracking(nums, sol, result);
	return result;
}

void printVectorOfVectors(const std::vector<std::vector<int>>& vec)
{
	for (const auto& innerVec : vec)
	{
		for (const auto& element : innerVec)
		{
			std::cout << element << " ";
		}
		std::cout << std::endl;
	}
}

int main()
{
	std::vector<int> nums = { 1, 2, 3 };
	printVectorOfVectors(permuteUnique(nums));
	return 0;
}

/*
//-----sol 2--------
void backtracking(std::vector<int>& nums, std::vector<int>& permutation, std::vector<std::vector<int>>& result, std::vector<bool>& used)
{
	if (permutation.size() == nums.size())
	{
		result.push_back(permutation);
		return;
	}

	for (int i = 0; i < nums.size(); i++)
	{
		if (used[i] || (i > 0 && nums[i] == nums[i-1] && !used[i-1]))
			continue;

		used[i] = true;
		permutation.push_back(nums[i]);
		backtracking(nums, permutation, result, used);
		permutation.pop_back();
		used[i] = false;
	}
}

std::vector<std::vector<int>> permuteUnique(std::vector<int>& nums)
{
	std::sort(nums.begin(), nums.end());
	std::vector<std::vector<int>> result;
	std::vector<int> permutation;
	std::vector<bool> used(nums.size(), false);
	backtracking(nums, permutation, result, used);
	return result;
}
*/