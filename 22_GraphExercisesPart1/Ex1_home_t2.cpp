#include <iostream>
#include <queue>

class Solution
{
public:

	std::vector<std::vector<int>> convertDislikesToAdjList(std::vector<std::vector<int>>& dislikes, int n)
	{
		std::vector<std::vector<int>> adjList(n + 1, std::vector<int>());

		for (int i = 0; i < dislikes.size(); i++)
		{
			adjList[dislikes[i][0]].push_back(dislikes[i][1]);
			adjList[dislikes[i][1]].push_back(dislikes[i][0]);
		}

		return adjList;
	}

	bool possibleBipartition(int n, std::vector<std::vector<int>>& dislikes)
	{
		std::vector<std::vector<int>> adjList = convertDislikesToAdjList(dislikes, n);
		int no_nodes = n;
		std::vector<int> colored(no_nodes + 1, 0);

		for (int node_src = 1; node_src <= no_nodes; node_src++)
		{
			if (colored[node_src] == 0)
			{
				colored[node_src] = 1;
				std::queue<int> nodesQueue;
				nodesQueue.push(node_src);

				while (!nodesQueue.empty())
				{
					int currentNode = nodesQueue.front();
					nodesQueue.pop();

					for (int nextNodePos = 0; nextNodePos < adjList[currentNode].size(); nextNodePos++)
					{
						int nextNode = adjList[currentNode][nextNodePos];

						if (colored[nextNode] == colored[currentNode])
						{
							return false;
						}
						else if (colored[nextNode] == 0)
						{
							if (colored[currentNode] == 1)
							{
								colored[nextNode] = 2;
							}
							else
							{
								colored[nextNode] = 1;
							}
							nodesQueue.push(nextNode);
						}
					}
				}
			}
		}
		return true;
	}
};

int main()
{
	int no_nodes = 4;
	Solution solution;
	std::vector<std::vector<int>> dislikes = { {1,2}, {1,3}, {2,4} };
	bool isBipartite = solution.possibleBipartition(no_nodes, dislikes);
	if (isBipartite)
	{
		std::cout << "Splitting into two groups is possible" << std::endl;
	}
	else
	{
		std::cout << "Splitting into two groups is NOT possible" << std::endl;
	}

	return 0;
}