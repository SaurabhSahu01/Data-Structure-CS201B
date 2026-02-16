#include<stdio.h>
#include<limits.h>
int main(){
	int n, maxElement = INT_MIN;
	scanf("%d", &n);
	int arr[n];
	
	// take input to the array
	for(int i = 0; i < n; i++){
		scanf("%d", &arr[i]);
		if(arr[i] > maxElement) maxElement = arr[i];
	}

	// make a frequency array of size maxElement + 1
	int freq[maxElement + 1];
	
	// populate the frequency array
	for(int i = 0; i < n; i++){
		freq[arr[i]]++;
		if(freq[arr[i]] > 1){
			printf("true\n");
			return 0;
		}
	}
	printf("false\n");
	return 0;
}