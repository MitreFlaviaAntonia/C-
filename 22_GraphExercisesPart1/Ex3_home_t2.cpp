#include <iostream>
#include <vector>

int dfs(int employee, std::vector<int>& informTime, std::vector<std::vector<int>>& adjList)
{
	int maxTime = 0;
	for (int subordinatePos = 0; subordinatePos < adjList[employee].size(); subordinatePos++)
	{
		int subordinate = adjList[employee][subordinatePos];
		maxTime = std::max(maxTime, dfs(subordinate, informTime, adjList));
	}
	return informTime[employee] + maxTime;
}

int numOfMinutes(int n, int headID, std::vector<int>& manager, std::vector<int>& informTime)
{
	std::vector<std::vector<int>> adjList(n);
	for (int subordinate = 0; subordinate < n; subordinate++)
	{
		if (manager[subordinate] != -1)
		{
			adjList[manager[subordinate]].push_back(subordinate);
		}
	}
	return dfs(headID, informTime, adjList);
}

int main()
{
	int n = 6;
	int headID = 2;
	std::vector<int> manager = { 2, 2, -1, 2, 2, 2 };
	std::vector<int> informTime = { 0, 0, 1, 0, 0, 0 };

	int minutesNeeded = numOfMinutes(n, headID, manager, informTime);
	std::cout << "Minutes needed to inform all employees: " << minutesNeeded << std::endl;

	return 0;
}