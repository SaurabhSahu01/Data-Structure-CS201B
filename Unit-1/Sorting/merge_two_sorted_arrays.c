#include<stdio.h>
void merge(int [], int, int, int, int);
int main(){
    int arr[] = {5, 2, 1, 3, 3, 5, 1, 6, 8, 0, 5, 4};
    int n = 12;
    int s1 = 2, e1 = 5, s2 = 6, e2 = 8;

    // print the array before merging sorted intervals
    printf("Before merging: \n");
    for(int i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");

    // print the array after merging sorted intervals into one sorted interval
    printf("After merging: \n");
    merge(arr, s1, e1, s2, e2);
    for(int i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
    return 0;
}

void merge(int arr[], int s1, int e1, int s2, int e2){
    // make two temporary arrays
    int temp1[e1-s1+1], temp2[e2-s2+1];

    // copy the elements to the temporary arrays
    int count = 0;
    for(int i = s1; i <= e1; i++){
        temp1[count++] = arr[i];
    }
    count = 0;
    for(int i = s2; i <= e2; i++){
        temp2[count++] = arr[i];
    }

    // merge the arrays
    int p1 = 0, p2 = 0;
    count = s1;
    while(p1 < (e1 - s1 + 1) && p2 < (e2 - s2 + 1)){
        if(temp1[p1] < temp2[p2]){
            arr[count++] = temp1[p1++];
        }
        else{
            arr[count++] = temp2[p2++];
        }
    }
    if(p1 > (e1 - s1)){
        while(p2 < (e2 - s2 + 1)){
            arr[count++] = temp2[p2++];
        }
    }
    else{
        while(p1 < (e1 - s1 + 1)){
            arr[count++] = temp1[p1++];
        }
    }
}