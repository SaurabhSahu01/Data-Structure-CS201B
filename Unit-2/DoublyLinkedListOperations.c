#include <stdio.h>
#include<stdlib.h>

typedef struct Node{
    int data;
    struct Node* next;
    struct Node* prev;
}Node;

int lengthOfLinkedList(Node* head){
    int length = 0;
    
    Node* temp = head;
    while(temp != NULL){
        temp = temp->next;
        length++;
    }
    return length;
}

Node* createNode(int data){
    Node* ptr = (Node*)malloc(sizeof(Node));
    ptr->data = data;
    ptr->next = NULL;
    ptr->prev = NULL;
    return ptr;
}

Node* addNodeAtBeginning(Node* head, Node* ptr){
    // empty linked list
    if(head == NULL){
        head = ptr;
        return head;
    }
    
    ptr->next = head;
    head->prev = ptr;
    head = ptr;
    return head;
}

Node* addNodeAtEnd(Node* head, Node* ptr){
    if(head == NULL){
        head = ptr;
        return head;
    }
    Node* tmp = head;
    while(tmp->next != NULL){
        tmp = tmp->next;
    }
    tmp->next = ptr;
    ptr->prev = tmp;
    return head;
}

Node* addNodeAtPosition(Node* head, Node* ptr, int pos){
    int length = lengthOfLinkedList(head);
    if(!(pos >= 1 && pos <= length + 1)){
        // just return the head without adding Node
        printf("The node cannot be added at this position!\n");
        return head;
    }
    if(pos == 1){
        return addNodeAtBeginning(head, ptr);
    }
    
    if(pos == length + 1){
        return addNodeAtEnd(head, ptr);
    }
    
    Node* tmp = head;
    int count = 1;
    while(count != pos){
        tmp = tmp->next;
        count++;
    }
    
    tmp->prev->next = ptr;
    ptr->prev = tmp->prev;
    ptr->next = tmp;
    tmp->prev = ptr;
    return head;
}

void printList(Node* head){
    Node* tmp = head;
    while(tmp != NULL){
        printf("%d --> ", tmp->data);
        tmp = tmp->next;
    }
    printf("NULL\n");
}

int main(){
    int n = 5;
    int arr[] = {1,2,3,4,5};
    
    Node* head = NULL; // empty linked list
    
    for(int i = 0; i < n; i++){
        Node* ptr = createNode(arr[i]);
        head = addNodeAtEnd(head, ptr);
    }
    
    printList(head);
    
    // add at position
    int pos = 7;
    int data = 6;
    Node* ptr = createNode(data);
    
    head = addNodeAtPosition(head, ptr, pos);
    
    printList(head);
    

    return 0;
}

