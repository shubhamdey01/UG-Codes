/************************************************************************************************************************
Name : Shubham Dey
Program : Write a C program to sort all the data in a binary search tree either in ascending order or in descending order.
Program No. : 012
Date : 07.05.2022
*************************************************************************************************************************/

#include <stdio.h>
#include <stdlib.h>

struct node
{
	int data;
	struct node *left, *right;
};
typedef struct node tree;

tree *insert(tree *bst, int val);
void inorder(tree *bst);
void revinorder(tree *bst);

int main()
{
	tree *root = NULL;
	int ch, num;
    do
    {
        printf("\n1. Insert Element\n");
        printf("2. Ascending Order\n");
        printf("3. Decending Order\n");
        printf("4. Exit\n");

        printf("\nEnter your choice :\t");
        scanf("%d",&ch);

        switch(ch)
        {
            case 1:
                printf("\nEnter value to be inserted :\t");
                scanf("%d",&num);
                root = insert(root, num);
                break;
            case 2:
                printf("\nAscending Order :\n");
                inorder(root);
                printf("\n");
                break;
            case 3:
                printf("\nDecending Order :\n");
                revinorder(root);
                printf("\n");
                break;
            case 4:
                break;
            default :
                printf("\nPlease enter correct choice\n");
                break;
        }
    } while(ch != 4);

	return 0;
}

tree *insert(tree *bst, int val)
{
	if(bst == NULL)
	{
		tree * new = (tree*)calloc(1,sizeof(tree));
		new->data = val;
		new->left = new->right = NULL;
		return new;
	}
	else
	{
		if(bst->data > val)
			bst->left = insert(bst->left, val);
		else
			bst->right = insert(bst->right, val);
	}
	return bst;
}

void inorder(tree *bst)
{
	if(bst != NULL)
	{
		inorder(bst->left);
		printf("%d  ",bst->data);
		inorder(bst->right);
	}
}

void revinorder(tree *bst)
{
	if(bst != NULL)
	{
		revinorder(bst->right);
		printf("%d  ",bst->data);
		revinorder(bst->left);
	}
}
