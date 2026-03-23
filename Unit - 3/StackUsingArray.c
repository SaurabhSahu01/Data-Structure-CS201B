#include<stdio.h>
#include<limits.h>

#define STACKSIZE 10
int arr[STACKSIZE];
int tp = -1;

void push(int);
int pop();
int top();
int size();
int empty();



int main(){
    int n = 6;
    int arr2[] = {1,2,3,4,5,6};
    for(int i = 0; i < n; i++){
        push(arr2[i]);
    }

    while(!empty()){
        int tempElem = pop();
        printf("%d\n", tempElem);
    }
    return 0;
}

void push(int x){
    if(size() == STACKSIZE){
        printf("Stack Overflow\n");
        return;
    }
    tp++;
    arr[tp] = x;
}
int pop(){
    // empty case
    if(tp < 0){
        printf("Stack is empty\n");
        return -1;
    }
    int temp = arr[tp];
    arr[tp] = INT_MIN;
    tp--;
    return temp;
}
int top(){
    // empty case
    if(tp < 0){
        printf("Stack is empty\n");
        return -1;
    }
    return arr[tp];
}
int size(){
    return tp + 1;
}
int empty(){
    if(tp >= 0){
        return 0;
    }
    return 1;
}