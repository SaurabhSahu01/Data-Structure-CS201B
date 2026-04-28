#ifndef QUEUEFORTREE_H
#define QUEUEFORTREE_H
#define QUEUE_MAX_SIZE 40
#include"BuildingBlockTree.h"

typedef struct QueueForTree{
    int front;
    int rear;
    TreeNode** queue;
}Queue;

void init(Queue* );

void enqueue(Queue* , TreeNode* );

TreeNode* dequeue(Queue* );

TreeNode* front(Queue* );

int isEmpty(Queue* );

#endif