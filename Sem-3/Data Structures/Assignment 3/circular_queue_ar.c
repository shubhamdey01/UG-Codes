/****************************************************
Name : Shubham Dey
Program : Implement Circular Queue using static array
****************************************************/

#include <stdio.h>

#define MAX 5

void enqueue(int num);
int dequeue();
int peek();
void display();

int queue[MAX], front = -1, rear = -1;

int main()
{
    int ch, num;
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
            case 5:
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
    if(front == 0 && rear == MAX-1 || front == rear+1)
    {
        printf("\nQueue Overflow !!\n");
        return;
    }
    else if(front == -1 && rear == -1)
        front = rear = 0;
    else if(rear == MAX-1 && front != 0)
        rear = 0;
    else
        rear++;
    queue[rear] = num;
}

int dequeue()
{
    if(front == -1 && rear == -1)
    {
        printf("\nQueue Underflow !!\n");
        return -999;
    }
    int val = queue[front];
    if(front == rear)
        front = rear = -1;
    else if(front == MAX-1)
        front = 0;
    else
        front++;
    return val;
}

int peek()
{
    if(front == -1 && rear == -1)
    {
        printf("\nQueue is Empty.\n\n");
        return -999;
    }
    return queue[front];
}

void display()
{
    if(front == -1 && rear == -1)
    {
        printf("\nQueue is Empty.\n\n");
        return;
    }
    printf("\nItems of the Queue are :\n");
    if(front == rear)
        printf("%d  <- FRONT & REAR\n",queue[front]);
    else if(front < rear)
    {
        printf("%d  <- FRONT\n",queue[front]);
        for(int i=front+1; i<rear; i++)
            printf("%d\n",queue[i]);
        printf("%d  <- REAR\n",queue[rear]);
    }
    else
    {
        printf("%d  <- FRONT\n",queue[front]);
        for(int i=front+1; i<=MAX-1; i++)
            printf("%d\n",queue[i]);
        for(int i=0; i<rear; i++)
            printf("%d\n",queue[i]);
        printf("%d  <- REAR\n",queue[rear]);
    }
}