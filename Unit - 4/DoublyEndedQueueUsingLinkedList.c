#include<stdio.h>
#include"QueueBuildingBlock.c"

typedef QueueLL DoublyEndedQueue;

// Functions for Doubly Ended Queue - Array Based Implementation

void init(DoublyEndedQueue* q){
    initQueueLL(q);
    return;
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
// Generalised method for dequeueRear and dequeueFront, isFront = true (dequeue from front)
int dequeueDoublyEndedQueue(DoublyEndedQueue* dq, int isFront){
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

int front(DoublyEndedQueue* dq){
    if(dq->front == NULL && dq->rear == NULL){
        return -1;
    }
    return dq->front->data;
}
int rear(DoublyEndedQueue* dq){
    if(dq->front == NULL && dq->rear == NULL){
        return -1;
    }
    return dq->rear->data;
}


