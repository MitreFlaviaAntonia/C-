#include <iostream>
#include <queue>

class Solution
{
public:
	bool isBipartite(std::vector<std::vector<int>>& graph)
	{
		int no_nodes = graph.size();
		std::vector<int> colored(no_nodes, 0);

		for (int node_src = 0; node_src < no_nodes; node_src++)
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

					for (int nextNodePos = 0; nextNodePos < graph[currentNode].size(); nextNodePos++)
					{
						int nextNode = graph[currentNode][nextNodePos];

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
	std::vector<std::vector<int>> graph = { {1, 3}, {0, 2}, {1, 3}, {0, 2} };

	Solution solution;
	bool isBipartite = solution.isBipartite(graph);

	if (isBipartite)
	{
		std::cout << "The graph is bipartite." << std::endl;
	}
	else
	{
		std::cout << "The graph is not bipartite." << std::endl;
	}

	return 0;
}