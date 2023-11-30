// Linked List Sorting and Inserting

#include<stdio.h>
#include<stdlib.h>

struct linked_list
{
	int num;
	struct linked_list *next;
};
typedef struct linked_list NODE;

NODE *mem_alloc(void);
void create(NODE *lst);
void display(NODE *lst);
void sort(NODE *lst);
void swap(NODE *l1,NODE *l2);
NODE *insert(NODE *lst,int x);

void main()
{
	NODE *head;
	int n;

	head = mem_alloc();
	printf("Input data for the linked-list :\n");
	create(head);
	printf("\nUnsorted linked-list :\n");
	display(head);
	sort(head);
	printf("\nSorted linked-list :\n");
	display(head);
	printf("\nEnter number to be inserted :\t");
	scanf("%d",&n);
	head = insert(head,n);
	printf("\nSorted linked-list (After inserting) :\n");
	display(head);
}

NODE *mem_alloc(void)
{
	NODE *lst = (NODE*)calloc(1,sizeof(NODE));
	if (lst==NULL)
	{
		printf("Error\n");
		exit(0);
	}
}
void create(NODE *lst)
{
	static int i=1;
	char ch;

	printf("Enter a number [%d] :\t",i);
	scanf("%d",&lst->num);
	printf("Want to enter more numbers ? (y/n) :\t");
	getchar();
	scanf("%c",&ch);
	if(ch=='Y' || ch=='y')
	{
		lst->next = mem_alloc();
		i++;
		create(lst->next);
	}
}
void display(NODE *lst)
{
	if(lst->next != NULL)
	{
		printf("%d -> ",lst->num);
		if(lst->next->next == NULL)
		{
			printf("%d\n",lst->next->num);
			return;
		}
		display(lst->next);
	}
	else
		printf("%d\n",lst->num);
}
void sort(NODE *lst)
{
	int flag=1;
    NODE *p;

    while(flag)
    {
        flag = 0;
        p = lst;
        while (p->next != NULL)
        {
            if (p->num > p->next->num)
            {
                swap(p, p->next);
                flag = 1; 
            }
            p = p->next;
        }
    }
}
void swap(NODE *l1,NODE *l2)
{
	int temp = l1->num;
	l1->num = l2->num;
	l2->num = temp;
}
NODE *insert(NODE *lst,int x)
{
	NODE *p,*p1,*p2;

	p1 = NULL;
	p2 = lst;
	for(;p2->num < x;p2=p2->next)
	{
		p1 = p2;
		if(p2->next->next == NULL)
		{
			p1 = p2->next;
			p2 = NULL;
			break;
		}
	}
	p = mem_alloc();
	p->num = x;
	p->next = p2;
	if(p1==NULL)
		lst = p;
	else
		p1->next = p;
	return lst;
}
