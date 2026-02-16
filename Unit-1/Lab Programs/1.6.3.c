#include<stdio.h>

int main(){
	int M, N, X1, Y1, X2, Y2;
	scanf("%d%d", &M, &N);
	int arr[M][N];
	// taking input in Row-major order - row by row
	// Column-major order - column by column
	for(int i = 0; i < M; i++){
		for(int j = 0; j < N; j++){
			scanf("%d", &arr[i][j]);
		}
	}
	scanf("%d%d%d%d", &X1, &Y1, &X2, &Y2);
	X1 -= 1; 
	Y1 -= 1;
	X2 -= 1;
	Y2 -= 1;

	int sum = 0; 
	for(int i = X1; i <= X2; i++){
		for(int j = Y1; j <= Y2; j++){
			sum += arr[i][j];
		}
	}
	printf("%d\n", sum);
	return 0;
}