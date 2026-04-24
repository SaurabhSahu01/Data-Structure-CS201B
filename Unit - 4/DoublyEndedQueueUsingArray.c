#include<stdio.h>
#include"QueueBuildingBlock.c"

typedef QueueArray DoublyEndedQueue;

// Functions for Doubly Ended Queue - Array Based Implementation

void init(DoublyEndedQueue* q){
    initQueueArray(q);
    return;
}

void enqueueFront(int x, DoublyEndedQueue* q){
    int newFront = (q->front - 1 + QUEUE_MAX_SIZE) % QUEUE_MAX_SIZE;
    // check for the overflow condition
    if(newFront == q->rear){
        printf("Doubly Ended Queue is overflow.\n");
        return;
    }
    q->front = newFront;
    q->queue[q->front] = x;
    return;
}

void enqueueRear(int x, DoublyEndedQueue* q){
    int newRear = (q->rear + 1 + QUEUE_MAX_SIZE) % QUEUE_MAX_SIZE;
    // check for the overflow condition
    if(newRear == q->front){
        printf("Doubly Ended Queue is overflow.\n");
        return;
    }
    q->rear = newRear;
    q->queue[q->rear] = x;
    return;
}

int dequeueFront(DoublyEndedQueue* q){
    int tempData = -1;
    // check for the underflow condition
    if(q->front == -1 && q->rear == -1){
        printf("Doubly Ended Queue is underflow.\n");
        return tempData; // Note to return that value which is not the part of the answer
    }
    tempData = q->queue[q->front];
    // check if Queue has only one element
    if(q->front == q->rear){
        q->front = q->rear = -1;
        return tempData;
    }
    // update the front to delete the element from the front of the queue
    q->front = (q->front + 1 + QUEUE_MAX_SIZE) % QUEUE_MAX_SIZE;
    return tempData;
}

int dequeueRear(DoublyEndedQueue* q){
    int tempData = -1;
    // check for the underflow condition
    if(q->front == -1 && q->rear == -1){
        printf("Doubly Ended Queue is underflow.\n");
        return tempData;
    }
    // check if the queue has only one element 
    if(q->front == q->rear){
        tempData = q->queue[q->rear];
        q->front = q->rear = -1;
        return tempData;
    }
    // update the rear to delete the element from the rear of the queue
    q->rear = (q->rear - 1 + QUEUE_MAX_SIZE) % QUEUE_MAX_SIZE;
    return tempData;
}

int front(DoublyEndedQueue* q){
    // check if the Doubly Ended Queue is already empty
    if(q->front == -1 && q->rear == -1){
        printf("Doubly Ended Queue is empty.\n");
        return -1; // Note to return that value which is not the part of the answer
    }
    return q->queue[q->front];
}

int rear(DoublyEndedQueue* q){
    // check if the Doubly Ended Queue is already empty
    if(q->front == -1 && q->rear == -1){
        printf("Doubly Ended Queue is empty.\n");
        return -1; // Note to return that value which is not the part of the answer
    }
    return q->queue[q->rear];
}

int isEmpty(DoublyEndedQueue* q){
    return (q->front == -1 && q->rear == -1);
}

void display(DoublyEndedQueue* q){
    // check if the queue is already empty
    if(q->front == -1 && q->rear == -1){
        printf("Doubly Ended Queue is empty.\n");
        return;
    }
    printf("Elements of Doubly Ended Queue are : ");
    int i = q->front;
    while(i != q->rear){
        printf("%d ", q->queue[i]);
        i = (i + 1 + QUEUE_MAX_SIZE) % QUEUE_MAX_SIZE;
    }
    printf("%d\n", q->queue[i]);
    return;
}