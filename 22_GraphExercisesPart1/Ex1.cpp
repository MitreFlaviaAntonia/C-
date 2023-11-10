/*#include <iostream>
#include <vector>
#include <list>

class GraphRecap
{
	int no_nodes;
	std::vector<std::list<int>> adj_list;

public:
	GraphRecap(int no_nodes);

	void addEdgeList(int node_src, int node_des);
	void printAdjList();
	bool isCompleteGraphList();
};

GraphRecap::GraphRecap(int no_nodes)
{
	adj_list.resize(no_nodes);
	this->no_nodes = no_nodes;
}

void GraphRecap::addEdgeList(int node_src, int node_des)
{
	adj_list[node_src].push_back(node_des); 
	adj_list[node_des].push_back(node_src); 
}

void GraphRecap::printAdjList()
{
	for (int i = 0; i < no_nodes; i++)
	{
		std::cout << i << " -> ";
		for (int elem : adj_list[i])
		{
			std::cout << elem << " ";
		}
		std::cout << "\n";
	}
}

bool GraphRecap::isCompleteGraphList()
{
	int nrEdgesMax = no_nodes - 1;
	for (int currentNode = 0; currentNode < no_nodes; currentNode++)
	{
		if (adj_list[currentNode].size() != nrEdgesMax)
		{
			return false;
		}
	}
	return true;
}

int main()
{
	GraphRecap g(4);
	g.addEdgeList(0, 1);
	g.addEdgeList(0, 2);
	g.addEdgeList(1, 2);
	g.addEdgeList(2, 0);
	g.addEdgeList(2, 3);
	g.addEdgeList(3, 3);

	std::cout << "Adj List: \n";
	g.printAdjList();
	std::cout << "\n";

	if (g.isCompleteGraphList())
	{
		std::cout << "Complete graph\n";
	}
	else
	{
		std::cout << "Not complete graph\n\n";
	}

	GraphRecap g1(4);
	g1.addEdgeList(0, 1);
	g1.addEdgeList(0, 2);
	g1.addEdgeList(0, 3);
	g1.addEdgeList(1, 2);
	g1.addEdgeList(1, 3);
	g1.addEdgeList(2, 3);

	std::cout << "Adj List: \n";
	g1.printAdjList();
	std::cout << "\n";

	if (g1.isCompleteGraphList())
	{
		std::cout << "Complete graph\n";
	}
	else
	{
		std::cout << "Not complete graph\n";
	}

	return 0;
}*/