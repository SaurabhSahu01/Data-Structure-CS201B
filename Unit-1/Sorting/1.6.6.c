#include<stdio.h>
// function prototype
void swap(int *, int *);
void sort2DArray(int n, int arr[][n]);
int main(){
	int n,m;
	scanf("%d %d", &n, &m);
	int arr[n];
	int freq[2][m + 1]; // frequency array ( 2 * m )
	for(int i = 0; i < m+1; i++){
        freq[0][i] = 0;
		freq[1][i] = i;
	}
	// user input for the array
	for(int i = 0; i < n; i++){
		scanf("%d", &arr[i]);
	}

    // populate the frequency array
    for(int i = 0; i < n; i++){
        freq[0][arr[i]]++;
    }

	// sorting algo
	sort2DArray(m+1, freq);

	// print the answer
	for(int i = m; i >= 0; i--){
        while(freq[0][i]--){
            printf("%d ", freq[1][i]);
        }
    }
	return 0;
}

void sort2DArray(int n, int arr[][n]){
	// bubble sort
	for(int pos = n-1; pos > 0; pos--){
		for(int i = 0; i < pos; i++){
			if(arr[0][i] > arr[0][i+1]){
				// element swapping
				swap(&arr[0][i], &arr[0][i+1]);
				// index swapping
				swap(&arr[1][i], &arr[1][i+1]);
			}
		}
	}
}
void swap(int *a, int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}