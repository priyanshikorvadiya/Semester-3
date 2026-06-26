//WAP to find largest element among given three numbers

#include<stdio.h>
void main (){
    int a,b,c;
    int largest = 0;

    printf("Enter a :");
    scanf("%d",&a);

    printf("Enter b :");
    scanf("%d",&b);

    printf("Enter c :");
    scanf("%d",&c);

    largest = (a > b) ? ((a > c) ? a : c) : ((b > c) ? b : c);

    printf("Largest element is as given :");
    printf("%d",largest);
}