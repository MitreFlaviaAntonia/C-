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

bool isValidNQueens(int x, std::vector<int> sol)
{
	int n = sol.size();
	for (int i = 0; i < n; i++)
	{
		if (abs(n - i) == abs(x - sol[i]))
		{
			return false;
		}
		else if (x == sol[i])
		{
			return false;
		}
	}

	return true;
}

void backtrackingNQueens(const std::vector<int>& arr, std::vector<int> sol)
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
			if (isValidNQueens(arr[i], sol))
			{
				sol.push_back(arr[i]);
				backtrackingNQueens(arr, sol);
				sol.pop_back();
			}
		}
	}
}

int main()
{
	std::vector<int> arr = { 1, 2, 3, 4 };
	std::vector<int> sol;
	sol.reserve(arr.size());
	backtrackingNQueens(arr, sol);
	return 0;
}*/