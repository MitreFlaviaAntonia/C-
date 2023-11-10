#include <iostream>
#include <vector>

bool foundSolution(int n, std::vector<int> sol)
{
	return n == sol.size();
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

void backtrackingCom(const std::vector<int>& arr, std::vector<int> sol, int k, int index)
{
	if (foundSolution(k, sol))
	{
		displaySol(sol);
		// return;
	}
	else
	{
		for (int i = index; i < arr.size(); i++)
		{
			if (isValid(arr[i], sol))
			{
				sol.push_back(arr[i]);
				backtrackingCom(arr, sol, k, i+1);
				sol.pop_back();
			}
		}
	}
}

int main()
{
	std::vector<int> arr = { 1, 2, 3, 4 };
	std::vector<int> sol;
	int k = 3;
	sol.reserve(arr.size());
	backtrackingCom(arr, sol, k, 0);
	return 0;
}