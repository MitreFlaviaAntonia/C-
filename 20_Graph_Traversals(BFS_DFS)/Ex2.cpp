#include <iostream>
#include <vector>
#include <list>
#include <queue>

std::vector<std::list<int>> makeAdjList(std::vector<int> nodes) //makes an adjacency list using the vector and the conditions given
{
	std::vector<std::list<int>> adjList(nodes.size());
	for (int i = 0; i < nodes.size(); i++)
	{
		for (int j = 0; j < nodes.size(); j++)
		{
			if (abs(j - i) == 1 || (nodes[i] == nodes[j] && i != j))
			{
				adjList[i].push_back(j);
			}
		}
	}
	return adjList;
}

int minJumps(std::vector<int>& nodes)
{
	std::vector<bool> visited(nodes.size(), false);
	std::vector<std::list<int>> adjList = makeAdjList(nodes);
	std::queue<int> nodesQueue;
	std::vector<int> jumps(nodes.size(), 0);  // stores the number of jumps to each node
	int current = 0;
	nodesQueue.push(current);

	while (!nodesQueue.empty())
	{
		current = nodesQueue.front();

		for (auto it = adjList[current].begin(); it != adjList[current].end(); ++it) //iterates through every current node's adj list
		{
			if (visited[*it] == false)
			{
				visited[*it] = true;
				nodesQueue.push(*it);
				jumps[*it] = jumps[current] + 1;

				if (*it == adjList.size() - 1)
				{
					return jumps[current] + 1;
				}
			}
		}
		nodesQueue.pop();
	}
	return -1;
}

int main()
{
	std::vector<int> arr = { 100, -23, -23, 404, 100, 23, 23, 23, 3, 404, 23, 23, 23, 3, 342 };
	int result = minJumps(arr);
	std::cout << "Minimum number of jumps: " << result << std::endl;
	return 0;
}