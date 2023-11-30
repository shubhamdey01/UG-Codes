/**********************************************************************************************************
Name : Shubham Dey
Program : Write a C program to implement inorder, preorder and postorder traversals in a binary search tree.
Program No. : 011
Date : 07.05.2022
***********************************************************************************************************/

#include <stdio.h>
#include <stdlib.h>

struct node
{
	int data;
	struct node *left, *right;
};
typedef struct node tree;

tree *insert(tree *bst, int val);
void preorder(tree *bst);
void inorder(tree *bst);
void postorder(tree *bst);

int main()
{
	tree *root = NULL;
	int ch, num;
    do
    {
        printf("\n1. Insert Element\n");
        printf("2. Pre-Order Traversal\n");
        printf("3. In-Order Traversal\n");
        printf("4. Post-Order Traversal\n");
        printf("5. Exit\n");

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
            	printf("\nPre-Order Traversal Sequence :\n");
                preorder(root);
                printf("\n");
                break;
            case 3:
                printf("\nIn-Order Traversal Sequence :\n");
                inorder(root);
                printf("\n");
                break;
            case 4:
                printf("\nPost-Order Traversal Sequence :\n");
                postorder(root);
                printf("\n");
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

void preorder(tree *bst)
{
	if(bst != NULL)
	{
		printf("%d  ",bst->data);
		preorder(bst->left);
		preorder(bst->right);
	}
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

void postorder(tree *bst)
{
	if(bst != NULL)
	{
		postorder(bst->left);
		postorder(bst->right);
		printf("%d  ",bst->data);
	}
}
