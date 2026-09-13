// Write a program to implement a Binary Search using Array. (Iterative & 
// recursive)

#include<stdio.h>

//Iterative binarysearch function
int BinarySearchI(int arr[] , int n , int x){
    int low = 0;
    int high = n - 1;

    while(low <= high){
        int mid = low + (high - low) / 2;

        if(arr[mid] == x){
            return mid;
        }

        if(arr[mid] < x){
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
    }
    return -1;
}

//Recursive binarysearch function
int BinarySearchR(int arr[] , int low , int high , int x){

    if(low > high){
        return -1;
    }

    int mid = low + (high - low) / 2;

    if(arr[mid] == x){
        return mid;
    }

    if(arr[mid] < x){
        return BinarySearchR(arr , mid + 1 , high , x);
    }
    else{
        return BinarySearchR(arr , low , mid - 1 , x);
    }

    return -1;
}

void main(){
    int n , x , index1 , index2;

    printf("Enter size of an array:");
    scanf("%d", &n);

    int arr[n];

    printf("Enter array elements:");
    for(int i = 0; i < n ; i++){
        scanf("%d", &arr[i]);
    }

    printf("Enter value to find:");
    scanf("%d", &x);

    index1 = BinarySearchI(arr , n , x);
    index2 = BinarySearchR(arr , 0 , n - 1 , x);

    printf("Value found at(Iterative approch) : %d\n", index1);
    printf("Value found at(Recursive approch) : %d", index2);
}