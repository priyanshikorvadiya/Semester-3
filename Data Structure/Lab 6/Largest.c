// WAP to find the largest element in the array using Pointer. 

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

    max = ptr[0];

    for(i = 0 ; i < n ; i++){
        if(*(ptr + i) > max){
            max = *(ptr + i);
        }
    }

    printf("%d",max);
}