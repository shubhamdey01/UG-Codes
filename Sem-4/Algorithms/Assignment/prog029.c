/**********************************************************************
Name : Shubham Dey
Program : Write a C program to implement Naive String Matching algorithm.
Program No. : 029
Date : 03.07.2022
***********************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void search(char* pat, char* txt);

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

	search(pat, txt);

	return 0;
}

void search(char* pat, char* txt)
{
	int M = strlen(pat);
	int N = strlen(txt);

	for (int i = 0; i <= N - M; i++)
	{
		int j;
		for (j = 0; j < M; j++)
			if (txt[i + j] != pat[j])
				break;

		if (j == M)
			printf("Pattern found at index %d \n", i);
	}
}
