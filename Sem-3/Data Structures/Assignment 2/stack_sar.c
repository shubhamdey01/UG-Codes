/********************************************
Name : Shubham Dey
Program : Implement Stack using static array
********************************************/

#include <stdio.h>

#define MAX 10

void push(int num);
int pop();
int peek();
void display();

int st[MAX], top = -1;

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
    if(top == MAX-1)
    {
        printf("\nStack Overflow\n");
        return;
    }
    top++;
    st[top] = num;
}

int pop()
{
    if(top == -1)
    {
        printf("Stack Underflow.\n");
        return -999;
    }

    int val = st[top];
    top--;
    return val;
}

int peek()
{
    if(top == -1)
    {
        printf("\nStack is Empty.\n\n");
        return -999;
    }
    return st[top];
}

void display()
{
    if(top == -1)
    {
        printf("\nStack is Empty.\n\n");
        return;
    }
    printf("\nItems of the Stack are :\n");
    printf("%d\t<-TOP\n",st[top]);
    for(int i=top-1; i>=0; i--)
        printf("%d\n",st[i]);
    printf("\n");
}