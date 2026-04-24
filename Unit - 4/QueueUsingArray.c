#include<stdio.h>
#include"QueueBuildingBlock.c"

typedef QueueArray Queue;

// Functions for the Array based Queue
void init(Queue *q){
    initQueueArray(q);
    return;
}

void enqueue(int x, Queue* q){
    // check for the queue overflow condition
    if(q->rear == QUEUE_MAX_SIZE - 1){
        printf("Queue is overflow\n");
        return;
    }
    // check if the queue is empty
    if(q->front == -1 && q->rear == -1){
        q->front = 0;
    }
    q->queue[++(q->rear)] = x;
}

int dequeue(Queue* q){
    // check if the queue is already empty
    if((q->front == -1 && q->rear == -1) || (q->front > q->rear)){
        printf("Queue is underflow\n");
        return -1; // Note to return that value which is not the part of your answer
    }
    int tempData = q->queue[q->front];
    // check for the single element
    if(q->front == q->rear){
        q->front = q->rear = -1;
    }
    else
       (q->front)++;
    return tempData;
}

int front(Queue* q){
    // check if the queue is already empty
    if((q->front == -1 && q->rear == -1) || q->front > q->rear){
        printf("Queue is underflow\n");
        return -1; // Note to return that value which is not the part of your answer
    }
    return q->queue[q->front];
}

int isEmpty(Queue* q){
    return (q->front == -1 && q->rear == -1) || (q->front > q->rear);
}

void display(Queue* q){
    // check for the empty queue
    if((q->front == -1 && q->rear == -1) || q->front > q->rear){
        printf("Queue is empty. Nothing to display\n");
        return;
    }
    for(int i = q->front; i <= q->rear; i++){
        printf("%d ", q->queue[i]);
    }
    printf("\n");
    return;
}
