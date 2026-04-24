#include<stdlib.h>

// Node structure required to make the nodes of the linked list ( Used in linked list implementation of queues )
typedef struct Node{
    int data;
    struct Node* next;
    struct Node* prev;
}Node;

Node* createNode(int x){
    Node* newNode = (Node*)malloc(sizeof(Node));
    if(newNode == NULL){
        return NULL;
    }
    newNode->data = x;
    newNode->next = newNode->prev = NULL;
    return newNode;
}


/* Array Based Implementation */
#define QUEUE_MAX_SIZE 50

typedef struct {
    int front; // variable to point to the front element of the queue
    int rear; // variable to point to the rear element of the queue
    int* queue; // queue array to store the elements
}QueueArray;

void initQueueArray(QueueArray* q){
    q->front = q->rear = -1; // Initial condition of the queue, both rear and front points to -1
    q->queue = (int*)malloc(QUEUE_MAX_SIZE*sizeof(int)); // create a dynamic array of size = QUEUE_MAX_SIZE
}

/* Linked-List Based Implementation */
typedef struct {
    Node* front; // pointer to point to the front element of the queue ( in the linked list )
    Node* rear; // pointer to point to the rear element of the queue ( in the linked list )
}QueueLL;

void initQueueLL(QueueLL* q){
    q->front = q->rear = NULL; // Initial condition of the queue, both the rear and front pointer points to the NULL
}