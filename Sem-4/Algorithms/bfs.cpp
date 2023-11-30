// BFS

#include <iostream>
#include <queue>
#include "matrix.h"

void BFS(int **adj, bool *v, int a, int n);

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

	printf("\nBreadth First Search :\n");
	BFS(adj, v, a, n);

	return 0;
}

void BFS(int **adj, bool *v, int a, int n)
{
	queue<int> q;
	v[a] = true;
	q.push(a);
	while(!q.empty())
	{
		a = q.front();
		printf("%d ",a);
		q.pop();

		for(int i=0; i<n; i++)
			if(adj[a][i]==1 && v[i] == false)
			{
				v[i] = true;
				q.push(i);
			}
	}
}
