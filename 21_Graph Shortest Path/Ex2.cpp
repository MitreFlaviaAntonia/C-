#include <iostream>
#include <list>
#include <queue>
#include <vector>

void printList(const std::list<int>& myList)
{
	for (const auto& element : myList)
	{
		std::cout << element << " ";
	}
	std::cout << std::endl;
}

void topologicalSort(int startingNode, std::vector<std::vector<int>> adjList, int nrNodes)
{
	std::queue<int> nodesQueue;
	std::vector<int> inDegree(nrNodes, 0);
	
	for (int currentNode = 0; currentNode < nrNodes; currentNode++)
	{
		for (int nextNodePos = 0; nextNodePos < adjList[currentNode].size(); ++nextNodePos)
		{
			inDegree[adjList[currentNode][nextNodePos]]++;
		}
	}
	
	for (int currentNode = 0; currentNode < nrNodes; currentNode++)
	{
		if (inDegree[currentNode] == 0)
		{
			nodesQueue.push(currentNode);
		}
	}

	std::list<int> topologicalOrder;
	int cntVisitedNodes = 0;

	while (!nodesQueue.empty())
	{
		int currentNode = nodesQueue.front();
		nodesQueue.pop();
		topologicalOrder.push_back(currentNode);

		for (int nextNodePos = 0; nextNodePos < adjList[currentNode].size(); ++nextNodePos)
		{
			inDegree[adjList[currentNode][nextNodePos]]--;
			if (inDegree[adjList[currentNode][nextNodePos]] == 0)
			{
				nodesQueue.push(adjList[currentNode][nextNodePos]);
			}
		}
		cntVisitedNodes++;
	}
	
	if (cntVisitedNodes != nrNodes)
	{
		std::cout << "Topological sort is not possible" << std::endl;
	}
	else
	{
		std::cout << "The topological order is: " << " \n"; 
		printList(topologicalOrder);
	}
}

int main()
{
	std::vector<std::vector<int>> adjList = { {}, {}, {3}, {1}, {0, 1}, {0, 2} };

	int startingNode = 1;
	int nrNodes = adjList.size();
	
	topologicalSort(startingNode, adjList, nrNodes);

	return 0;
}