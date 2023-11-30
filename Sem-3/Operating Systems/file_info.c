#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
	char str1[]="ls -l ", str2[15];
	strcpy(str2,argv[1]);
	strcat(str1,str2);
	puts(str1);
	system(str1);
	return 0;
}