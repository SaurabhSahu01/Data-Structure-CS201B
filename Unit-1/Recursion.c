#include<stdio.h>

int fib(int n){
    if(n == 0 || n == 1) return n;
    printf("Prefix - %d\n", n);
    int result = fib(n-1);
    printf("Infix - %d\n", n);
    result += fib(n-2);
    printf("Postfix - %d\n", n);

    return result;
}

int main(){
    int n = 4;
    printf("%d\n", fib(n));
    return 0;
}