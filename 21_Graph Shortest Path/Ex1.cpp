#include <iostream>
#include <climits>
#include <list>
#include <stack>
#include <vector>
#include <utility>

void topologicalSort(int currentNode, bool visited[], std::stack<int>& nodesStack, std::vector<std::vector<std::pair<int, int>>> adjList, int nrNodes)
{
	visited[currentNode] = true;
	
	for (int nextNodePos = 0; nextNodePos < adjList[currentNode].size(); ++nextNodePos)
	{
		if (!adjList[currentNode].empty())
		{
			if (visited[adjList[currentNode][nextNodePos].first] == false)
			{
				topologicalSort(adjList[currentNode][nextNodePos].first, visited, nodesStack, adjList, nrNodes);
			}
		}
	}

	nodesStack.push(currentNode);
}

void longestPath(int startingNode, std::vector<std::vector<std::pair<int, int>>> adjList, int nrNodes)
{
	std::stack<int> nodesStack;
	std::vector<int> dist(nrNodes, INT_MIN);

	bool* visited = new bool[nrNodes];
	for (int currentNode = 0; currentNode < nrNodes; currentNode++)
	{
		visited[currentNode] = false;
	}

	for (int currentNode = 0; currentNode < nrNodes; currentNode++)
	{
		if (visited[currentNode] == false)
		{ 
			topologicalSort(currentNode, visited, nodesStack, adjList, nrNodes);
		}
	}

	dist[startingNode] = 0;

	while (nodesStack.empty() == false)
	{
		int currentNode = nodesStack.top();
		nodesStack.pop();		
		if (dist[currentNode] != INT_MIN)
		{
			for (int nextNodePos = 0; nextNodePos < adjList[currentNode].size(); ++nextNodePos)
			{
				if (dist[adjList[currentNode][nextNodePos].first] < dist[currentNode] + adjList[currentNode][nextNodePos].second)
				{
					dist[adjList[currentNode][nextNodePos].first] = dist[currentNode] + adjList[currentNode][nextNodePos].second;
				}
			}
		}
	}

	for (int i = 0; i < nrNodes; i++)
	{
		if (dist[i] == INT_MIN)
		{
			std::cout << "INF ";
		}
		else
		{
			std::cout << dist[i] << " ";
		}
	}

	delete[] visited;
}

int main()
{
	std::vector<std::vector<std::pair<int, int>>> adjList =
	{
	   {{1, 5}, {2, 3}}, //0
	   {{3, 6}, {2, 2}}, //1
	   {{4, 4}, {5, 2}, {3, 7}}, //2
	   {{5, 1}, {4, -1}}, //3
	   {{5, -2}}, //4
	   {}, //5
	};
	
	int startingNode = 1;
	int nrNodes = adjList.size();
	std::cout << "Following are longest distances from source vertex " << startingNode << " \n";
	longestPath(startingNode, adjList, nrNodes);

	return 0;
}