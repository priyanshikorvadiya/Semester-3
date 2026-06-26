//WAP to find factorial of a number. (Using loop & recursion)

#include<stdio.h>
int Fact(int n);
int main(){

    int n,fact = 0;
    printf("Enter number :");
    scanf("%d",&n);

    fact = Fact(n);

    printf("Factorial of given number :");
    printf("%d",fact);

    return 0;
}

int Fact(int n){
    if(n <= 1){
        return 1;
    }
    else{
        return n * Fact( n - 1 );
    }
}