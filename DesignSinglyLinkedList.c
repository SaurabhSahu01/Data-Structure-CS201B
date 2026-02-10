#include<stdio.h>
#include<stdlib.h>

// Structure Definition
typedef struct Node{
    int data;
    struct Node* next;
} Node;

// Function Prototypes
Node* createNode(int);
Node* createList(int);
Node* addNodeAtEnd(Node*, int);
Node* createListFromArray(int [], int);
void printList(Node*);

int main(){
    int arr[] = {1,2,3};
    Node* head = createListFromArray(arr, 3);
    head = addNodeAtEnd(head, 4);
    printList(head);
    return 0;
}

Node* createNode(int x){
    Node* ptr = (Node*)malloc(sizeof(Node));
    if(!ptr) return NULL;
    ptr->data = x;
    ptr->next = NULL;
    return ptr;
}

Node* createList(int x){
    return createNode(x);
}

Node* addNodeAtEnd(Node* head, int x){
    if(!head){
        head = createNode(x);
        return head;
    }
    Node* temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = createNode(x);
    return head;
}

Node* createListFromArray(int arr[], int n){
    Node* head = NULL; // always initialise pointers with null if not initialising while declaration
    for(int i = 0; i < n; i++){
        head = addNode(head, arr[i]);
    }
    return head;
}

void printList(Node* head){
    Node* temp = head;
    while(temp != NULL){
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL");
}