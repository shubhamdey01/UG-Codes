/***********************************************************************************************
Name : Shubham Dey
Program : Write a C program to implement parenthesization problem. (Matrix chain multiplication)
Program No. : 026
Date : 08.06.2022
************************************************************************************************/

#include <stdio.h>
#include<limits.h>
#include "matrix.h"

void matmultiply(int **m, int **s, int*p, int n);
void print_optimal(int **s, int i, int j);

void main()
{
	int n, i, j, k, **m, **s, *p;
	printf("Enter the no. of matrices: ");
	scanf("%d",&n);

	m = memalloc(n,n);
	s = memalloc(n,n);
	p = (int*)calloc(n+1,sizeof(int));

	for(i=0;i<n;i++)
		for(j=i+1;j<n;j++)
		{
			m[i][i]=0;
			m[i][j]=INT_MAX;
			s[i][j]=0;
		}
	printf("\nEnter the dimensions: \n");
	for(k=0;k<=n;k++)
	{
		printf("P%d: ",k);
		scanf("%d",&p[k]);
	}

	matmultiply(m, s, p, n);

	printf("\nMinimum number of multiplications is : %d ",m[0][n-1]);
	printf("\nMultiplication Sequence : ");
	print_optimal(s, 0, n-1);
}

void matmultiply(int **m, int **s, int*p, int n)
{
	int i, j, k, q;
	for(i=n-1;i>=0;i--)
	{
		for(j=i;j<n;j++)
		{
			if(i==j)
				m[i][j]=0;
			else
			{
				for(k=i;k<j;k++)
				{
					q=m[i][k]+m[k+1][j]+p[i]*p[k+1]*p[j+1];
					if(q<m[i][j])
					{
						m[i][j]=q;
						s[i][j]=k;
					}
				}
			}
		}
	}
}

void print_optimal(int **s, int i, int j)
{
	if (i == j)
		printf(" A%d ",i);
	else
	{
		printf("( ");
		print_optimal(s, i, s[i][j]);
		print_optimal(s, s[i][j]+1, j);
		printf(" )");
	}
}
