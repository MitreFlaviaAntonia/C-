/*include <iostream>
#include <vector>
#include <list>
using namespace std;

class GraphRecap
{
	// number of nodes
	int no_nodes;

	// number of edges
	int no_edges = 0;

	vector<list<int>> adj_list;

	int adj_matrix[50][50];

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
	bool DFS_ex2(int node_src, vector<int>& visitedDFS);
	bool BFS_ex1(int node_src, vector<bool>& visitedBFS);
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
	//adj_list[node_des].push_back(node_src); //adding this => unoriented
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

bool GraphRecap::DFS_ex2(int node_src, vector<int>& visitedDFS) //returns if a node is in a cycle or not
{
	if (visitedDFS[node_src] == 2) //this node is part of a cycle (was visited twice)
	{
		return false;
	}

	if (visitedDFS[node_src] == 1) //this node was visited once
	{
		return true;
	}

	visitedDFS[node_src] = 1;

	for (int elem : adj_list[node_src])
	{
		if (DFS_ex2(elem, visitedDFS))
		{
			return true;
		}
	}

	visitedDFS[node_src] = 2;
	return false;
}

bool GraphRecap::BFS_ex1(int node_src, vector<bool>& visitedBFS) //checks if a graph is bipartite or not = 2 seturi independente de noduri
{
	list<int> queue;

	vector<int> colored(no_nodes);

	visitedBFS[node_src] = true;
	queue.push_back(node_src);
	colored[node_src] = 1;

	while (!queue.empty())
	{
		node_src = queue.front();
		cout << node_src << " ";
		queue.pop_front();
		for (int adjacent : adj_list[node_src])
		{
			if (!visitedBFS[adjacent])
			{
				visitedBFS[adjacent] = true;
				queue.push_back(adjacent);
				if (colored[node_src] == 1)
				{
					colored[adjacent] = 2;
				}
				else
				{
					colored[adjacent] = 1;
				}
			}
			else if (colored[node_src] == colored[adjacent])
			{
				return false;
			}
		}
	}

	return true;
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

	cout << "EX 1" << endl << endl;
	bool ok = true;
	
	int no_nodes = 6;
	GraphRecap g(no_nodes);
	g.addEdgeList(0, 1);
	g.addEdgeList(0, 3);
	g.addEdgeList(2, 3);
	g.addEdgeList(2, 1);
	g.addEdgeList(4, 5);

	vector<bool> visitedBFS;
	visitedBFS.resize(no_nodes, false);
	
	
	for (int i = 0; i < no_nodes; i++)
	{
		if (!visitedBFS[i])
		{
			if (!g.BFS_ex1(i, visitedBFS))
			{
				ok = false;
				break;
			}
		}
	}

	if (ok)
	{
		cout << "it is bipartite" << endl;
	}
	else
	{
		cout << "it is not bipartite" << endl;
	}
	
	//cout << endl;
	//cout << "EX 2" << endl << endl;

	int no_nodes = 6;
	GraphRecap g1(no_nodes);
	g1.addEdgeList(1, 0);
	g1.addEdgeList(0, 3);
	g1.addEdgeList(3, 2);
	g1.addEdgeList(2, 1);
	g1.addEdgeList(4, 5);
	g1.addEdgeList(3, 4);

	vector<int> visitedDFS;
	visitedDFS.resize(no_nodes);
	bool ok = true;

	for (int i = 0; i < no_nodes; i++)
	{
		if (!visitedDFS[i])
		{
			ok = g1.DFS_ex2(i, visitedDFS);
		}
	}

	if (ok)
	{
		cout << "It has a cycle" << endl;
	}
	else
	{
		cout << "It has no cycle" << endl;
	}

	for (int i = 0; i < no_nodes; i++)
	{
		if (visitedDFS[i] == 2)
		{
			cout << i << " ";
		}
	}
	cout << "\n";

	return 0;
}*/