#include<stdio.h>
int UpperBound(int [], int, int);
int main(){
	int n, target;
	scanf("%d", &n);
	int arr[n];
	for(int i = 0; i < n; i++){
		scanf("%d", &arr[i]);
	}
	scanf("%d", &target);

	printf("%d\n", UpperBound(arr, n, target));
	return 0;
}

int UpperBound(int arr[], int n, int target){
	int start = 0, end = n-1;
	while(start <= end){
		int mid = start + (end - start)/2;
		if(target == arr[mid]) return mid;
		if(target > arr[mid]) start = mid + 1;
		else end = mid - 1;
	}

	return start;
}