/************************************************************************************************************
Name : Shubham Dey
Program : Write a C/C++ program to find a spanning tree from a connected graph by using Breadth First Search.
Program No. : 014
Date : 01.06.2022
**************************************************************************************************************/

#include <iostream>
#include <queue>
#include "matrix.h"

void spanningBFS(int **adj, bool *v, int a, int n, int **spTree);
bool check(int n, bool *v);

using namespace std;

int main()
{
	int n, a, **adj, **spTree;

	cout<< "Enter no. of vertices :\t";
	cin >> n;

	bool v[n] = {false};
	adj = memalloc(n,n);
	spTree = memalloc(n,n);

	cout<< "Enter the adjacency matrix for the graph :\n";
	input(n, n, adj);
	cout<<"Enter the starting vertex :\t";
	cin>> a;

	spanningBFS(adj, v, a, n, spTree);

	if(check(n, v))
	{
		cout<<"Adjacency matrix for spanning tree using DFS :\n";
		display(n,n,spTree);
	}
	else
		cout<<"The given graph is not connected.";

	return 0;
}

void spanningBFS(int **adj, bool *v, int a, int n, int **spTree)
{
	queue<int> q;
	v[a] = true;
	q.push(a);
	while(!q.empty())
	{
		a = q.front();
		q.pop();

		for(int i=0; i<n; i++)
			if(adj[a][i]==1 && v[i] == false)
			{
				v[i] = true;
				q.push(i);
				spTree[a][i] = 1;
			}
	}
}

bool check(int n, bool *v)
{
	for(int i=0; i<n; i++)
		if(!v[i])
			return false;
	return true;
}

// OUTPUT
/*
Enter no. of vertices :	5
Enter the adjacency matrix for the graph :
0 1 0 1 0
1 0 1 0 1
0 1 0 0 0
1 0 0 0 1
0 1 0 1 0
Enter the starting vertex :	4
Adjacency matrix for spanning tree using DFS :
    0    0    0    0    0
    1    0    1    0    0
    0    0    0    0    0
    0    0    0    0    0
    0    1    0    1    0
*/