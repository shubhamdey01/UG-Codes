/**********************************************************************
Name : Shubham Dey
Program : Write a C program to delete an element from a Red-Black tree.
Program No. : 028
Date : 16.06.2022
***********************************************************************/

#include <stdio.h>
#include <stdlib.h>

#define RED 0
#define BLACK 1

typedef struct node{
    int key, color;
    struct node *parent, *left, *right;
} node;

node *ROOT;
node *NILL;

void display(node *root);
void preorder(node* root);
void inorder(node* root);
void insert(int key);
void insertFixup(node *z);
void leftRotate(node *x);
void rightRotate(node *x);
node *search(int key);
node *min(node *x);
void delete(node *z);
void deleteFixup(node *x);
void transplant(node *u, node *v);

int main()
{
    NILL = malloc(sizeof(node));
    NILL->color = BLACK;

    ROOT = NILL;

    int ch, num;
    do
    {
        printf("\n1. Insert Element\n");
        printf("2. Delete\n");
        printf("3. Display\n");
        printf("4. Exit\n");

        printf("\nEnter your choice :\t");
        scanf("%d",&ch);

        switch(ch)
        {
            case 1:
                printf("\nEnter value to be inserted :\t");
                scanf("%d",&num);
                insert(num);
                break;
            case 2:
                printf("\nEnter value to be deleted :\t");
                scanf("%d",&num);
                delete(search(num));
                break;
            case 3:
                display(ROOT);
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

void display(node *root)
{
    if(root == NILL)
    {
        printf("\nRBT is empty.\n");
        return;
    }
    printf("\nPreorder & Inorder Traversal of RBT (0->RED, 1->BLACK) :\n");
    preorder(root);
    printf("\n");
    inorder(root);
    printf("\n");
}

void preorder(node* root)
{
    if (root == NILL)
        return;
    printf("%d-(%d)  ", root->key,root->color);
    preorder(root->left);
    preorder(root->right);
}

void inorder(node* root)
{
    if (root == NILL)
        return;
    inorder(root->left);
    printf("%d-(%d)  ", root->key,root->color);
    inorder(root->right);
}

void insert(int key)
{
    node *z, *x, *y;
    z = malloc(sizeof(node));

    z->key = key;
    z->color = RED;
    z->left = NILL;
    z->right = NILL;

    x = ROOT;
    y = NILL;

    while(x != NILL)
    {
        y = x;
        if(z->key <= x->key)
        {
            x = x->left;
        }
        else{
            x = x->right;
        }
    }

    if(y == NILL)
    {
        ROOT = z;
    }
    else if(z->key <= y->key)
    {
        y->left = z;
    }
    else{
        y->right = z;
    }

    z->parent = y;

    insertFixup(z);
}

void insertFixup(node *z)
{
    while(z->parent->color == RED)
    {
        if(z->parent == z->parent->parent->left)
        {
            if(z->parent->parent->right->color == RED)
            {
                z->parent->color = BLACK;
                z->parent->parent->right->color = BLACK;
                z->parent->parent->color = RED;
                z = z->parent->parent;
            }

            else{
                if(z == z->parent->right)
                {
                    z = z->parent;
                    leftRotate(z);
                }

                z->parent->color = BLACK;
                z->parent->parent->color = RED;
                rightRotate(z->parent->parent);
            }
        }

        else{
            if(z->parent->parent->left->color == RED)
            {
                z->parent->color = BLACK;
                z->parent->parent->left->color = BLACK;
                z->parent->parent->color = RED;
                z = z->parent->parent;
            }

            else{
                if(z == z->parent->left)
                {
                    z = z->parent;
                    rightRotate(z);
                }

                z->parent->color = BLACK;
                z->parent->parent->color = RED;
                leftRotate(z->parent->parent);
            }
        }
    }

    ROOT->color = BLACK;
}

void leftRotate(node *x)
{
    node *y;
    
    y = x->right;
    x->right = y->left;
    if(y->left != NILL)
    {
        y->left->parent = x;
    }

    y->parent = x->parent;
    if(y->parent == NILL)
    {
        ROOT = y;
    }
    else if(x == x->parent->left)
    {
        x->parent->left = y;
    }
    else{
        x->parent->right = y;
    }
    
    y->left = x;
    x->parent = y;
}

void rightRotate(node *x)
{
    node *y;

    y = x->left;
    x->left = y->right;
    if(y->right != NILL)
    {
        y->right->parent = x;
    }

    y->parent = x->parent;
    if(y->parent == NILL)
    {
        ROOT = y;
    }
    else if(x == x->parent->left)
    {
        x->parent->left = y;    
    }
    else{
        x->parent->right = y;
    }

    y->right = x;
    x->parent = y;
}

node *search(int key){
    node *x;

    x = ROOT;
    while(x != NILL && x->key != key){
        if(key < x->key){
            x = x->left;
        }
        else{
            x = x->right;
        }
    }

    return x;
}

node *min(node *x){
    while(x->left != NILL){
        x = x->left;
    }
    return x;
}

void delete(node *z){
    node *y, *x;
    int yOriginalColor;

    y = z;
    yOriginalColor = y->color;

    if(z->left == NILL){
        x = z->right;
        transplant(z, z->right);
    }
    else if(z->right == NILL){
        x = z->left;
        transplant(z, z->left);
    }
    else{
        y = min(z->right);
        yOriginalColor = y->color;

        x = y->right;

        if(y->parent == z){
            x->parent = y;
        }
        else{
            transplant(y, y->right);
            y->right = z->right;
            y->right->parent = y;
        }

        transplant(z, y);
        y->left = z->left;
        y->left->parent = y;
        y->color = z->color;
    }

    if(yOriginalColor == BLACK){
        deleteFixup(x);
    }
}

void deleteFixup(node *x){
    node *w; 

    while(x != ROOT && x->color == BLACK){
        
        if(x == x->parent->left){
            w = x->parent->right;

            if(w->color == RED){
                w->color = BLACK;
                x->parent->color = RED;
                leftRotate(x->parent);
                w = x->parent->right;
            }

            if(w->left->color == BLACK && w->right->color == BLACK){
                w->color = RED;
                x->parent->color = BLACK;
                x = x->parent;
            }
            else{

                if(w->right->color == BLACK){
                    w->color = RED;
                    w->left->color = BLACK;
                    rightRotate(w);
                    w = x->parent->right;
                }

                w->color = x->parent->color;
                x->parent->color = BLACK;
                x->right->color = BLACK;
                leftRotate(x->parent);
                x = ROOT;       

            }

        }
        else{
            w = x->parent->left;

            if(w->color == RED){
                w->color = BLACK;
                x->parent->color = BLACK;
                rightRotate(x->parent);
                w = x->parent->left;
            }

            if(w->left->color == BLACK && w->right->color == BLACK){
                w->color = RED;
                x->parent->color = BLACK;
                x = x->parent;
            }
            else{

                if(w->left->color == BLACK){
                    w->color = RED;
                    w->right->color = BLACK;
                    leftRotate(w);
                    w = x->parent->left;
                }

                w->color = x->parent->color;
                x->parent->color = BLACK;
                w->left->color = BLACK;
                rightRotate(x->parent);
                x = ROOT;

            }
        }

    }

    x->color = BLACK;
}

void transplant(node *u, node *v){
    if(u->parent == NILL){
        ROOT = v;
    }
    else if(u == u->parent->left){
        u->parent->left = v;
    }
    else{
        u->parent->right = v;
    }

    v->parent = u->parent;
}
