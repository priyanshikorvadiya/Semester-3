// WAP to find factors of a given number. 

#include<stdio.h>
void main(){

    int n,fact = 0;
    printf("Enter number :");
    scanf("%d",&n);

    for(int i = 1 ; i <= n ; i++){
        if(n % i == 0){
            fact = i;
            printf("%d", fact);
        }
    }
}