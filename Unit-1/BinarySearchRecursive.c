#include<stdio.h>
// Function Prototype
int BinarySearch(int [], int, int);
int BinarySearchRecursive(int [], int, int, int);
int main(){
    int arr[] = {10, 20, 30, 40 , 50};
    printf("Element found at : %d", BinarySearchRecursive(arr, 40, 0, 4));
    return 0;
}

int BinarySearch(int arr[], int n, int target){
    int start = 0, end = n-1;
    while(start <= end){
        int mid = start + (end - start)/2;
        if(target == arr[mid]) return mid;
        if(target > arr[mid]) start = mid + 1;
        else end = mid - 1;
    }
    return -1;
}
int BinarySearchRecursive(int arr[], int target, int start, int end){
    // Base Case
    if(start > end) return -1;

    int mid = start + (end - start)/2;

    if(target == arr[mid]) return mid;

    if(target > arr[mid]) return BinarySearchRecursive(arr, target, mid + 1, end);
    else return BinarySearchRecursive(arr, target, start, mid - 1);
}