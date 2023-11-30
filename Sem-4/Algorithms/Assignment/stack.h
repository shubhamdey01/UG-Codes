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