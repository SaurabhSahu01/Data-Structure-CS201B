struct polynomial {
	int coeff;
	int exp;
	struct polynomial *next;
};
typedef struct polynomial *poly;

poly createNode(int coeff, int exp){
	poly temp = (poly)malloc(sizeof(struct polynomial));
	temp->coeff = coeff;
	temp->exp = exp;
	return temp;
}

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
	// linked list is empty
	if(head == NULL){
		head = ptr;
		return head;
	}
	poly temp = head;
	// find the correct position of the node to be inserted, temp represents the node where we have to insert the node just before it
	while(temp->exp > ptr->exp){
		temp = temp->next;
	}
	// if the found node has the same exponent value, add the coeffiecents
	if(temp != NULL && temp->exp == ptr->exp){
		temp->coeff += ptr->coeff;
		return head;
	}
	// if temp is pointing to the head, then the node to be added will be added at the beginning
	if(temp == head){
		// add the node at the beginning
		head = addNodeAtBeginning(head, ptr);
		return head;
	}
	// temp is not pointing to the first node, then we need to find a node just before the node pointed by temp
	poly pos = head;
	while(pos->next != temp){
		pos = pos->next;
	}
	head = addNodeAfterGivenNode(head, ptr, pos);
	return head;
}

void print(poly head) {
	poly temp = head;
	while(temp != NULL) {
		printf("%d X^ %d ---> ", temp -> coeff, temp -> exp);
		temp = temp -> next;
	}
	printf("NULL\n");
}

poly mul(poly head1, poly head2) {
	poly p1 = head1, p2 = head2;
	poly newHead = NULL;
	while(p2 != NULL){
		while(p1 != NULL){
			int resultCoeff = p2->coeff * p1->coeff;
			int resultExp = p2->exp + p1->exp;
			poly newNode = createNode(resultCoeff, resultExp);
			newHead = addTerm(newHead, newNode);
			p1 = p1->next;
		}
		p2 = p2->next;
        p1 = head1;
	}
	return newHead;
}








