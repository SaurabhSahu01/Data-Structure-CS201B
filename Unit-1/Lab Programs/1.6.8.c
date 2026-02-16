#include<stdio.h>
void insertionSort(int [], int);
int main(){
	int n;
	scanf("%d", &n);
	int arr[n];

	// take input to the array
	for(int i = 0; i < n; i++){
		scanf("%d", &arr[i]);
	}
	// sort the array
	insertionSort(arr, n);

	// print the array
	for(int i = 0; i < n; i++){
		printf("%d ", arr[i]);
	}
	printf("\n");
	return 0;
}

void insertionSort(int arr[], int n){
	for(int i = 1; i < n; i++){
		// store the current element to a temp variable
		int temp = arr[i];
		// last index of the sorted array in which we have to find the correct position of insertion of the current element
		int idx = i - 1;
		// search the correct position to insert the current element in the sorted array
		while(arr[idx] > temp){
			// copy the current idx element to idx+1 element
			arr[idx+1] = arr[idx];
			idx--;
		}
		arr[idx + 1] = temp;
	}
}