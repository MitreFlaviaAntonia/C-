/*#include <iostream>
#include <vector>
#include <list>
#define MAX_VERTICES 50
using namespace std;

class GraphRecap
{
	// number of nodes
	int no_nodes;

	// number of edges
	int no_edges = 0;

	vector<list<int>> adj_list;

	int adj_matrix[MAX_VERTICES][MAX_VERTICES];

public:
	GraphRecap(int no_nodes);

	void addEdgeMatrix(int node_src, int node_des, int weight);
	void addEdgeList(int node_src, int node_des);
	void printAdjMatrix();
	void printAdjList();
	bool isCompleteGraphList();
	bool isCompleteGraphMatrix();
	int noConexCompoments();
	void DFS(int node_src, vector<bool>& visitedDFS);
};

GraphRecap::GraphRecap(int no_nodes)
{
	adj_list.resize(no_nodes);
	this->no_nodes = no_nodes;
	for (int i = 0; i < no_nodes; i++)
	{
		for (int j = 0; j < no_nodes; j++)
		{
			adj_matrix[i][j] = 0;
		}
	}
}

void GraphRecap::addEdgeMatrix(int node_src, int node_des, int weight)
{
	adj_matrix[node_src][node_des] = weight; //oriented
	adj_matrix[node_des][node_src] = weight; //adding this => unoriented
	no_edges++;
}

void GraphRecap::addEdgeList(int node_src, int node_des)
{
	adj_list[node_src].push_back(node_des); //oriented
	adj_list[node_des].push_back(node_src); //adding this => unoriented
}

void GraphRecap::printAdjMatrix()
{
	for (int i = 0; i < no_nodes; i++)
	{
		for (int j = 0; j < no_nodes; j++)
		{
			cout << adj_matrix[i][j] << " ";
		}
		cout << "\n";
	}
}

void GraphRecap::printAdjList()
{
	for (int i = 0; i < no_nodes; i++)
	{
		cout << i << " -> ";
		for (int elem : adj_list[i])
		{
			cout << elem << " ";
		}
		cout << "\n";
	}
}

bool GraphRecap::isCompleteGraphMatrix()
{
	for (int i = 0; i < no_nodes; i++)
	{
		for (int j = 0; j < no_nodes; j++)
		{
			if (i != j && adj_matrix[i][j] == 0)
			{
				return false;
			}
		}
	}
	return true;
}

bool GraphRecap::isCompleteGraphList()
{
	return true;
}

void GraphRecap::DFS(int node_src, vector<bool>& visitedDFS)
{
	visitedDFS[node_src] = true;
	cout << node_src << " ";

	for (int elem : adj_list[node_src])
	{
		if (!visitedDFS[elem])
		{
			DFS(elem, visitedDFS);
		}
	}
}

int GraphRecap::noConexCompoments()
{
	int no_comp = 0;
	vector<bool> visitedDFS(no_nodes);

	for (int i = 0; i < no_nodes; i++)
	{
		if (!visitedDFS[i])
		{
			DFS(i, visitedDFS);
			cout << "\n";
			no_comp++;
		}
		
	}

	DFS(0, visitedDFS);
	cout << "\nNr conex components " << no_comp;
	return no_comp;
}

int main()
{
	
	GraphRecap g(4);
	g.addEdgeMatrix(0, 1, -1);
	g.addEdgeMatrix(0, 2, 3);
	g.addEdgeMatrix(1, 2, 4);
	g.addEdgeMatrix(2, 0, -2);
	g.addEdgeMatrix(2, 3, 7);
	//g.addEdgeMatrix(3, 3, 6);
	g.addEdgeMatrix(0, 3, 2);
	g.addEdgeMatrix(1, 3, -3);

	cout << "Print Matrix: \n";
	g.printAdjMatrix();
	cout << "\n";

	if (g.isCompleteGraphMatrix())
	{
		cout << "yes, complete\n";
	}
	else
	{
		cout << "no, not complete\n";
	}

	GraphRecap g1(7);
	g1.addEdgeList(0, 1);
	g1.addEdgeList(0, 2);
	g1.addEdgeList(1, 2);
	g1.addEdgeList(2, 0);
	g1.addEdgeList(2, 3);
	g1.addEdgeList(3, 3);
	g1.addEdgeList(4, 5);
	g1.addEdgeList(6, 6);

	cout << "Print List: \n";
	g1.printAdjList();
	cout << "\n";

	g1.noConexCompoments();
	
	return 0;
}*/