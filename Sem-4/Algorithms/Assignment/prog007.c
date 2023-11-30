/************************************************************************************
Name : Shubham Dey
Program : Write a C program to find the determinant of a matrix by iterative approach.
Program No. : 007
Date : 05.05.2022
*************************************************************************************/

#include <stdio.h>
#include <stdlib.h>

float **memalloc(int m, int n);
void input(int m, int n, float **A);
void display(int m, int n, float **A);
float determinant(int n, float **A);
void swap(float **X, int m, int n);

int main()
{
	int r;
	float **A;

	printf("Enter no. of rows/columns for the matrix :\n");
	scanf("%d",&r);

	A = memalloc(r,r);

	printf("Enter elements for the matrix :\n");
	input(r,r,A);
	printf("\nGiven Matrix :\n");
	display(r,r,A);

	printf("\nDeterminant = %g\n",determinant(r,A));

	return 0;
}

float **memalloc(int m, int n)
{
	float **A = (float**)calloc(m,sizeof(float*));
	for(int i=0; i<m; i++)
		A[i] = (float*)calloc(n,sizeof(float));
	return A;
}

void input(int m, int n, float **A)
{
	for(int i=0; i<m; i++)
		for(int j=0; j<n; j++)
			scanf("%f",&A[i][j]);
}

void display(int m, int n, float **A)
{
	for(int i=0; i<m; i++)
	{
		for(int j=0; j<n; j++)
			printf("%5g",A[i][j]);
		printf("\n");
	}
}

float determinant(int n, float **A)
{
	int i, j, k, p;
	float a;
	float det = 1;

	for(j=0; j<n; j++)
	{
		if(A[j][j] == 0)
		{
			swap(A,j,n);
			det *= -1;
		}
		for(i=j+1; i<n; i++)
		{
			if(A[i][j] != 0)
			{
				a = A[i][j]/A[j][j];
				for(k=0; k<n; k++)
					A[i][k] -= a*A[j][k];
			}
		}
	}

	for(i=0; i<n; i++)
		det *= A[i][i];
	return det;
}

void swap(float **X, int m, int n)
{
	for(int i=m+1; i<n; i++)
	{
		if(X[i][m] != 0)
		{
			float *temp = X[i];
			X[i] = X[m];
			X[m] = temp;
			return;
		}
	}
	
}
