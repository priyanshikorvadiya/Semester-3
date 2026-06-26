// WAP to get and print the array elements using Pointer. 

#include<stdio.h>
#include<stdlib.h>

void main(){
    int n;

    printf("Enter n:");
    scanf("%d",&n);

    int *ptr = (int *)malloc(n * sizeof(int));

    for(int i = 0 ; i < n ;i++){
        scanf("%d",&ptr[i]);
    }

    for(int i = 0 ; i < n ;i++){
        printf("%d",ptr[i]);
    }
}