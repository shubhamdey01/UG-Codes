/*******************************************************
Name : Shubham Dey
Program : Write a C program to implement Red-Black tree.
Program No. : 027
Date : 15.06.2022
********************************************************/

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
void fixup(node *z);
void leftRotate(node *x);
void rightRotate(node *x);

int main()
{
    NILL = malloc(sizeof(node));
    NILL->color = BLACK;

    ROOT = NILL;

    int ch, num;
    do
    {
        printf("\n1. Insert Element\n");
        printf("2. Display\n");
        printf("3. Exit\n");

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
                display(ROOT);
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

    fixup(z);
}

void fixup(node *z)
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

// OUTPUT
/*

1. Insert Element
2. Display
3. Exit

Enter your choice : 1

Enter value to be inserted :    96

1. Insert Element
2. Display
3. Exit

Enter your choice : 1

Enter value to be inserted :    90

1. Insert Element
2. Display
3. Exit

Enter your choice : 2

Preorder & Inorder Traversal of RBT (0->RED, 1->BLACK) :
96-(1)  90-(0)  
90-(0)  96-(1)  

1. Insert Element
2. Display
3. Exit

Enter your choice : 1

Enter value to be inserted :    85

1. Insert Element
2. Display
3. Exit

Enter your choice : 1

Enter value to be inserted :    80

1. Insert Element
2. Display
3. Exit

Enter your choice : 2

Preorder & Inorder Traversal of RBT (0->RED, 1->BLACK) :
90-(1)  85-(1)  80-(0)  96-(1)  
80-(0)  85-(1)  90-(1)  96-(1)  

1. Insert Element
2. Display
3. Exit

Enter your choice : 1

Enter value to be inserted :    75

1. Insert Element
2. Display
3. Exit

Enter your choice : 1

Enter value to be inserted :    70

1. Insert Element
2. Display
3. Exit

Enter your choice : 1

Enter value to be inserted :    65

1. Insert Element
2. Display
3. Exit

Enter your choice : 1

Enter value to be inserted :    60

1. Insert Element
2. Display
3. Exit

Enter your choice : 1

Enter value to be inserted :    55

1. Insert Element
2. Display
3. Exit

Enter your choice : 1  

Enter value to be inserted :    50

1. Insert Element
2. Display
3. Exit

Enter your choice : 2

Preorder & Inorder Traversal of RBT (0->RED, 1->BLACK) :
80-(1)  70-(1)  60-(0)  55-(1)  50-(0)  65-(1)  75-(1)  90-(1)  85-(1)  96-(1)  
50-(0)  55-(1)  60-(0)  65-(1)  70-(1)  75-(1)  80-(1)  85-(1)  90-(1)  96-(1)  

1. Insert Element
2. Display
3. Exit

Enter your choice : 3

*/