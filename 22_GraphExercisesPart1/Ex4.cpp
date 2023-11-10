/*#include <iostream>
#include <list>
#include <queue>
#include <utility>
#include <vector>

bool validPath(int nrEdges, std::vector<std::vector<int>>& edges, int source, int destination)
{
	std::vector<std::vector<int>> adjacencyList(nrEdges);

	for (int edge = 0; edge < edges.size(); edge++)
	{
		int firstNode = edges[edge][0];
		int secondNode = edges[edge][1];
		adjacencyList[firstNode].push_back(secondNode);
		adjacencyList[secondNode].push_back(firstNode);
	}

	std::vector<bool> visited(nrEdges, false);
	visited[source] = true;

	std::queue<int> nodesQueue;
	nodesQueue.push(source);

	while (!nodesQueue.empty())
	{
		int currentNode = nodesQueue.front();
		nodesQueue.pop();

		if (currentNode == destination)
		{
			return true;
		}

		for (int nextNodePos = 0; nextNodePos < adjacencyList[currentNode].size(); nextNodePos++)
		{
			int nextNode = adjacencyList[currentNode][nextNodePos];
			if (!visited[nextNode])
			{
				visited[nextNode] = true;
				nodesQueue.push(nextNode);
			}
		}
	}

	return false;
}

int main()
{
	int nrEdges = 3;
	std::vector<std::vector<int>> edges = { { 0, 1 }, { 1, 2 }, { 2, 0 } };
	int source = 0;
	int destination = 2;
	std::cout << validPath(nrEdges, edges, source, destination);
}*/