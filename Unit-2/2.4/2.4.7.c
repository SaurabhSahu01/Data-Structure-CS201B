struct polynomial {
	int coeff;
	int exp;
	struct polynomial *next;
};
typedef struct polynomial *poly;

poly createNode(int coeff, int exp){
	poly ptr = (poly)malloc(sizeof(struct polynomial));
	ptr->coeff = coeff;
	ptr->exp = exp;
	return ptr;
}

poly addNodeAtBeginning(poly head, poly ptr){
	if(head == NULL){
		head = ptr;
		return head;
	}

	ptr->next = head;
	head = ptr;
	return head;
}

poly addNodeAfterGivenNode(poly head, poly ptr, poly pos){
	ptr->next = pos->next;
	pos->next = ptr;
	return head;
}

poly addTerm(poly head, poly ptr) {
	// check if the linked list is empty
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
	while(temp != NULL) {
		printf("%d X^ %d ---> ", temp -> coeff, temp -> exp);
		temp = temp -> next;
	}
	printf("NULL\n");
}

poly sub(poly head1, poly head2) {
	poly newHead = NULL;
	poly p1 = head1, p2 = head2;
	while(p1 != NULL){
		int requiredCoeff = p1->coeff;
		int requiredExp = p1->exp;
		poly newNode = createNode(requiredCoeff, requiredExp);
		newHead = addTerm(newHead, newNode);
		p1 = p1->next;
	}
	while(p2 != NULL){
		int requiredCoeff = -(p2->coeff);
		int requiredExp = p2->exp;
		poly newNode = createNode(requiredCoeff, requiredExp);
		newHead = addTerm(newHead, newNode);
		p2 = p2->next;
	}
	return newHead;
}





