// WAP to calculate the sum of n numbers using Pointer. 

#include<stdio.h>
#include<stdlib.h>

void main (){
    int n,sum = 0,i = 0;

    printf("Enter n:");
    scanf("%d",&n);

    int *arr = (int *)malloc(n * sizeof(int));

    if(*(arr + i) == NULL){
        printf("Allocation Failed!!");
    }

    for(i = 0; i < n ; i++){
        scanf("%d",&*(arr + i));
    }

    for(i = 0; i < n ; i++){
        sum += *(arr + i);
    }

    printf("%d",sum);
}