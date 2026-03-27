typedef struct Node{
    char data;
    struct Node* next;
}Node;


Node* createNode(char ch){
    Node* ptr = (Node*)malloc(sizeof(Node));
    ptr->data = ch;
    ptr->next = NULL;
    return ptr;
}
int empty(Node** head){
    return (*head == NULL);
}

void push(char ch, Node** head){
    Node* newNode = createNode(ch);
    if(head == NULL){
        *head = newNode;
        return;
    }
    newNode->next = *head;
    *head = newNode;
    return;
}

char pop(Node** head){
    if(empty(head)){
        return '\0';
    }
    Node* tmp = *head;
    char topElem = tmp->data;
    *head = (*head)->next;
    tmp->next = NULL;
    free(tmp);
    return topElem;
}
char top(Node** head){
    if(empty(head)){
        return '\0';
    }
    return (*head)->data;
}

bool isValid(char* s) {
    Node* head = NULL;
    for(int idx = 0; idx < strlen(s); idx++){
        if(s[idx] == '(' || s[idx] == '{' || s[idx] == '['){
            push(s[idx], &head);
        }
        else if(s[idx] == ')' || s[idx] == '}' || s[idx] == ']'){
            if(empty(&head)) return false;
            char topElem = top(&head);
            if(topElem == '(' && s[idx] == ')'){
                pop(&head);
            }
            else if(topElem == '{' && s[idx] == '}'){
                pop(&head);
            }
            else if(topElem == '[' && s[idx] == ']'){
                pop(&head);
            }
            else{
               return false;
            }
        }
    }
    return empty(&head);
}