/***************************************************************************************************
Name : Shubham Dey
Program : Write a C/C++ program to find all the paths between any two vertices of a connected graph.
Program No. : 017
Date : 03.06.2022
****************************************************************************************************/

#include <iostream>
#include <list>
using namespace std;

class Graph {
	int V;
	list<int>* adj;

	void findAllPaths(int, int, bool[], int[], int&);

public:
	Graph(int V);
	void addEdge(int u, int v);
	void printAllPaths(int s, int d);
};

int main()
{
	int v,x;
	int s,d;
	cout<<"Enter no. of vertices :\t";
	cin>>v;
	Graph g(v);
	cout<<"Enter adjacency list (-1 at end):"<<endl;
	for(int i=0; i<v; i++)
	{
		cout<<i<<" -> ";
		cin>>x;
		while(x != -1)
		{
			g.addEdge(i,x);
			cin>>x;
		}
	}
	cout<<"Enter source and destination :\n";
	cin>>s>>d;
	cout << "Following are all different paths from " << s << " to " << d << endl;
	g.printAllPaths(s, d);

	return 0;
}

Graph::Graph(int V)
{
	this->V = V;
	adj = new list<int>[V];
}

void Graph::addEdge(int u, int v)
{
	adj[u].push_back(v);
}

void Graph::printAllPaths(int s, int d)
{
	bool* visited = new bool[V];

	int* path = new int[V];
	int index = 0;

	for (int i = 0; i < V; i++)
		visited[i] = false;

	findAllPaths(s, d, visited, path, index);
}

void Graph::findAllPaths(int u, int d, bool visited[], int path[], int& index)
{
	visited[u] = true;
	path[index] = u;
	index++;

	if (u == d) {
		for (int i = 0; i < index; i++)
			cout << path[i] << " ";
		cout << endl;
	}
	else
	{
		list<int>::iterator i;
		for (i = adj[u].begin(); i != adj[u].end(); ++i)
			if (!visited[*i])
				findAllPaths(*i, d, visited, path, index);
	}

	index--;
	visited[u] = false;
}

// OUTPUT
/*
Enter no. of vertices :	7
Enter adjacency list (-1 at end):
0 -> 1 2 3 5 -1
1 -> 0 3 4 -1
2 -> 0 4 -1
3 -> 0 1 -1
4 -> 1 2 5 6 -1
5 -> 0 4 6 -1
6 -> 4 5 -1
Enter source and destination :
1 4
Following are all different paths from 1 to 4
1 0 2 4 
1 0 5 4 
1 0 5 6 4 
1 3 0 2 4 
1 3 0 5 4 
1 3 0 5 6 4 
1 4 
*/