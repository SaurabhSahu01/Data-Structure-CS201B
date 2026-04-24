#include<stdio.h>
#include"QueueBuildingBlock.c"

typedef QueueLL Queue;

// Functions for the Linked-List based Queue

void init(Queue* q){
    initQueueLL(q);
    return;
}

void enqueue(int x, Queue* q){
    // check for the overflow condition
    Node* newNode = createNode(x);
    // this is the overflow condition
    if(newNode == NULL){
        printf("Queue is overflow\n");
        return;
    }
    // check if the queue is empty
    if(q->front == NULL && q->rear == NULL){
        q->front = q->rear = newNode;
        return;
    }
    // else part, if above two conditions are false
    q->rear->next = newNode;
    q->rear = newNode;
    return;
}

int dequeue(Queue* q){
    // check for the underflow condition
    if(q->front == NULL && q->rear == NULL){
        printf("Queue is underflow\n");
        return -1; // Note to return that value which is not the part of your answer
    }
    int tempData = q->front->data;
    // check if there is only one element in the queue
    if(q->front == q->rear){
        free(q->front);
        q->front = q->rear = NULL; // Now the queue has become empty
    }
    else{
        Node* temp = q->front;
        q->front = temp->next;
        temp->next = NULL;
        free(temp);
    }
    return tempData;
}

int front(Queue* q){
    // check if the queue is already empty
    if(q->front == NULL && q->rear == NULL){
        printf("Queue is empty\n");
        return -1; // Note to return that value which not the part of your answer
    }
    return q->front->data;
}

int isEmpty(Queue* q){
    return (q->front == NULL && q->rear == NULL); // this is the only condition in linked list for an empty queue
}

void display(Queue* q){
    // check if the queue is empty
    if(q->front == NULL && q->rear == NULL){
        printf("Queue is empty. Nothing to display.\n");
        return;
    }
    Node* temp = q->front;
    while(temp != NULL){
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
    return;
}

