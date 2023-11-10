#include <iostream>
#include <vector>
#include <queue>
#include <limits>


int networkDelayTime(std::vector<std::vector<int>>& times, int n, int k)
{
	// Step 1: Create a graph data structure
	int size = n + 1;
	std::vector<std::vector<std::pair<int, int>>> graph(size);
	for (const auto& time : times)
	{
		int source = time[0];
		int target = time[1];
		int weight = time[2];
		graph[source].emplace_back(target, weight);
	}

	// Step 2: Initialize distance array
	std::vector<int> distance(size, std::numeric_limits<int>::max());
	distance[k] = 0;

	// Step 3: Create a priority queue
	std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<>> pq;
	pq.push({ 0, k });

	// Step 5: Dijkstra's algorithm
	while (!pq.empty())
	{
		int node = pq.top().second;
		int dist = pq.top().first;
		pq.pop();

		if (dist > distance[node])
		{
			continue;
		}

		for (const auto& neighbor : graph[node])
		{
			int neighborNode = neighbor.first;
			int neighborDist = neighbor.second;

			if (dist + neighborDist < distance[neighborNode])
			{
				distance[neighborNode] = dist + neighborDist;
				pq.push({ distance[neighborNode], neighborNode });
			}
		}
	}

	// Step 6: Check if all nodes can receive the signal
	for (int i = 1; i <= n; i++)
	{
		if (distance[i] == std::numeric_limits<int>::max())
		{
			return -1;
		}
	}

	// Step 7: Return the maximum distance in the distance array
	int maxDistance = 0;
	for (int i = 1; i <= n; i++)
	{
		maxDistance = std::max(maxDistance, distance[i]);
	}
	return maxDistance;
}

int main()
{
	std::vector<std::vector<int>> times = { {2, 1, 1}, {2, 3, 1}, {3, 4, 1} };
	int n = 4;
	int k = 2;

	int minTime = networkDelayTime(times, n, k);
	std::cout << "Minimum time for all nodes to receive the signal: " << minTime << std::endl;

	return 0;
}