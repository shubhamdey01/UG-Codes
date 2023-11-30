/*************************************************************************
Name : Shubham Dey
Program : Implement single circular linked list with associated operations
*************************************************************************/

#include <stdio.h>
#include <stdlib.h>

struct linked_list
{
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

int main()
{
	int ch;
	do
	{
		printf("\n\tSingle Circular Linked List\n");
		printf("\t===========================\n");
		printf("1. Create Linked List\n");
		printf("2. Display\n");
		printf("3. Insert at beginning\n");
		printf("4. Insert at end\n");
		printf("5. Insert after a node\n");
		printf("6. Delete from beginning\n");
		printf("7. Delete from end\n");
		printf("8. Delete a node\n");
		printf("9. Exit\n");

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
				break;
			default :
				printf("\nPlease enter correct choice.\n");
				break;
		}
	} while(ch!=9);
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
		create(list->next);
	}
	else
		list->next = head;
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
		printf("%d -> ",ptr->data);
		ptr = ptr->next;
	}
	printf("%d\n",ptr->data);
}

void insert_beg()
{
	node *ptr, *new;
	new = (node*)malloc(sizeof(node));
	printf("\nEnter data :");
	scanf("%d",&new->data);
	if(head==NULL)
    {
	    head = new;
	    head->next = head;
    }
    ptr = head;
    while (ptr->next != head)
        ptr = ptr->next;
    ptr->next = new;
    new->next = head;
    head = new;
	printf("\nOperation Successful.\n");
}

void insert_end()
{
	if(head==NULL)
	{
		insert_beg();
		return;
	}
	node *new, *ptr;
	new = (node*)malloc(sizeof(node));
	printf("\nEnter data :");
	scanf("%d",&new->data);
	ptr = head;
	while(ptr->next != head)
		ptr = ptr->next;
	ptr->next = new;
    new->next = head;
	printf("\nOperation Successful.\n");
}

void insert_a()
{
	if(head==NULL)
	{
		printf("\nList is empty.\n");
		return;
	}
	node *new, *ptr, *pptr;
	int num;
	new = (node*)malloc(sizeof(node));
	printf("\nEnter data :");
	scanf("%d",&new->data);
	printf("Enter the value after which the data has to be inserted :");
	scanf("%d",&num);
	pptr = head;
	ptr = pptr->next;
	while(pptr->data != num)
	{
		if(ptr == head)
		{
			printf("\nValue %d not found.\n",num);
			return;
		}
		pptr = ptr;
		ptr = ptr->next;
	}
	pptr->next = new;
	new->next = ptr;
	printf("\nOperation Successful.\n");
}

void delete_beg()
{
	if(head==NULL)
	{
		printf("\nList is empty.\n");
		return;
	}
	node *ptr = head;
	if(head->next == head)
    {
        printf("\nDeleted item is : %d\n",head->data);
        free(head);
	    head = NULL;
        return;
    }
    while (ptr->next != head)
        ptr = ptr->next;
    ptr->next = head->next;
    printf("\nDeleted item is : %d\n",head->data);
    free(head);
	head = ptr->next;
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
	node *ptr, *pptr;
	ptr = head;
	while(ptr->next != head)
	{
		pptr = ptr;
		ptr = ptr->next;
	}
	pptr->next = head;
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
	node *ptr, *pptr;
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
		pptr = ptr;
		ptr = ptr->next;
	}
	pptr->next = ptr->next;
	free(ptr);
	printf("\nOperation Successful.\n");
}