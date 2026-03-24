#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int data;
    struct Node* next;
}Node;

Node* head = NULL; // empty stack condition

// Function Prototypes
void push(int);
int pop();
int size();
int empty();
int top();
Node* createNode(int);


int main(){
    int n = 9;
    int arr[] = {654, 43, 908, 43, 14, 76, 90, 100, 544};
    for(int i = 0; i < n; i++){
        push(arr[i]);
    }

    pop();
    int topElem = top();
    printf("Top element : %d\n", topElem);
    printf("Size of stack = %d\n", size());
    pop();
    topElem = top();
    printf("Top element : %d\n", topElem);
    printf("Size of stack = %d\n", size());
    return 0;
}

Node* createNode(int x){
    Node* ptr = (Node*)malloc(sizeof(struct Node));
    ptr->data = x;
    ptr->next = NULL;
    return ptr;
}

void push(int data){
    Node* ptr = createNode(data);
    if(head != NULL)
        ptr->next = head;
    head = ptr;
}
int pop(){
    Node* tmp = head;
    int tempData = head->data;
    head = head->next;
    tmp->next = NULL;
    free(tmp);
    return tempData;
}
int top(){
    // empty stack condition
    if(head == NULL){
        printf("Stack is empty!\n");
        return -1;
    }
    return head->data;
}
int size(){
    int count = 0;
    Node* temp = head;
    while(temp != NULL){
        count++;
        temp = temp->next;
    }
    return count;
}
int empty(){
    if(head == NULL)
        return 1;
    return 0;
}
