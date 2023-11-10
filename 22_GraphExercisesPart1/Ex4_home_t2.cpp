#include<iostream>
#include<vector>

class Solution
{
public:
	std::vector<int> findRedundantConnection(std::vector<std::vector<int>>& edges)
	{
		int nrNodes = edges.size();
		std::vector<int> parent(nrNodes + 1, 0);

		for (int currentNode = 1; currentNode <= nrNodes; currentNode++)
		{
			parent[currentNode] = currentNode;
		}

		std::vector<int> result;

		for (int i = 0; i < edges.size(); i++)
		{
			int firstNode = edges[i][0];
			int secondNode = edges[i][1];

			int parentFirstNode = findParent(firstNode, parent);
			int parentSecondNode = findParent(secondNode, parent);

			if (parentFirstNode == parentSecondNode)
			{
				result = edges[i];
			}

			parent[parentFirstNode] = parentSecondNode;
		}

		return result;
	}

	int findParent(int node, std::vector<int>& parent)
	{
		if (parent[node] == node)
		{
			return node;
		}

		return parent[node] = findParent(parent[node], parent);
	}
};

int main()
{
	Solution solution;

	// Test case 1
	std::vector<std::vector<int>> edges1 = { {1, 2}, {1, 3}, {2, 3} };
	std::vector<int> redundantConnection1 = solution.findRedundantConnection(edges1);
	std::cout << "Redundant connection: " << redundantConnection1[0] << " " << redundantConnection1[1] << std::endl;

	// Test case 2
	std::vector<std::vector<int>> edges2 = { {1, 2}, {2, 3}, {3, 4}, {1, 4}, {1, 5} };
	std::vector<int> redundantConnection2 = solution.findRedundantConnection(edges2);
	std::cout << "Redundant connection: " << redundantConnection2[0] << " " << redundantConnection2[1] << std::endl;

	// Test case 3
	std::vector<std::vector<int>> edges3 = { {1, 2}, {2, 3}, {3, 1} };
	std::vector<int> redundantConnection3 = solution.findRedundantConnection(edges3);
	std::cout << "Redundant connection: " << redundantConnection3[0] << " " << redundantConnection3[1] << std::endl;

	return 0;
}