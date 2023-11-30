// DFS

#include <iostream>
#include "matrix.h"

void DFS(int **adj, bool *v, int a, int n);

using namespace std;

int main()
{
	int n, a, **adj;

	cout<< "Enter no. of vertices :\t";
	cin >> n;

	bool v[n] = {false};
	adj = memalloc(n,n);

	cout<< "Enter the adjacency matrix for the graph :\n";
	input(n, n, adj);
	cout<<"Enter the starting vertex :\t";
	cin>> a;

	printf("\nDepth First Search :\n");
	DFS(adj, v, a, n);

	return 0;
}

void DFS(int **adj, bool *v, int a, int n)
{
	v[a] = true;
			printf("%d ",a);
	for(int i=0; i<n; i++)
		if(adj[a][i]==1 && v[i] == false)
		{
			DFS(adj, v, i, n);
		}
}