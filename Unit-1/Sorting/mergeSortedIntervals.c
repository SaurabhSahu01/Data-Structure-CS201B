#include <stdio.h>
void merge(int [], int, int, int);

int main(){
    int A[] = {1, 3, 2, 4, 5, 6, 3, 7, 9, 11, 10, 8};
    int left = 3, mid = 5, right = 9;
    
    merge(A, left, mid, right);
    
    // print the array
    for(int i = 0; i < 12; i++){
        printf("%d ", A[i]);
    }

    return 0;
}

void merge(int A[], int left, int mid, int right){
    int l1 = mid - left + 1, l2 = right - (mid + 1) + 1;
    // temporary arrays to store the elements from the intervals
    int tempArr1[l1], tempArr2[l2];
    
    // copy elements from the intervals to the temp arrays
    int count = 0;
    for(int i = left; i <= mid; i++){
        tempArr1[count++] = A[i];
    }
    count = 0;
    for(int i = mid+1; i <= right; i++){
        tempArr2[count++] = A[i];
    }
    
    // compare the elements and copy back to the original array
    int i = 0, j = 0;
    count = left;
    while(i < l1 && j < l2){
        if(tempArr1[i] <= tempArr2[j]){
            A[count++] = tempArr1[i++];
        }
        else{
            A[count++] = tempArr2[j++];
        }
    }
    while(i < l1){
        A[count++] = tempArr1[i++];
    }
    while(j < l2){
        A[count++] = tempArr2[j++];
    }
    
    return;
}