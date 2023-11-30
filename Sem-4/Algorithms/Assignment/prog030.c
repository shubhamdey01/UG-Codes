/**********************************************************************
Name : Shubham Dey
Program : Write a C program to implement KMP String Matching algorithm.
Program No. : 030
Date : 03.07.2022
***********************************************************************/

#include <stdio.h>
#include <stdlib.h>

void prefix(char* pat, int m, int* pi);
void KMPSearch(char* pat, char* txt, int m, int n);

int main()
{
	char *txt, *pat;
	int n,m;
	printf("Enter the length of Text and Pattern :\n");
	scanf("%d %d",&n,&m);
	txt = (char*)calloc(n,sizeof(char));
	pat = (char*)calloc(m,sizeof(char));

	getchar();
	printf("Enter the Text :\t");
	scanf("%[^\n]",txt);
	getchar();
	printf("Enter the Pattern :\t");
	scanf("%[^\n]",pat);

	KMPSearch(pat, txt, m, n);
	return 0;
}

void prefix(char* pat, int m, int* pi)
{
	int len = 0;
	pi[0] = 0;
	int i = 1;
	while (i < m)
	{
		if (pat[i] == pat[len])
		{
			len++;
			pi[i] = len;
			i++;
		}
		else
		{
			if (len != 0)
			{
				len = pi[len - 1];
			}
			else
			{
				pi[i] = 0;
				i++;
			}
		}
	}
}

void KMPSearch(char* pat, char* txt, int m, int n)
{
	int *pi = (int*)calloc(m, sizeof(int));
	int i = 0, j = 0;

	prefix(pat, m, pi);

	while (i < n)
	{
		if (pat[j] == txt[i])
		{
			j++;
			i++;
		}

		if (j == m)
		{
			printf("Found pattern at index %d\n", i-j);
			j = pi[j - 1];
		}
		else if (i < n && pat[j] != txt[i])
		{
			if (j != 0)
				j = pi[j - 1];
			else
				i = i + 1;
		}
	}
}
