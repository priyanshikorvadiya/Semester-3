//WAP to implement Insertion sort using array.

#include<stdio.h>

void InsertionSort(int arr[], int n){
    int i = 1;

    while(i < n){
        int key = arr[i];
        int j = i - 1;

        while(j >= 0 && arr[j] > key){
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
        i = i + 1;
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

    InsertionSort(arr , n);

    printf("Sorted array elements:");
    for(int i = 0; i < n ; i++){
        printf("%d ", arr[i]);
    }
}