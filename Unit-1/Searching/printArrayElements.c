#include<stdio.h>
// Function prototype
void printElements(int [], int, int);

int main(){
    int arr[] = {1,2,3,4,5};
    printElements(arr, 5, 1);
    return 0;
}

void printElements(int arr[], int n, int idx){
    // base case 
    if(idx > n-1) return;
    printf("%d ", arr[idx]);
    printElements(arr, n, idx+1);
}