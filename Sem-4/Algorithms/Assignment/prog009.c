/***************************************************************************************************
Name : Shubham Dey
Program : Write a C program to implement inorder, preorder and postorder traversals in a binary tree.
Program No. : 009
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

tree *newNode(int val);
void preorder(tree *bst);
void inorder(tree *bst);
void postorder(tree *bst);

int main()
{
    tree *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);

    printf("\nPre-Order Traversal Sequence :\n");
    preorder(root);
    printf("\n");
    printf("\nIn-Order Traversal Sequence :\n");
    inorder(root);
    printf("\n");
    printf("\nPost-Order Traversal Sequence :\n");
    postorder(root);
    printf("\n");

    return 0;
}

tree *newNode(int val)
{
    tree *node = (tree*)malloc(sizeof(tree));
    node->data = val;
    node->left = NULL;
    node->right = NULL;
    return node;
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
