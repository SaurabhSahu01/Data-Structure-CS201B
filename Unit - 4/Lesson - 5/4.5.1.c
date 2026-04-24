/**
 * Implementation of Stack using Queues
 */

#include "../QueueUsingArray.c"

void push(int elem, Queue* q1, Queue* q2){
    while(!isEmpty(q1)){
        int topElement = dequeue(q1);
        enqueue(topElement, q2);
    }
    enqueue(elem, q1);
    while(!isEmpty(q2)){
        int topElement = dequeue(q2);
        enqueue(topElement, q1);
    }
    return;
}
int pop(Queue* q1){
    return dequeue(q1);
}
void displayStack(Queue* q1, Queue* q2){
    while(!isEmpty(q1)){
        int poppedElement = dequeue(q1);
        printf("%d ", poppedElement);
        enqueue(poppedElement, q2);
    }
    while(!isEmpty(q2)){
        int poppedElement = dequeue(q2);
        enqueue(poppedElement, q1);
    }
    printf("\n");
    return;
}
int isEmptyStack(Queue* q1){
    return isEmpty(q1);
}

int main(){
    Queue q1, q2;
    init(&q1);
    init(&q2);

    push(10, &q1, &q2);
    push(20, &q1, &q2);
    push(30, &q1, &q2);
    pop(&q1);
    displayStack(&q1, &q2);
    
    return 0;
}