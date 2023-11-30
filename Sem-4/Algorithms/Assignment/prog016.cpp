/************************************************************************************************************************
Name : Shubham Dey
Program : Write a C/C++ program to find a minimal spanning tree from a weighted connected graph by Prim's algorithm.
Program No. : 016
Date : 02.06.2022
*************************************************************************************************************************/

#include <iostream>
#include <climits>
#include "matrix.h"

using namespace std;

int V, **adj;

typedef struct {
   int a, b, w;
}edge;

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
            cout << "Edge: " << edges[i].a << "--" << edges[i].b;
            cout << "  Weight: " << edges[i].w << endl;
            t += edges[i].w;
         }
         cout << "Total Weight: " << t << endl;
      }
      friend void prims(Tree &tre, int start);
};

int main()
{
   int a;
   cout<<"No. of vertices :\t";
   cin>>V;
   adj = memalloc(V,V);
   cout<<"Enter the adjacency matrix for the graph :"<<endl;
   input(V,V,adj);
   cout<<"Enter starting vertex :\t";
   cin>>a;
   cout<<"\nMinimum Spanning Tree :"<<endl;

   Tree tr;
   prims(tr, a);
   tr.printEdges();
   return 0;
}

void prims(Tree &tr, int start)
{
   int usedVert[V], unusedVert[V];
   int i, j, min, p;
   edge ed;

   usedVert[0] = start; p = 1;
   unusedVert[0] = -1;

   for(i = 1; i<V; i++)
   {
      usedVert[i] = -1;
      unusedVert[i] = i;
   }

   tr.n = 0;
   while(p != V)
   {
      min = INT_MAX;
      for(i = 0; i<p; i++)
      {
         for(j = 0; j<V; j++)
         {
            if(unusedVert[j] != -1)
            {
               if(min > adj[i][j] && adj[i][j] != 0)
               {
                  min = adj[i][j];
                  ed.a = i; ed.b = j; ed.w = min;
               }
            }
         }
      }
      unusedVert[ed.b] = -1;
      tr.addEdge(ed);
      usedVert[p] = ed.a; p++;
   }
}

// OUTPUT
/*
No. of vertices : 7
Enter the adjacency matrix for the graph :
0 1 3 4 0 5 0
1 0 0 7 2 0 0
3 0 0 0 8 0 0
4 7 0 0 0 0 0
0 2 8 0 0 2 4
5 0 0 0 2 0 3
0 0 0 0 4 3 0
Enter starting vertex : 5

Minimum Spanning Tree :
Edge: 0--1  Weight: 1
Edge: 1--4  Weight: 2
Edge: 0--2  Weight: 3
Edge: 0--3  Weight: 4
Edge: 4--5  Weight: 2
Edge: 5--6  Weight: 3
Total Weight: 15
*/