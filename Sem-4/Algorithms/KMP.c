/********************************************************************************************************
 ********************************************************************************************************
 Name - Madhusdan chand
 Prog - Write a C program to implement KMP String Matching algorithm
 Date - 21/06/2022
 ********************************************************************************************************
*********************************************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void clean_stdin();
int getPatternSize(char *a);
int* compute_prefix_function(char *a);
void display(int *a,int n);
void kmpMatcher(char *a,char *b);

int main()
{
    char *a,*b;
    int *c;
    int n,m;

    printf("Enter a size of a string\n");
    scanf("%d",&n);

    printf("Enter a size for the pattern of for the following string\n");
    scanf("%d",&m);

    a=(char*)calloc(n,sizeof(char));
    b=(char*)calloc(m,sizeof(char));
    c=(int*)calloc(m,sizeof(int));
    if(a==NULL && b==NULL && c==NULL)
        printf("Insufficient Memory\n");
    else
    {
        clean_stdin();
        printf("Enter the text string\n");
        fgets(a,n,stdin);
        printf("Enter the pattern string\n");
        fgets(b,m,stdin);

       // getPatternSize(b);
        c=compute_prefix_function(b);
        printf("Pie Table\n");
        display(c,getPatternSize(b));
        kmpMatcher(a,b);
    }
    return 0;
}

void clean_stdin()
{
    int c;
    do {
        c = getchar();
    } while (c != '\n' && c != EOF);
}

int getPatternSize(char *a)
{
    int n=0;

    while(*a!='\0')
    {
        n++;
        a++;
    }
    return n;
}

int* compute_prefix_function(char *a)
{
    int m=getPatternSize(a),k=0;
    int *prefixarray=(int*)calloc(m,sizeof(m));

    prefixarray[0]=0;
    k=0;
    
    for(int i=1;i<m;i++)
    {
        if(a[i]==a[k])
        {
            k++;
            prefixarray[i]=k;
        }
        else
        {
            if(k!=0)
            {
                k=prefixarray[k-1];
                //i--;
            }
            else
                prefixarray[i]=0;
        }
    }
    return prefixarray;
}



void display(int *a,int n)
{
    for(int i=0;i<n-1;i++)
        printf("%d ",a[i]);
    printf("\n");
}


void kmpMatcher(char *a,char *b)
{
    int n=getPatternSize(a);
    int m=getPatternSize(b);

    int *test=(int*)calloc(m,sizeof(int));

    test=compute_prefix_function(b);
    int i=0,j=0;

    while(i<n)
    {
        if(a[i]==b[j])
        {
            i++;j++;
        }
        
        if(j==m-1)
        {
            printf("Location is %d start of pattern\n",i-j);
            j=test[j-1];
        }
        else if(i<n && b[j]!=a[i])
        {
            if(j!=0)
                j=test[j-1];
            else
                i++;
        }
    }
    
}

/*
Enter a size of a string
20
Enter a size for the pattern of for the following string
10
Enter the text string
aabbcdfffaaacdb
Enter the pattern string
aa
Pie Table
0 1 
Location is 0 start of pattern
Location is 9 start of pattern
Location is 10 start of pattern
*/
