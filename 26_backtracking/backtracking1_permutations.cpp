/*#include <iostream>
#include <vector>

bool foundSolution(const std::vector<int>& arr, std::vector<int> sol)
{
	return sol.size() == arr.size();
}

void displaySol(std::vector<int> sol)
{
	for (int i = 0; i < sol.size(); i++)
	{
		std::cout << sol[i] << " ";
	}
	std::cout << "\n";
}

bool isValid(int x, std::vector<int> sol)
{
	return find(sol.begin(), sol.end(), x) == sol.end();
}

void backtracking(const std::vector<int>& arr, std::vector<int> sol)
{
	if (foundSolution(arr, sol))
	{
		displaySol(sol);
		// return;
	}
	else
	{
		for (int i = 0; i < arr.size(); i++)
		{
			if (isValid(arr[i], sol))
			{
				sol.push_back(arr[i]);
				backtracking(arr, sol);
				sol.pop_back();
			}
		}
	}
}

int main()
{
	std::vector<int> arr = { 1, 2, 3 };
	std::vector<int> sol;
	sol.reserve(arr.size());
	backtracking(arr, sol);
	return 0;
}*/