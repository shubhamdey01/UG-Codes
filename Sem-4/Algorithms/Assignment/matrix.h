// Header file for matrix operations

#include <stdio.h>
#include <stdlib.h>

int **memalloc(int m, int n)
{
	int **A = (int**)calloc(m,sizeof(int*));
	for(int i=0; i<m; i++)
		A[i] = (int*)calloc(n,sizeof(int));
	return A;
}

void input(int m, int n, int **A)
{
	for(int i=0; i<m; i++)
		for(int j=0; j<n; j++)
			scanf("%d",&A[i][j]);
}

void display(int m, int n, int **A)
{
	for(int i=0; i<m; i++)
	{
		for(int j=0; j<n; j++)
			printf("%5d",A[i][j]);
		printf("\n");
	}
}