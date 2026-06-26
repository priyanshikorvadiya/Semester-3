//WAP to find power of a number using loop.

#include<stdio.h>
void main(){

    int n,multi = 1,p;

    printf("Enter a number and power :");
    scanf("%d",&n);
    scanf("%d",&p);

    for(int i = 1; i <= p ; i++){
        multi = multi * n;
    }

    printf("Power of a number is :");
    printf("%d",multi);
}