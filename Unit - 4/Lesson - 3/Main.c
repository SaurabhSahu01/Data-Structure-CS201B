#include "../Queues.c"

int main(){
    DoublyEndedQueue dq;
    init(&dq);
    
    display(&dq);
    enqueueFront(10, &dq);
    enqueueRear(20, &dq);
    enqueueFront(30, &dq);
    dequeueFront(&dq);
    dequeueRear(&dq);
    display(&dq);

    return 0;
}