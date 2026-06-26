//WAP to sort the array elements using Pointer.

#include<stdio.h>
#include<stdlib.h>

void main(){
    int n,i,max;

    printf("Enter n :");
    scanf("%d",&n);

    int *ptr = (int *)malloc(n * sizeof(int));

    if(ptr == NULL){
        printf("Memory Allocation failed");
    }

    for(i = 0 ; i < n ;i++){
        scanf("%d",&ptr[i]);
    }

    int j , temp;

    for(int i = 0 ; i < n - 1;i++){
        for(int j = 0 ; j < n - i - 1; j++){
            if(*(ptr + j) > *(ptr + j + 1)){
                temp = *(ptr + j);
                *(ptr + j) = *(ptr + j + 1);
                *(ptr + j + 1) = temp;
            }
        }
    }

    printf("Sorted Array :");
    for(i = 0; i < n ; i++){
        printf("%d",ptr + i);
    }
}