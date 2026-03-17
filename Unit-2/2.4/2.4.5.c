struct polynomial {
	int coeff;
	int exp;
	struct polynomial *next;
};
typedef struct polynomial *poly;

poly addNodeAtBeginning(poly head, poly ptr){
	ptr->next = head;
	head = ptr;
	return head;
}

poly addNodeBeforeGivenNode(poly head, poly ptr, poly tmp){
	poly tmp2 = head;
	while(tmp2->next != tmp){
		tmp2 = tmp2->next;
	}
	ptr->next = tmp2->next;
	tmp2->next = ptr;
	return head;
}

poly addTerm(poly head, poly ptr) {
	poly tmp = head;
	while(tmp != NULL){
		if(tmp->exp <= ptr->exp)
			break;
		tmp = tmp->next;
	}
	if(tmp != NULL && tmp->exp == ptr->exp){
		tmp->coeff = tmp->coeff + ptr->coeff;
		return head;
	}

	if(tmp == head){
		// add the node at the beginning
		head = addNodeAtBeginning(head, ptr);
		return head;
	}

	head = addNodeBeforeGivenNode(head, ptr, tmp);
	return head;
}

void print(poly head) {
	poly tmp = head;
	while(tmp != NULL){
		printf("%d X^ %d ---> ", tmp->coeff, tmp->exp);
		tmp = tmp->next;
	}
	printf("NULL\n");
}