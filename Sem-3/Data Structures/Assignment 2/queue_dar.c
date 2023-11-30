/********************************************
Name : Shubham Dey
Program : Implement Queue using dynamic array
********************************************/

#include <stdio.h>
#include <stdlib.h>

void enqueue(int num);
int dequeue();
int peek();
void display();

int *qu, f=-1, r=-1, max;

int main()
{
    int ch, num;
    printf("Enter the maximum size of the queue :\t");
    scanf("%d",&max);
    qu = (int*)calloc(max,sizeof(int));
    do
    {
        printf("\n\tQueue Operations\n");
        printf("\t================\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exit\n");

        printf("\nEnter your choice :\t");
        scanf("%d",&ch);

        switch(ch)
        {
            case 1:
                printf("\nEnter value to be inserted :\t");
                scanf("%d",&num);
                enqueue(num);
                break;
            case 2:
                num = dequeue();
                if(num != -999)
                    printf("\nDeleted item is : %d\n",num);
                break;
            case 3:
                num = peek();
                if(num != -999)
                    printf("\nItem at front of queue is : %d\n",num);
                break;
            case 4:
                display();
                break;
            default :
                printf("\nPlease enter correct choice\n");
                break;
        }
    } while(ch != 5);

    return 0;
}

void enqueue(int num)
{
    if(r == max-1)
    {
        printf("\nQueue Overflow\n");
        return;
    }
    else if(f==-1 && r==-1)
        f = r = 0;
    else
        r++;
    qu[r] = num;
}

int dequeue()
{
    if(f == -1)
    {
        printf("\nQueue Underflow.\n");
        return -999;
    }

    int val = qu[f];
    f++;
    if(f>r)
        f = r = -1;
    return val;
}

int peek()
{
    if(f == -1)
    {
        printf("\nQueue is Empty.\n\n");
        return -999;
    }

    return qu[f];

}

void display()
{
    if(f == -1)
    {
        printf("\nQueue is Empty.\n\n");
        return;
    }
    printf("\nItems of the Queue are :\n");
    if(f==r)
        printf("%d\t<-FRONT & REAR\n",qu[f]);
    else
    {
        printf("%d\t<-FRONT\n",qu[f]);
        for(int i=f+1; i<r; i++)
            printf("%d\n",qu[i]);
        printf("%d\t<-REAR\n",qu[r]);
        printf("\n");
    }
}