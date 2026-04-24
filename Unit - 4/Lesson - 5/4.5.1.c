/**
 * Implementation of Stack using Queues
 */

#include "../DoublyEndedQueueUsingArray.c"

void push(int elem, DoublyEndedQueue* q1, DoublyEndedQueue* q2){
    while(!isEmpty(q1)){
        int topElement = dequeueFront(q1);
        enqueueRear(topElement, q2);
    }
    enqueueRear(elem, q1);
    while(!isEmpty(q2)){
        int topElement = dequeueFront(q2);
        enqueueRear(topElement, q1);
    }
    return;
}
int pop(DoublyEndedQueue* q1){
    return dequeueFront(q1);
}
void displayStack(DoublyEndedQueue* q1, DoublyEndedQueue* q2){
    while(!isEmpty(q1)){
        int poppedElement = dequeueFront(q1);
        printf("%d ", poppedElement);
        enqueueRear(poppedElement, q2);
    }
    while(!isEmpty(q2)){
        int poppedElement = dequeueFront(q2);
        enqueueRear(poppedElement, q1);
    }
    printf("\n");
    return;
}
int isEmptyStack(DoublyEndedQueue* q1){
    return isEmpty(q1);
}

int main(){
    DoublyEndedQueue q1, q2;
    init(&q1);
    init(&q2);

    push(10, &q1, &q2);
    push(20, &q1, &q2);
    push(30, &q1, &q2);
    pop(&q1);
    displayStack(&q1, &q2);
    
    return 0;
}