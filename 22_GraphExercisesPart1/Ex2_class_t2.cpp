#include <iostream>
#include <vector>

class Solution
{
private:
	std::vector<int> DFS_ex2(int node_src, std::vector<int>& visitedDFS, int no_nodes, std::vector<std::vector<int>>& graph);
	bool isSafe(int node, std::vector<int>& visitedDFS, std::vector<std::vector<int>>& graph);

public:
	std::vector<int> eventualSafeNodes(std::vector<std::vector<int>>& graph);
};

bool Solution::isSafe(int node, std::vector<int>& visitedDFS, std::vector<std::vector<int>>& graph)
{
	if (visitedDFS[node] == 2)
	{
		return true;
	}
	if (visitedDFS[node] == 1)
	{
		return false;
	}

	visitedDFS[node] = 1;
	for (int neighbor : graph[node])
	{
		if (!isSafe(neighbor, visitedDFS, graph))
		{
			return false;
		}
	}
	visitedDFS[node] = 2;
	return true;
}

std::vector<int> Solution::DFS_ex2(int node_src, std::vector<int>& visitedDFS, int no_nodes, std::vector<std::vector<int>>& graph)
{
	std::vector<int> safeNodes;
	visitedDFS[node_src] = 1;

	for (int neighbor : graph[node_src])
	{
		if (!visitedDFS[neighbor] && isSafe(neighbor, visitedDFS, graph))
		{
			safeNodes.push_back(neighbor);
		}
	}

	visitedDFS[node_src] = 2;
	return safeNodes;
}

std::vector<int> Solution::eventualSafeNodes(std::vector<std::vector<int>>& graph)
{
	int no_nodes = graph.size();
	std::vector<int> visitedDFS(no_nodes);
	std::vector<int> safeNodes;

	for (int node = 0; node < no_nodes; node++)
	{
		if (isSafe(node, visitedDFS, graph))
		{
			safeNodes.push_back(node);
		}
	}

	return safeNodes;
}

int main()
{
	Solution solution;

	//with safe nodes
	std::vector<std::vector<int>> graph1 = { {3}, {0}, {1}, {2, 4}, {5}, {} };
	std::vector<int> safeNodes1 = solution.eventualSafeNodes(graph1);

	std::cout << "Safe nodes in graph1: ";
	for (int i = 0; i < safeNodes1.size(); i++)
	{
		int node = safeNodes1[i];
		std::cout << node << " ";
	}
	std::cout << std::endl;

	//without safe nodes
	std::vector<std::vector<int>> graph2 = { {1, 2}, {2}, {0} };
	std::vector<int> safeNodes2 = solution.eventualSafeNodes(graph2);

	if (safeNodes2.size() == 0)
	{
		std::cout << "This graph does not contain safe nodes";
	}

	return 0;
}