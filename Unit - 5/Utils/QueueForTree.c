#include<stdio.h>
#include<stdlib.h>
#include"QueueForTree.h"


void init(Queue* q){
    q->front = q->rear = -1;
    q->queue = (TreeNode**)malloc(QUEUE_MAX_SIZE * sizeof(TreeNode *));
    return;
}

void enqueue(Queue* q, TreeNode* x){
    // check the overflow condition
    int newRear = (q->rear + 1 + QUEUE_MAX_SIZE) % QUEUE_MAX_SIZE;
    if(newRear == q->front){
        printf("Queue overflow\n");
        return;
    }
    // check queue empty condition
    if(q->front == -1 && q->rear == -1){
        q->front = newRear;
    }
    q->rear = newRear;
    q->queue[newRear] = x;
    return;
}

TreeNode* dequeue(Queue* q){
    // check for the underflow condition
    if(q->front == -1 && q->rear == -1){
        printf("Queue underflow\n");
        return NULL;
    }
    TreeNode* tempData = q->queue[q->front];
    // check for the single condition
    if(q->front == q->rear){
        q->front = q->rear = -1;
        return tempData;
    }
    q->front = (q->front + 1 + QUEUE_MAX_SIZE) % QUEUE_MAX_SIZE;
    return tempData;
}

TreeNode* front(Queue* q){
    // check for the empty queue condition
    if(q->front == -1 && q->rear == -1){
        printf("Queue is empty\n");
        return NULL;
    }
    return q->queue[q->front];
}

int isEmpty(Queue* q){
    return (q->front == -1 && q->rear == -1);
}