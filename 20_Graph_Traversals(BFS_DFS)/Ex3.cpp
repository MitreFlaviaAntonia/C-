#include <iostream>
#include <vector>
#include <stack>

bool canVisitAllNodesDFS(std::vector<std::vector<int>> adjList, int  nrNodes, int startingNode)
{
	std::vector<bool> visited(nrNodes, false);
	std::stack<int> nodesStack;
	nodesStack.push(startingNode);
	int currentNode;

	while (!nodesStack.empty())
	{
		currentNode = nodesStack.top();
		nodesStack.pop();

		if (visited[currentNode] == 0)
		{
			visited[currentNode] = true;

			for (int nextNodePos = 0; nextNodePos < adjList[currentNode].size(); nextNodePos++)
			{
				int nextNode = adjList[currentNode][nextNodePos];
				if (visited[nextNode] == 0)
				{
					nodesStack.push(nextNode);
				}
			}
		}
	}

	for (int node = 0; node < nrNodes; ++node)
	{
		if (visited[node] == 0)
		{
			return false;
		}
	}

	return true;
}

bool isStronglyConnected(std::vector<std::vector<int>> adjList)
{
	if (!canVisitAllNodesDFS(adjList, adjList.size(), 0))
	{
		return false;
	}
	return true;
}

int main()
{
	std::vector<std::vector<int>> adjList1 = { {4}, {0, 2}, {1, 4}, {1, 2}, {3} }; //is a strongly connected graph
	std::vector<std::vector<int>> adjList2 = { {4}, {0, 2}, {1, 4}, {1, 2}, {0} }; //it's not a strongly connected graph
	std::cout << "Is the first graph given strongly connected? " << isStronglyConnected(adjList1) << std::endl;
	std::cout << "Is the second graph given strongly connected? " << isStronglyConnected(adjList2) << std::endl;
	return 0;
}