/*
Note to the Students : 

We have solved this question using Brute Force approach, which will throw Time Limit Exceed error. 
Since, 1 <= N <= 10^6 and the time complexity is O(N^2). 

This question can be solved optimally with the help of stack.
We will re-visit the problem when we will study stacks.

*/

#include<stdio.h>

int main(){
	int n;
	scanf("%d", &n);
	int arr[n];
	for(int i = 0; i < n; i++){
		scanf("%d", &arr[i]);
	}

	long long int product = 1;
	for(int i = 0; i < n-1; i++){
		for(int j = i+1; j < n; j++){
			if(arr[j] < arr[i]){
				product *= (j + 1 - i);
				product = product % (1000000007);
				break;
			}
		}
	}
	printf("%lld\n", product);
	return 0;
}