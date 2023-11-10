/*#include <iostream>
#include <vector>

int findCenter(std::vector<std::vector<int>>& edges)
{
	int nrEdges = edges.size();
	
	std::vector<int> edgesCnt;

	for (int i = 0; i < nrEdges; i++)
	{
		if (std::max(edges[i][0] + 1, edges[i][1] + 1) > edgesCnt.size())
		{
			edgesCnt.resize(std::max(edges[i][0] + 1, edges[i][1] + 1));
		}
		edgesCnt[edges[i][0]]++;
		edgesCnt[edges[i][1]]++;
	}

	int maxCnt = 0;
	int maxNode = 0;
	for (int i = 0; i < edgesCnt.size(); i++)
	{
		if (edgesCnt[i] > maxCnt)
		{
			maxCnt = edgesCnt[i];
			maxNode = i;
		}
	}

	return maxNode;
}

int main()
{
	std::vector<std::vector<int>> edges = { {1,16},{16,2},{3,16},{4,16},{16,5},{16,6},{7,16},{16,8},{9,16},{10,16},{16,11},{12,16},{16,13},{16,14},{15,16},{16,17} };
	std::cout << "The center is node: " << findCenter(edges);

	return 0;
}*/