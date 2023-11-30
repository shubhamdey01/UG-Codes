/*********************************************************************************************
Name : Shubham Dey
Student ID No. : 03313052005
Q-12 : Write a program in C to create a Binary Search Tree and show its inorder tree traversal
Date : 30.06.2022
**********************************************************************************************/

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *left, *right;
} tree;

tree *insert(tree *bst, int val);
void inorder(tree *bst);

int main()
{
    tree *root = NULL;
    int ch, num;
    do
    {
        printf("\n1. Insert Element\n");
        printf("2. In-Order Traversal\n");
        printf("3. Exit\n");

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
                printf("\nIn-Order Traversal Sequence :\n");
                inorder(root);
                printf("\n");
                break;
            case 3:
                break;
            default :
                printf("\nPlease enter correct choice\n");
                break;
        }
    } while(ch != 3);

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

// OUTPUT
/*

1. Insert Element
2. In-Order Traversal
3. Exit

Enter your choice :	1

Enter value to be inserted :	10

1. Insert Element
2. In-Order Traversal
3. Exit

Enter your choice :	1

Enter value to be inserted :	6

1. Insert Element
2. In-Order Traversal
3. Exit

Enter your choice :	1

Enter value to be inserted :	12

1. Insert Element
2. In-Order Traversal
3. Exit

Enter your choice :	1

Enter value to be inserted :	33

1. Insert Element
2. In-Order Traversal
3. Exit

Enter your choice :	1

Enter value to be inserted :	0

1. Insert Element
2. In-Order Traversal
3. Exit

Enter your choice :	1

Enter value to be inserted :	6

1. Insert Element
2. In-Order Traversal
3. Exit

Enter your choice :	1

Enter value to be inserted :	-6

1. Insert Element
2. In-Order Traversal
3. Exit

Enter your choice :	1

Enter value to be inserted :	12

1. Insert Element
2. In-Order Traversal
3. Exit

Enter your choice :	2

In-Order Traversal Sequence :
-6  0  6  6  10  12  12  33  

1. Insert Element
2. In-Order Traversal
3. Exit

Enter your choice :	3

*/