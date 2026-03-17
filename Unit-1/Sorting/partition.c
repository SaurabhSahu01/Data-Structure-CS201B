#include<stdio.h>
void swap(int*, int*);
int partition(int [], int, int);
int main(){
    int arr[] = {3,5,1,2,8,9,0};
    int idx = 1;
    int n = 7;
    int correctIndex = partition(arr, n, idx);
    printf("Correct index : %d\n", correctIndex);
    // print the array
    for(int i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
    return 0;
}

int partition(int arr[], int n, int idx){
    int i = -1;
    swap(&arr[idx], &arr[n-1]);
    for(int j = 0; j < n-1; j++){
        if(arr[j] <= arr[n-1]){
            swap(&arr[i+1], &arr[j]);
            i++;
        }
    }
    swap(&arr[i+1], &arr[n-1]);
    return i+1;
}

void swap(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}