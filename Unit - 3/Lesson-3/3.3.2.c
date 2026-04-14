#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>
#define STACK_MAX_SIZE 20
char stack [STACK_MAX_SIZE];

int top = -1;

// function prototypes
int checkInvalidSymbols(char*);
int checkValidParenthesis(char*);

int size(){
	return top + 1;
}

//Return 1 if stack is empty else return 0.
int isEmpty() {
	return (size() == 0);
}

//Push the character into stack
void push(char x) {
	if(size() == STACK_MAX_SIZE){
		return;
	}
	stack[++top] = x;
	return;
}

//pop a character from stack
char pop() {
	if(isEmpty()){
		return '\0';
	}
	return stack[top--];;
}

char peek(){
	if(isEmpty()){
		return '\0';
	}
	return stack[top];
}

// Return 0 if char is '('
// Return 1 if char is '+' or '-'
// Return 2 if char is '*' or '/' or '%'
int priority(char x) {
	if(x == '('){
		return 0;
	}
	else if(x == '+' || x == '-'){
		return 1;
	}
	else if(x == '*' || x == '/' || x == '%'){
		return 2;
	}
	// other characters are not valid so priority is set to -1
	return -1;
}

//Output Format
//if expression is correct then output will be Postfix Expression : <postfix notation>
//If expression contains invalid operators then output will be "Invalid symbols in infix expression. Only alphanumberic and { '+', '-','*', '%%', '/' } are allowed."
//If the expression contains unbalanced paranthesis the output will be "Invalid infix expression : unbalanced parenthesis."
void convertInfix(char * e) {
	int isValid = 1;
	// check for invalid symbols
	isValid = checkInvalidSymbols(e);
	if(!isValid){
		printf("Invalid symbols in infix expression. Only alphanumeric and { '+', '-','*', '%%', '/' } are allowed.\n");
		return;
	}

	// check for valid parenthesis
	isValid = checkValidParenthesis(e);
	if(!isValid){
		printf("Invalid infix expression : unbalanced parenthesis.\n");
		return;
	}

	printf("Postfix expression : ");
	for(int i = 0; e[i] != '\0'; i++){
		// if operand then print it 
		if((e[i] >= 'A' && e[i] <= 'Z') || (e[i] >= 'a' && e[i] <= 'z')){
			printf("%c", e[i]);
			continue;
		}
		else if(e[i] == '('){
			push(e[i]);
			continue;
		}
		while(!isEmpty() && priority(peek())  >= priority(e[i])){
			char poppedElement = pop();
			if(poppedElement != '('){
				printf("%c", poppedElement);
			}
		}
		if(e[i] != ')')
			push(e[i]);
	}
	// after traversing the elements, stack might not be empty
	while(!isEmpty()){
		char poppedElement = pop();
			if(poppedElement != '(' && poppedElement != ')'){
				printf("%c", poppedElement);
			}
	}
	printf("\n");
	return;
}

int checkInvalidSymbols(char * str){
	for(int i = 0; str[i] != '\0'; i++){
		if(!(str[i] >= 'A' && str[i] <= 'Z') && !(str[i] >= 'a' && str[i] <= 'z') && 
			str[i] != '(' && str[i] != ')' && str[i] != '+' && str[i] != '-' && str[i] != '*' &&
			str[i] != '/' && str[i] != '%'){
			return 0;
		}
	}
	return 1;
}

int checkValidParenthesis(char * str){
	for(int i = 0; str[i] != '\0'; i++){
		if(str[i] == '('){
			push(str[i]);
		}
		else if(str[i] == ')'){
			if(isEmpty())
				return 0;
			else if(peek() == '(')
				pop();
		}
	}
	int answer = isEmpty();
	top = -1; // reset the stack
	return answer;
}
