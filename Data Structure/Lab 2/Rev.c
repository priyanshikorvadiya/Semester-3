//WAP to reverse a number. 

#include<stdio.h>

void main(){

    int n,rev = 0;
    printf("Enter number :");
    scanf("%d",&n);

    while(n != 0){
        int rem = n % 10;
        rev = (rev * 10) + rem;
        n /= 10;
    }

    printf("Reverse is %d",rev);
}