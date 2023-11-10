#include <iostream>
#include <vector>
#include <queue>
#include <stack>

//BFS
bool canVisitAllNodesBFS(std::vector<std::vector<int>> adjList, int  nrNodes, int startingNode)
{
    std::vector<bool> visited(nrNodes, false); //the vector that stores if the nodes were visited or not, is initialized with false for all the nodes, as, first, none of them is visited
    std::queue<int> nodesQueue;
    nodesQueue.push(startingNode); //inserting the starting node in the queue
    visited[startingNode] = true; //the starting node is visited

	while (!nodesQueue.empty())
    {
		int currentNode = nodesQueue.front(); // the current node is
        nodesQueue.pop();

		for (int nextNodePos = 0; nextNodePos < adjList[currentNode].size(); ++nextNodePos)
        {
            int nextNode = adjList[currentNode][nextNodePos];
			if (visited[nextNode] == 0)
            {
                nodesQueue.push(nextNode);
				visited[nextNode] = true;
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

//DFS
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

int main()
{
    std::vector<std::vector<int>> adjList = { { 1, 2 }, { 0, 3, 2 }, {0, 1}, {1} };
    int nrNodes = 4;
    int startingNode = 0;
    if (canVisitAllNodesBFS(adjList, nrNodes, startingNode))
    {
        std::cout << "yes" << std::endl;
    }
    else
    {
        std::cout << "no" << std::endl;
    }

	if (canVisitAllNodesDFS(adjList, nrNodes, startingNode))
	{
		std::cout << "yes" << std::endl;
	}
	else
	{
		std::cout << "no" << std::endl;
	}

    return 0;
}