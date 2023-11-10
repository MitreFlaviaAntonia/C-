#include <iostream>
#include <vector>

bool hasCycle(std::vector<std::vector<int>> adjList, int currentNode, std::vector<bool>& visited, int parent)
{
	visited[currentNode] = true;

	for (int nextNodeIndex = 0; nextNodeIndex < adjList[currentNode].size(); nextNodeIndex++)
	{
		int nextNode = adjList[currentNode][nextNodeIndex];
		if (!visited[nextNode])
		{
			if (hasCycle(adjList, nextNode, visited, currentNode))
			{

				return true;
			}
		}
		else if (nextNode != parent)
		{
			return true;
		}
	}
	return false;
}

bool containsCycle(std::vector<std::vector<int>> adjList)
{
	int nrNodes = adjList.size();
	std::vector<bool> visited(nrNodes, false);

	for (int currentNode = 0; currentNode < nrNodes; currentNode++)
	{
		if (!visited[currentNode] && hasCycle(adjList, currentNode, visited, -1)) //starting node to verify if the graph contains a cycle => invalid value for parent
		{
			return true;
		}
	}
	return false;
}

int main() 
{
	std::vector<std::vector<int>> adjList = { {1, 2}, {0}, {0, 3}, {2} }; //no cycle
	std::vector<std::vector<int>> adjList2 = { {1}, {2, 3, 4}, {1, 5, 6}, {1}, {1, 7, 8}, {2, 9, 10}, {2, 10}, {4, 1}, {4}, {5}, {5, 6}, {7}, {7} };

	bool hasCycle = containsCycle(adjList);
	
	if (hasCycle)
	{
		std::cout << "The graph contains a cycle." << std::endl;
	}
	else
	{
		std::cout << "The graph does not contain a cycle." << std::endl;
	}

	hasCycle = containsCycle(adjList2);

	if (hasCycle)
	{
		std::cout << "The graph contains a cycle." << std::endl;
	}
	else
	{
		std::cout << "The graph does not contain a cycle." << std::endl;
	}

	return 0;
}