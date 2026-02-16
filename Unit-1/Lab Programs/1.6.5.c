#include<stdio.h>

int main(){
	int test;
	scanf("%d", &test);

	while(test--){
		int n;
		scanf("%d", &n);
		int arr[n], sum = 0;
		for(int i = 0; i < n; i++){
			scanf("%d", &arr[i]);
			sum += arr[i];
		}
		// print the answer 
		for(int i = 0; i < n; i++){
			printf("%d ", sum - arr[i]);
		}
		printf("\n");
	}
	return 0;
}