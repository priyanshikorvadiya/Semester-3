//Write a program to implement Selection Sort using Array. 

#include<stdio.h>

void SelectionSort(int arr[] , int n){
    for(int i = 0; i < n - 1 ; i++){
        int min_idx = i;

        for(int j = i + 1; j < n; j++){
            if(arr[j] < arr[min_idx]){
                min_idx = j;
            }
        }

        int temp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = temp;
    }
}

void main(){
    int n;

    printf("Enter size of an array:");
    scanf("%d", &n);

    int arr[n];

    printf("Enter array elements:");
    for(int i = 0; i < n ; i++){
        scanf("%d", &arr[i]);
    }

    SelectionSort(arr , n);

    printf("Sorted array elements:");
    for(int i = 0; i < n ; i++){
        printf("%d ", arr[i]);
    }
}