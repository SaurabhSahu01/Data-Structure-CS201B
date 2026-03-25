#include<stdio.h>
#include<limits.h>
#define STACK_SIZE 20
int stack[STACK_SIZE];
int tp = -1;

void printArray(int [], int, char[]);

int size(){
	return tp + 1;
}

void push(int x){
	if(size() == STACK_SIZE){
		return;
	}
	tp++;
	stack[tp] = x;
	return;
}
int pop(){
	if(size() == 0){
		return INT_MIN;
	}
	int temp = stack[tp];
	stack[tp] = -1;
	tp--;
	return temp;
}
int empty(){
	if(size() == 0)
		return 1;
	return 0;
}


int main(){
	int n;
	printf("Enter the size of the array : ");
	scanf("%d",&n);
	if(n <= 0){
		printf("Invalid input! Size should be greater than 0.\n");
		return -1;
	}
	int arr[n];
	for(int i = 0; i < n; i++){
		printf("Enter arr[%d] : ", i);
		scanf("%d", &arr[i]);
	}
	// print before reversal
	char msg1[] = "Array before reversing : ";
	printArray(arr, n, msg1);

	// do some processing
	// 1. push all the elements of the array into the stack
	for(int i = 0; i < n; i++){
		push(arr[i]);
	}

	// 2. pop all the elements and meanwhile store in the array
	int count = 0;
	while(!empty()){
		int topElem = pop();
		arr[count++] = topElem;
	}

	// print after reversal
	char msg2[] = "Array after reversing : ";
	printArray(arr, n, msg2);
	return 0;
}
void printArray(int arr[], int n, char str[]){
	printf("%s", str);
	for(int i = 0; i < n; i++){
		printf("%d ", arr[i]);
	}
	printf("\n");
}