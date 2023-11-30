/********************************************
Name : Shubham Dey
Program : Implement Stack using linked list
********************************************/

#include <stdio.h>
#include <stdlib.h>

void push(int num);
int pop();
int peek();
void display();

struct linked_list
{
    int data;
    struct linked_list *next;
};
typedef struct linked_list stack;

stack *top = NULL;

int main()
{

    int ch, num;
    do
    {
        printf("\n\tStack Operations\n");
        printf("\t================\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exit\n");

        printf("\nEnter your choice :\t");
        scanf("%d",&ch);

        switch(ch)
        {
            case 1:
                printf("\nEnter value to be pushed :\t");
                scanf("%d",&num);
                push(num);
                break;
            case 2:
                num = pop();
                if(num != -999)
                    printf("\nPoped item is : %d\n",num);
                break;
            case 3:
                num = peek();
                if(num != -999)
                    printf("\nItem at top of stack is : %d\n",num);
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

void push(int num)
{
    stack *ptr = (stack*)malloc(sizeof(stack));
    ptr->data = num;
    if(top == NULL)
        ptr->next = NULL;
    else
        ptr->next = top;
    top = ptr;
}

int pop()
{
    if(top == NULL)
    {
        printf("Stack Underflow.\n");
        return -999;
    }
    stack *ptr = top;
    int val = ptr->data;
    top = top->next;
    free(ptr);
    return  val;
}

int peek()
{
    if(top == NULL)
    {
        printf("\nStack is Empty.\n\n");
        return -999;
    }
    return top->data;
}

void display()
{
    if(top == NULL)
    {
        printf("\nStack is Empty.\n\n");
        return;
    }
    printf("\nItems of the Stack are :\n");
    printf("%d  <-TOP\n",top->data);
    if(top->next != NULL)
    {
        stack *ptr = top->next;
        while (ptr != NULL)
        {
            printf("%d\n",ptr->data);
            ptr = ptr->next;
        }
        printf("\n");
    }
}