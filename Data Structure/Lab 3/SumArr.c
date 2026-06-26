// Write a program to calculate sum of numbers from m to n.

#include<stdio.h>
void main(){
    int n,arr[n],i=0;
    int sum = 0;

    printf("Enter size of an array(n) :");
    scanf("%d",&n);

    for(i = 0; i < n ; i++){
        printf("Enter element :");
        scanf("%d",&arr[i]);
    }

    for(i = 0; i < n ; i++){
        sum = sum + arr[i];
    }

    printf("Sum of array element is : %d ",sum);
}