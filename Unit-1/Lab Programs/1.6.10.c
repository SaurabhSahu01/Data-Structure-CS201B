#include <stdio.h>

// Function to merge two subarrays
void merge(int arr[], int left, int mid, int right) {
	int l1 = mid - left + 1, l2 = right - (mid + 1) + 1;

	// make two temporary arrays for storing the elements from each of the intervals
	int tempArr1[l1], tempArr2[l2];

	// copy elements to respective arrays
	int count = 0;
	for(int i = left; i <= mid; i++){
		tempArr1[count++] = arr[i];
	}
	count = 0;
	for(int i = mid + 1; i <= right; i++){
		tempArr2[count++] = arr[i];
	}

	// merge the two arrays based on comparison of elements from each arrays
	int i = 0, j = 0;
	count = left;
	while(i < l1 && j < l2){
		if(tempArr1[i] <= tempArr2[j]){
			arr[count++] = tempArr1[i++];
		}
		else{
			arr[count++] = tempArr2[j++];
		}
	}

	// copy the remaining elements
	while(i < l1){
		arr[count++] = tempArr1[i++];
	}
	while(j < l2){
		arr[count++] = tempArr2[j++];
	}

	return;
}

// Function to implement merge sort
void mergeSort(int arr[], int left, int right) {
	if(left >= right) return;

	int mid = left + (right - left)/2;
	
	mergeSort(arr, left, mid);
	mergeSort(arr, mid+1, right);
	merge(arr, left, mid, right);

	return;
}

// Function to print an array
void printArray(int arr[], int size) {
	for(int i = 0; i < size; i++){
		printf("%d ", arr[i]);
	}
	printf("\n");
}

int main() {
    int n;
    
    // Input the size of the array
    printf("");
    scanf("%d", &n);
    
    int arr[n];
    
    // Input the elements of the array
    printf("");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Print the original array
    printf("");
    printArray(arr, n);

    // Sort the array using merge sort
    mergeSort(arr, 0, n - 1);
    
    // Print the sorted array
    printf("");
    printArray(arr, n);

    return 0;
}
