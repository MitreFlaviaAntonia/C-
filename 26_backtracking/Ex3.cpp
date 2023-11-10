#include <iostream>
#include <vector>

void backtracking(const std::vector<int>& candidates, std::vector<int>& sol, std::vector<std::vector<int>>& result, int targetSum, int index)
{
	if (targetSum == 0)
	{
		result.push_back(sol);
		return;
	}

	for (int i = index; i < candidates.size(); i++)
	{
		if (candidates[i] > targetSum)
		{
			break;
		}

		sol.push_back(candidates[i]);
		backtracking(candidates, sol, result, targetSum - candidates[i], i);
		sol.pop_back();
	}
}

std::vector<std::vector<int>> combinationSum(std::vector<int>& candidates, int targetSum)
{
	std::vector<std::vector<int>> result;
	std::vector<int> sol;
	backtracking(candidates, sol, result, targetSum, 0);
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
	std::vector<int> candidates = { 2,3,6,7 };
	int targetSum = 7;
	printVectorOfVectors(combinationSum(candidates, targetSum));
	return 0;
}