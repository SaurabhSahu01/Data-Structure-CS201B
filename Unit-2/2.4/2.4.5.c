struct polynomial {
	int coeff;
	int exp;
	struct polynomial *next;
};
typedef struct polynomial *poly;

poly addNodeAfterGivenNode(poly head, poly ptr, poly pos){
	ptr->next = pos->next;
	pos->next = ptr;
	return head;
}

poly addNodeAtBeginning(poly head, poly ptr){
	ptr->next = head;
	head = ptr;
	return head;
}

poly addTerm(poly head, poly ptr) {
	// linked list is empty case
	if(head == NULL){
		head = ptr;
		return head;
	}
	poly temp = head;
	while(temp->exp > ptr->exp){
		temp = temp->next;
	}
	if(temp != NULL && temp->exp == ptr->exp){
		temp->coeff += ptr->coeff;
		return head;
	}
	// add the node at the beginning
	if(temp == head){
		head = addNodeAtBeginning(head, ptr);
		return head;
	}

	poly pos = head;
	while(pos->next != temp){
		pos = pos->next;
	}
	head = addNodeAfterGivenNode(head, ptr, pos);
	return head;
}

void print(poly head) {
	poly temp = head;
	while(temp != NULL){
		printf("%d X^ %d ---> ", temp->coeff, temp->exp);
		temp = temp->next;
	}
	printf("NULL\n");
}