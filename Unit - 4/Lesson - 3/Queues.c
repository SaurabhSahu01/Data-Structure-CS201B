#include<stdio.h>
#include<stdlib.h>

/*
*   Doubly Ended Queue using Linked List - Start
*/

typedef struct Node{
    int data;
    struct Node* next;
    struct Node* prev;
}Node;

typedef struct {
    Node* front;
    Node* rear;
}DoublyEndedQueue;

void init(DoublyEndedQueue* dq){
    dq->front = dq->rear = NULL;
}

Node* createNode(int x){
    Node* newNode = (Node*)malloc(sizeof(Node));
    if(newNode != NULL){
        newNode->data = x;
        newNode->prev = newNode->next = NULL;
    }
    return newNode;
}

void enqueueFront(int elem, DoublyEndedQueue* dq){
    Node* newNode = createNode(elem);
    if(!newNode){
        printf("Queue Overflow\n");
        return;
    }
    // when queue is empty
    if(dq->front == NULL && dq->rear == NULL){
        dq->front = dq->rear = newNode;
        return;
    }
    newNode->next = dq->front;
    dq->front->prev = newNode;
    dq->front = newNode;
    return;
}

void enqueueRear(int elem, DoublyEndedQueue* dq){
    Node* newNode = createNode(elem);
    if(!newNode){
        printf("Queue Overflow\n");
        return;
    }
    // when queue is empty
    if(dq->front == NULL && dq->rear == NULL){
        dq->front = dq->rear = newNode;
        return;
    }
    newNode->prev = dq->rear;
    dq->rear->next = newNode;
    dq->rear = newNode;
    return;
}

int dequeueFront(DoublyEndedQueue* dq){
    // check if queue is empty
    if(dq->front == NULL && dq->rear == NULL){
        printf("Queue underflow\n");
        return -1;
    }
    // check single element condition
    if(dq->front == dq->rear){
        Node* temp = dq->front;
        int tempData = temp->data;
        dq->front = dq->rear = NULL;
        free(temp);
        return tempData;
    }
    Node* temp = dq->front;
    int tempData = temp->data;
    dq->front = temp->next;
    dq->front->prev = NULL;
    temp->next = NULL;
    free(temp);
    return tempData;
}
int dequeueRear(DoublyEndedQueue* dq){
    // check if queue is empty
    if(dq->front == NULL && dq->rear == NULL){
        printf("Queue underflow\n");
        return -1;
    }
    // check single element condition
    if(dq->front == dq->rear){
        Node* temp = dq->front;
        int tempData = temp->data;
        dq->front = dq->rear = NULL;
        free(temp);
        return tempData;
    }
    Node* temp = dq->rear;
    int tempData = temp->data;
    dq->rear = temp->prev;
    dq->rear->next = NULL;
    temp->prev = NULL;
    free(temp);
    return tempData;
}
int dequeue(DoublyEndedQueue* dq, int isFront){
    // check if queue is empty
    if(dq->front == NULL && dq->rear == NULL){
        printf("Queue underflow\n");
        return -1;
    }
    // check single element condition
    if(dq->front == dq->rear){
        Node* temp = dq->front;
        int tempData = temp->data;
        dq->front = dq->rear = NULL;
        free(temp);
        return tempData;
    }
    int tempData;
    if(isFront){
        Node* temp = dq->front;
        tempData = temp->data;
        dq->front = temp->next;
        dq->front->prev = NULL;
        temp->next = NULL;
        free(temp);
    }
    else{
        Node* temp = dq->rear;
        tempData = temp->data;
        dq->rear = temp->prev;
        dq->rear->next = NULL;
        temp->prev = NULL;
        free(temp);
    }
    return tempData;
}

int isEmpty(DoublyEndedQueue* dq){
    return (dq->front == NULL && dq->rear == NULL);
}

void display(DoublyEndedQueue* dq){
    // check empty queue condition
    if(dq->front == NULL && dq->rear == NULL){
        printf("Queue is empty\n");
        return;
    }
    Node* temp = dq->front;
    while(temp != dq->rear){
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("%d \n", temp->data);
}

/*
*   Doubly Ended Queue using Linked List - End
*/