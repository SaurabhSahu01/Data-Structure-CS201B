#include <stdio.h>
#include <stdlib.h>
struct stack {
	int data;
	struct stack *next;
};

typedef struct stack* stk;
stk head = NULL;
// Was it really needed to return head in the push() function?
stk* push(int x) {
	stk ptr = (stk)malloc(sizeof(struct stack));// creating a Node
	ptr->data = x;
	// adding a node at the beginning of a linked list
	ptr->next = head;
	head = ptr;
	printf("Successfully pushed.\n");
	return &head;
}

void display() {
	stk temp = head;
	printf("Elements of the stack are : ");
	while(temp != NULL){
		printf("%d ", temp->data);
		temp = temp->next;
	}
	printf("\n");
}
