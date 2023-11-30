/********************************************
Name : Shubham Dey
Program : Implement Queue using linked list
********************************************/

#include <stdio.h>
#include <stdlib.h>

void enqueue(int num);
int dequeue();
int peek();
void display();

struct linked_list
{
    int data;
    struct linked_list *next;
};
typedef struct linked_list queue;

queue *front = NULL, *rear = NULL;

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
            default :
                printf("\nPlease enter correct choice\n");
                break;
        }
    } while(ch != 5);
    return 0;
}

void enqueue(int num)
{
    queue *ptr = (queue*)malloc(sizeof(queue));
    ptr->data = num;
    ptr->next = NULL;
    if(front == NULL)
        front = ptr;
    else
        rear->next = ptr;
    rear = ptr;
}

int dequeue()
{
    if(front == NULL)
    {
        printf("\nQueue Underflow.\n");
        return -999;
    }
    queue *ptr = front;
    int val = ptr->data;
    front = front->next;
    free(ptr);
    return  val;
}

int peek()
{
    if(front == NULL)
    {
        printf("\nQueue is Empty.\n\n");
        return -999;
    }
    return front->data;
}

void display()
{
    if(front == NULL)
    {
        printf("\nQueue is Empty.\n\n");
        return;
    }
    printf("\nItems of the Queue are :\n");
    if(front == rear)
        printf("%d  <- FRONT & REAR\n",front->data);
    else
    {
        queue *ptr = front->next;
        printf("%d  <- FRONT\n",front->data);
        while (ptr->next != NULL)
        {
            printf("%d\n",ptr->data);
            ptr = ptr->next;
        }
        printf("%d  <- REAR\n",rear->data);
    }
}