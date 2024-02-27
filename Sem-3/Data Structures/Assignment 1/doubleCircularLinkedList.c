/*************************************************************************
Name : Shubham Dey
Program : Implement double circular linked list with associated operations
*************************************************************************/

#include <stdio.h>
#include <stdlib.h>

struct linked_list
{
    struct linked_list *prev;
    int data;
    struct linked_list *next;
} *head = NULL;
typedef struct linked_list node;

void create(node *list);
void display();
void insert_beg();
void insert_end();
void insert_a();
void delete_beg();
void delete_end();
void delete_node();
void reverse();

int main()
{
    int ch;
    do
    {
        printf("\n\tDouble Circular Linked List\n");
        printf("\t===========================\n");
        printf("1. Create Linked List\n");
        printf("2. Display\n");
        printf("3. Insert at beginning\n");
        printf("4. Insert at end\n");
        printf("5. Insert after a node\n");
        printf("6. Delete from beginnings\n");
        printf("7. Delete from end\n");
        printf("8. Delete a node\n");
        printf("9. Display list in reverse\n");
        printf("0. Exit\n");

        printf("\nEnter your choice :");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                head = (node*)malloc(sizeof(node));
                create(head);
                break;
            case 2:
                display();
                break;
            case 3:
                insert_beg();
                break;
            case 4:
                insert_end();
                break;
            case 5:
                insert_a();
                break;
            case 6:
                delete_beg();
                break;
            case 7:
                delete_end();
                break;
            case 8:
                delete_node();
                break;
            case 9:
                reverse();
                break;
            case 0:
                break;
            default :
                printf("\nPlease enter correct choice.\n");
                break;
        }
    } while(ch != 0);
    return 0;
}

void create(node *list)
{
    char ch;
    printf("\nEnter data :");
    scanf("%d",&list->data);
    do
    {
        printf("Want to enter more data (y/n) :");
        getchar();
        scanf("%c",&ch);
    } while(ch!='y' && ch!='Y' && ch!='n' && ch!='N');
    if(ch=='y' || ch=='Y')
    {
        list->next = (node*)malloc(sizeof(node));
        list->next->prev = list;
        create(list->next);
    }
    else
    {
        list->next = head;
        head->prev = list;
    }
}

void display()
{
    if(head==NULL)
    {
        printf("\nList is empty.\n");
        return;
    }
    node *ptr = head;
    printf("\nItems of the linked list:\n");
    while(ptr->next != head)
    {
        printf("%d  ",ptr->data);
        ptr = ptr->next;
    }
    printf("%d\n",ptr->data);
}

void insert_beg()
{
    node *new = (node*)malloc(sizeof(node));
    printf("\nEnter data :");
    scanf("%d",&new->data);
    if(head==NULL)
    {
        head = new;
        head->next = head;
        head->prev = head;
    }
    else
    {
        head->prev->next = new;
        new->prev = head->prev;
        new->next = head;
        head->prev = new;
        head = new;
    }
    printf("\nOperation Successful.\n");
}

void insert_end()
{
    if(head==NULL)
    {
        insert_beg();
        return;
    }
    node *new = (node*)malloc(sizeof(node));
    printf("\nEnter data :");
    scanf("%d",&new->data);
    head->prev->next = new;
    new->next = head;
    new->prev = head->prev;
    head->prev = new;
    printf("\nOperation Successful.\n");
}

void insert_a()
{
    if(head==NULL)
    {
        printf("\nList is empty.\n");
        return;
    }
    node *new, *ptr;
    int num;
    new = (node*)malloc(sizeof(node));
    printf("\nEnter data :");
    scanf("%d",&new->data);
    printf("Enter the value after which the data has to be inserted :");
    scanf("%d",&num);
    ptr = head;
    while(ptr->data != num)
    {
        if(ptr->next == head)
        {
            printf("\nValue %d not found.\n",num);
            return;
        }
        ptr = ptr->next;
    }
    new->prev = ptr;
    new->next = ptr->next;
    ptr->next->prev = new;
    ptr->next = new;
    printf("\nOperation Successful.\n");
}

void delete_beg()
{
    if(head==NULL)
    {
        printf("\nList is empty.\n");
        return;
    }
    if(head->next == head)
    {
        printf("\nDeleted item is : %d\n",head->data);
        free(head);
        head = NULL;
        return;
    }
    else
    {
        node *ptr = head;
        head->prev->next = head->next;
        head->next->prev = head->prev;
        head = head->next;
        printf("\nDeleted item is : %d\n",ptr->data);
        free(ptr);
    }
}

void delete_end()
{
    if(head==NULL)
    {
        printf("\nList is empty.\n");
        return;
    }
    if(head->next==head)
    {
        delete_beg();
        return;
    }
    node *ptr = head->prev;
    ptr->prev->next = head;
    head->prev = ptr->prev;
    printf("\nDeleted item is : %d\n",ptr->data);
    free(ptr);
}

void delete_node()
{
    if(head==NULL)
    {
        printf("\nList is empty.\n");
        return;
    }
    node *ptr;
    int num;
    printf("\nEnter the value of the node to be deleted :");
    scanf("%d",&num);
    ptr = head;
    if(ptr->data == num)
    {
        delete_beg();
        return;
    }
    while(ptr->data != num)
    {
        if(ptr->next == head)
        {
            printf("\nValue %d not found.\n",num);
            return;
        }
        ptr = ptr->next;
    }
    ptr->prev->next = ptr->next;
    ptr->next->prev = ptr->prev;
    free(ptr);
    printf("\nOperation Successful.\n");
}

void reverse()
{
    if(head==NULL)
    {
        printf("\nList is empty.\n");
        return;
    }
    node *ptr = head->prev;
    printf("\nItems of the linked list in reverse order :\n");
    while(ptr->prev != head->prev)
    {
        printf("%d  ",ptr->data);
        ptr = ptr->prev;
    }
    printf("%d\n",ptr->data);
}
