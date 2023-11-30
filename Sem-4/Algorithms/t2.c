#include<stdio.h>
#include<stdlib.h>


void main()
{
    int n,ar[10],x,i,j,temp;

    printf("How many numbers ?\t");
    scanf("%d",&n);

    printf("Enter %d numbers :\n",n);
    for(i=0;i<n;i++)
        scanf("%d",&ar[i]);

    printf("\nUnsorted array :\n");
    for(i=0;i<n;i++)
        printf("%d  ",ar[i]);
    printf("\n");

    for(i=0;i<n-1;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(ar[i]>ar[j])
            {
                temp = ar[i];
                ar[i] = ar[j];
                ar[j] = temp;
            }
        }
    }

    printf("\nSorted array :\n");
    for(i=0;i<n;i++)
        printf("%d  ",ar[i]);
    printf("\n");
}