#include <iostream>
#include <vector>
#include <queue>
#include <limits>

class Solution
{
public:
	int findTheCity(int n, std::vector<std::vector<int>>& edges, int distanceThreshold)
	{
		// Step 1: Create a graph data structure
		std::vector<std::vector<std::pair<int, int>>> graph(n);
		for (const auto& edge : edges)
		{
			int from = edge[0];
			int to = edge[1];
			int weight = edge[2];
			graph[from].emplace_back(to, weight);
			graph[to].emplace_back(from, weight);
		}

		int minNeighbors = std::numeric_limits<int>::max();
		int cityWithMinNeighbors = -1;

		// Step 2: Iterate through each city as the starting point
		for (int startCity = 0; startCity < n; startCity++)
		{
			// Step 3: Initialize distance array
			std::vector<int> distance(n, std::numeric_limits<int>::max());
			distance[startCity] = 0;

			// Step 4: Create a priority queue
			std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<>> pq;
			pq.push({ 0, startCity });

			// Step 5: Dijkstra's algorithm
			while (!pq.empty())
			{
				int city = pq.top().second;
				int dist = pq.top().first;
				pq.pop();

				if (dist > distance[city])
				{
					continue;
				}

				for (const auto& neighbor : graph[city])
				{
					int neighborCity = neighbor.first;
					int neighborDist = neighbor.second;

					if (dist + neighborDist < distance[neighborCity])
					{
						distance[neighborCity] = dist + neighborDist;
						pq.push({ distance[neighborCity], neighborCity });
					}
				}
			}

			// Step 6: Count reachable cities within distance threshold
			int reachableCities = 0;
			for (int i = 0; i < n; i++)
			{
				if (i != startCity && distance[i] <= distanceThreshold)
				{
					reachableCities++;
				}
			}

			// Step 7: Update the city with the smallest number of reachable cities
			if (reachableCities <= minNeighbors)
			{
				minNeighbors = reachableCities;
				cityWithMinNeighbors = startCity;
			}
		}

		// Step 8: Return city with smallest number of reachable cities
		return cityWithMinNeighbors;
	}
};

int main()
{
	Solution solution;
	int n = 5;
	std::vector<std::vector<int>> edges = { {0, 1, 2}, {0, 4, 8}, {1, 2, 3}, {1, 4, 2}, {2, 3, 1}, {3, 4, 1} };
	int distanceThreshold = 2;

	int city = solution.findTheCity(n, edges, distanceThreshold);
	std::cout << "City with the smallest number of neighbors: " << city << std::endl;

	return 0;
}