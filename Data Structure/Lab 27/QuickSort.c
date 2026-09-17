// Write a program to implement Quick Sort using Array.

#include<stdio.h>
#include<stdbool.h>

void QuickSort(int arr[], int LB, int UB){
    bool Flag = true;

    if(LB < UB){
        int I = LB;
        int J = UB + 1;
        int key = arr[LB];

        while (Flag == true)
        {
            I = I + 1;

            while(arr[I] < key){
                I = I + 1;
            }

            J = J - 1;

            while(arr[J] > key){
                J = J - 1;
            }

            if(I < J){
                int temp = arr[I];
                arr[I] = arr[J];
                arr[J] = temp;
            }
            else{
                Flag = false;
            }
        }

        int temp = arr[LB];
        arr[LB] = arr[J];
        arr[J] = temp;

        QuickSort(arr, LB, J - 1);
        QuickSort(arr, J + 1, UB);
        
    }
    return;
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

    QuickSort(arr , 0, n - 1);

    printf("Sorted array elements:");
    for(int i = 0; i < n ; i++){
        printf("%d ", arr[i]);
    }
}