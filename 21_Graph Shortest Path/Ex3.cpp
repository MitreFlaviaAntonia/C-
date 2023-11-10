#include <iostream>
#include <list>
#include <queue>
#include <vector>

void containsCycle(int startingNode, std::vector<std::vector<int>> adjList, int nrNodes)
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
			if (!adjList[currentNode].empty())
			{
				inDegree[adjList[currentNode][nextNodePos]]--;
				if (inDegree[adjList[currentNode][nextNodePos]] == 0)
				{
					nodesQueue.push(adjList[currentNode][nextNodePos]);
				}
			}
		}
		cntVisitedNodes++;
	}

	if (cntVisitedNodes != nrNodes)
	{
		std::cout << "The graph does not contain a cycle" << std::endl;
	}
	else
	{
		std::cout << "The graph contains a cycle" << " \n";
	}
}

std::vector<std::vector<int>> makeAdjList(std::vector<std::vector<int>> edges, int nrNodes)
{
	std::vector<std::vector<int>> adjList(nrNodes);

	for (int i = 0; i < edges.size(); i++)
	{
		adjList[edges[i][0]].push_back(edges[i][1]);
	}
	
	return adjList;
}

int main()
{
	int nrNodes = 6;
	int nrEdges = 6;
	std::vector<std::vector<int>> edges = { {2, 3}, {3, 1}, {4, 0}, {4, 1}, {5, 0}, {5, 1} };
	std::vector<std::vector<int>> adjList = makeAdjList(edges, nrNodes);
	int startingNode = 0;
	containsCycle(startingNode, adjList, nrNodes);

	return 0;
}