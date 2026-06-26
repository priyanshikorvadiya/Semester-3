// Write a program to read and display n numbers using an array.

#include<stdio.h>
void main(){
    int n,arr[n],i=0;

    printf("Enter size of an array(n) :");
    scanf("%d",&n);

    for(i = 0; i < n ; i++){
        printf("Enter element :");
        scanf("%d",&arr[i]);
    }

    for(i = 0; i < n ; i++){
        printf("%d ,",arr[i]);
    }
}