// Write a program to implement a Linear Search using Array.

#include<stdio.h>

int LinearSearch(int arr[], int size, int x){

    for(int i = 0; i < size; i++){
        if(arr[i] == x){
            return i;
        }
    }
    return -1;
}

void main(){
    int n , x , index;

    printf("Enter size of an array:");
    scanf("%d", &n);

    int arr[n];

    printf("Enter array elements:");
    for(int i = 0; i < n ; i++){
        scanf("%d", &arr[i]);
    }

    printf("Enter value to find:");
    scanf("%d", &x);

    index = LinearSearch(arr , n , x);

    printf("Value found at : %d", index);
}