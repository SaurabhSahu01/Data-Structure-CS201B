#include<stdio.h>
// function prototype
void swap(int *, int *);
void sort2DArray(int n, int arr[][n]);
int main(){
	int n,m;
	scanf("%d %d", &n, &m);
	int arr[n], freq1[m+1], freq2[2][n]; // frequency array ( 2 * n )

    // initialise freq2 array
	for(int i = 0; i < n; i++){
        freq2[0][i] = freq2[1][i] = 0;
	}

    // initialise freq1 array
    for(int i = 0; i < m+1; i++){
        freq1[i] = 0;
    }

	// user input for the array
	for(int i = 0; i < n; i++){
		scanf("%d", &arr[i]);
        freq1[arr[i]]++;
	}

    // populate the freq2 array
    int count = 0;
    for(int i = 0; i < n; i++){
        if(freq1[arr[i]] > 0){
            freq2[0][count] = freq1[arr[i]];
            freq2[1][count] = arr[i];
            freq1[arr[i]] *= -1;
            count++;
        }
    }

	// sorting algo
	sort2DArray(n, freq2);

	// print the answer
	for(int i = 0; i < n; i++){
        while(freq2[0][i]--){
            printf("%d ", freq2[1][i]);
        }
    }
	return 0;
}

void sort2DArray(int n, int arr[][n]){
	// bubble sort
	for(int pos = n-1; pos > 0; pos--){
		for(int i = 0; i < pos; i++){
            // bubble sort in decreasing order
			if(arr[0][i] < arr[0][i+1]){
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