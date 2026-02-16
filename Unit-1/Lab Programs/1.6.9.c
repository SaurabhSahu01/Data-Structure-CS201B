#include <stdio.h>

// swap function
void swap(int *a, int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

// Partition Function
int partition(int arr[], int low, int high){
	// we will select the mid element and find it's correct position in the range
	int mid = low + (high - low)/2;
	int temp = arr[mid];
	// place the mid element to the last of the array
	swap(&arr[mid], &arr[high]);

	// Let i always points to the end of the region containing elements < the chosen element
	int i = -1;
	// let j be a variable to traverse the array
	for(int j = 0; j < high; j++){
		if(arr[j] <= temp){
			i++;
			swap(&arr[i], &arr[j]);
		}
	}
	swap(&arr[i+1], &arr[high]);

	return i+1;
}

// Quick Sort function
void quickSort(int arr[], int low, int high) {
	if(low >= high) return;
	
    int pivot = partition(arr, low, high);

	quickSort(arr, low, pivot-1);
	quickSort(arr, pivot+1, high);
	return;
}

// Function to print an array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int n;
    // Input the size of the array
    scanf("%d", &n);
    int arr[n];
    
    // Input the elements of the array
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Print the original array
    printArray(arr, n);

    // Sort the array using quick sort
    quickSort(arr, 0, n - 1);
    
    // Print the sorted array
    printArray(arr, n);

    return 0;
}