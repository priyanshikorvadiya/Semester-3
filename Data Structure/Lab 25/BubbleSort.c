// Write a program to implement Bubble using Array. 

#include<stdio.h>

void BubbleSort(int arr[] , int n){
    
    for(int i = 0 ; i < n - 1 ; i++){

        int count = 0;

        for(int j = 0 ; j < n - i - 1 ; j++){
            if(arr[j] > arr[j + 1]){
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;

                count = 1;
            }
        }

        if(count == 0){
            break;
        }
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

    BubbleSort(arr , n);

    printf("Sorted array elements:");
    for(int i = 0; i < n ; i++){
        printf("%d ", arr[i]);
    }
}