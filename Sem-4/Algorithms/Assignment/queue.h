#include <stdio.h>
#include <stdlib.h>
 
// A linked list (LL) node to store a queue entry
struct QNode {
    int key;
    struct QNode* next;
};
 
// The queue, front stores the front node of LL and rear stores the
// last node of LL
typedef struct {
    struct QNode *front, *rear;
}Queue;
 
// A utility function to create a new linked list node.
struct QNode* newNode(int k)
{
    struct QNode* temp = (struct QNode*)malloc(sizeof(struct QNode));
    temp->key = k;
    temp->next = NULL;
    return temp;
}
 
// A utility function to create an empty queue
Queue* createQueue()
{
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->front = q->rear = NULL;
    return q;
}
 
// The function to add a key k to q
void enQueue(Queue* q, int k)
{
    // Create a new LL node
    struct QNode* temp = newNode(k);
 
    // If queue is empty, then new node is front and rear both
    if (q->rear == NULL) {
        q->front = q->rear = temp;
        return;
    }
 
    // Add the new node at the end of queue and change rear
    q->rear->next = temp;
    q->rear = temp;
}
 
// Function to remove a key from given queue q
void deQueue(Queue* q)
{
    // If queue is empty, return NULL.
    if (q->front == NULL)
        return;
 
    // Store previous front and move front one node ahead
    struct QNode* temp = q->front;
 
    q->front = q->front->next;
 
    // If front becomes NULL, then change rear also as NULL
    if (q->front == NULL)
        q->rear = NULL;
 
    free(temp);
}
int peek(Queue *q)
{
    if(q->front == NULL)
    {
        printf("\nQueue is Empty.\n\n");
        return -999;
    }
    return q->front->key;
}
void disp(Queue q)
{
    if(q->front == NULL)
    {
        printf("\nQueue is Empty.\n\n");
        return;
    }
    printf("\nItems of the Queue are :\n");
    if(q->front == q->rear)
        printf("%d  <- FRONT & REAR\n",q->front->key);
    else
    {
        Queue *ptr = q->front->next;
        printf("%d  <- FRONT\n",q->front->key);
        while (ptr->next != NULL)
        {
            printf("%d\n",ptr->key);
            ptr = ptr->next;
        }
        printf("%d  <- REAR\n",q->rear->key);
    }
}