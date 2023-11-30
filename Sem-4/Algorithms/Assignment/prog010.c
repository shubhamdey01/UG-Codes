/***************************************************************************************************
Name : Shubham Dey
Program : Write a C program to create a binary search tree. Then implement the following:
		a) insert an element b) delete an element c) search an element and show the result accordingly.
Program No. : 010
Date : 06.05.2022
****************************************************************************************************/

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
tree* delete(tree *bst, int val);
int search(tree *bst, int val);
tree *successor(struct node* node);

int main()
{
	tree *root = NULL;
	int ch, num;
    do
    {
        printf("\n1. Insert Element\n");
        printf("2. Delete Element\n");
        printf("3. Search Element\n");
        printf("4. Exit\n");

        printf("\nEnter your choice :\t");
        scanf("%d",&ch);

        switch(ch)
        {
            case 1:
                printf("\nEnter value to be inserted :\t");
                scanf("%d",&num);
                root = insert(root, num);
                printf("\nIn-order traversal result :\n");
                inorder(root);
    			printf("\n");
                break;
            case 2:
                printf("\nEnter value to be deleted :\t");
                scanf("%d",&num);
                root = delete(root, num);
                if(root == NULL)
                	printf("\nBST is empty.\n");
                else
                {
	                printf("\nIn-order traversal result :\n");
	                inorder(root);
	    			printf("\n");
	    		}
                break;
            case 3:
            	printf("\nEnter value to be searched :\t");
                scanf("%d",&num);
                if(search(root, num) == 1)
                	printf("\n%d is prensent in the BST.\n",num);
                else
                	printf("\n%d is not present in the BST.\n",num);
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

tree* delete(tree *bst, int val)
{
	if (bst == NULL)
	{
		printf("\n%d is not present in the BST.\n",val);
        return bst;
	}

    if (bst->data > val)
        bst->left = delete(bst->left, val);
    else if (bst->data < val)
        bst->right = delete(bst->right, val);
    else {
        if (bst->left == NULL) {
            struct node* temp = bst->right;
            free(bst);
            return temp;
        }
        else if (bst->right == NULL) {
            struct node* temp = bst->left;
            free(bst);
            return temp;
        }
        struct node* temp = successor(bst->right);
        bst->data = temp->data;
        bst->right = delete(bst->right, temp->data);
    }
    return bst;
}

int search(tree *bst, int val)
{
	if(bst == NULL)
		return 0;
	if(bst->data == val)
		return 1;
	else if(bst->data > val)
		return search(bst->left, val);
	else
		return search(bst->right, val);
}

tree *successor(struct node* node)
{
    struct node* temp = node;
    while (temp && temp->left != NULL)
        temp = temp->left;
 
    return temp;
}
