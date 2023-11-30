/************************************************************************************************************************
Name : Shubham Dey
Program : Write a C/C++ program to find a minimal spanning tree from a weighted connected graph by Kruskal's algorithm.
Program No. : 015
Date : 02.06.2022
*************************************************************************************************************************/

#include <iostream>
#include "matrix.h"

using namespace std;

typedef struct {
   int a, b, w;
}edge;

int V, **adj;

class Tree
{
	int n;
	edge *edges;
	public:
		Tree()
		{
			edges = (edge*)calloc(V-1,sizeof(edge));
			n = 0;
		}

		void addEdge(edge e)
		{
			edges[n] = e;
			n++;
		}

		void printEdges()
		{
			int t = 0;

			for(int i = 0; i<n; i++)
			{
				cout << "Edge: " << edges[i].a << "--" <<edges[i].b;
				cout << "  Weight: " << edges[i].w << endl;
				t += edges[i].w;
			}
			cout << "Total Weight: " << t << endl;
		}
};

class VSet
{
	int n;
	int *set;
	public:
		VSet()
		{
			set = (int*)calloc(V,sizeof(int));
			n = -1;
		}

		void addVertex(int vert)
		{
			set[++n] = vert;
		}

		int deleteVertex()
		{
			return set[n--];
		}

	friend int findVertex(VSet *vertSetArr, int vert);
	friend void merge(VSet &set1, VSet &set2);
};

void swapping(edge &e1, edge &e2);
int findEdge(edge *edgeList);
void sortEdge(edge *edgeList, int n);
void kruskal(Tree &tr);

int main()
{
	cout<<"No. of vertices :\t";
	cin>> V;

	adj = memalloc(V,V);
	cout<<"Enter the adjacency matrix for the graph :"<<endl;
	input(V,V,adj);
	cout<<"\nMinimum Spanning Tree :"<<endl;
	Tree tr;
	kruskal(tr);
	tr.printEdges();
}

void merge(VSet &set1, VSet &set2)
{
	while(set2.n >= 0)
		set1.addVertex(set2.deleteVertex());
}

int findVertex(VSet *vertSetArr, int vert)
{
	for(int i = 0; i<V; i++)
		for(int j = 0; j<=vertSetArr[i].n; j++)
			if(vert == vertSetArr[i].set[j])
				return i;
}

void swapping(edge &e1, edge &e2)
{
	edge temp;
	temp = e1;
	e1 = e2;
	e2 = temp;
}

int findEdge(edge *edgeList)
{
	int count = -1, i, j;
	for(i = 0; i<V; i++)
		for(j = 0; j<i; j++)
			if(adj[i][j] != 0)
			{
				count++;
				edgeList[count].a = i;
				edgeList[count].b = j;
				edgeList[count].w = adj[i][j];
			}
	return count+1;
}

void sortEdge(edge *edgeList, int n)
{
	int flag = 1, i, j;

	for(i = 0; i<(n-1) && flag; i++)
	{
		flag = 0;
		for(j = 0; j<(n-i-1); j++)
			if(edgeList[j].w > edgeList[j+1].w)
			{
				swapping(edgeList[j], edgeList[j+1]);
				flag = 1;
			}
	}
}

void kruskal(Tree &tr)
{
	int ecount, maxEdge = V*(V-1)/2;
	edge edgeList[maxEdge], ed;
	int uloc, vloc;
	VSet VSetArray[V];
	ecount = findEdge(edgeList);

	for(int i = 0; i < V; i++)
		VSetArray[i].addVertex(i);
	sortEdge(edgeList, ecount);
	int count = 0;

	while(count <= V-1)
	{
		ed = edgeList[count];
		uloc = findVertex(VSetArray, ed.a);
		vloc = findVertex(VSetArray, ed.b);

		if(uloc != vloc)
		{
			merge(VSetArray[uloc], VSetArray[vloc]);
			tr.addEdge(ed);
		}
		count++;
	}
}

// OUTPUT
/*
No. of vertices :	7
Enter the adjacency matrix for the graph :
0 1 3 4 0 5 0
1 0 0 7 2 0 0
3 0 0 0 8 0 0
4 7 0 0 0 0 0
0 2 8 0 0 2 4
5 0 0 0 2 0 3
0 0 0 0 4 3 0

Minimum Spanning Tree :
Edge: 1--0  Weight: 1
Edge: 4--1  Weight: 2
Edge: 5--4  Weight: 2
Edge: 2--0  Weight: 3
Edge: 6--5  Weight: 3
Edge: 3--0  Weight: 4
Total Weight: 15
*/