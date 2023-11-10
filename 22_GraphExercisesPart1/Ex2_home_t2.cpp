#include <iostream>
#include <queue>

class Solution
{
public:

	bool canVisitAllRoomsBFS(std::vector<std::vector<int>>& rooms)
	{
		int nrNodes = rooms.size();
		std::vector<bool> visited(nrNodes, false);
		std::queue<int> nodesQueue;
		int startingNode = 0;
		nodesQueue.push(startingNode);
		visited[startingNode] = true;

		while (!nodesQueue.empty())
		{
			int currentNode = nodesQueue.front();
			nodesQueue.pop();

			for (int nextNodePos = 0; nextNodePos < rooms[currentNode].size(); ++nextNodePos)
			{
				int nextNode = rooms[currentNode][nextNodePos];
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
};

int main()
{
	std::vector<std::vector<int>> adjList = { { 1, 3 }, { 3, 0, 1 }, {2}, {0} };

	Solution solution;

	if (solution.canVisitAllRoomsBFS(adjList))
	{
		std::cout << "can visit all rooms" << std::endl;
	}
	else
	{
		std::cout << "cannot visit all rooms" << std::endl;
	}

	std::vector<std::vector<int>> adjList2 = { { 1 }, { 2 }, { 3 }, { } };

	if (solution.canVisitAllRoomsBFS(adjList2))
	{
		std::cout << "can visit all rooms" << std::endl;
	}
	else
	{
		std::cout << "cannot visit all rooms" << std::endl;
	}

	return 0;
}