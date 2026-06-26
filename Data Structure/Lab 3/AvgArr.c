// Write a program to calculate average of first n numbers. 

#include<stdio.h>
void main(){
    int n,arr[n],i=0;
    int sum = 0;
    float avg = 0;

    printf("Enter size of an array(n) :");
    scanf("%d",&n);

    for(i = 0; i < n ; i++){
        printf("Enter element :");
        scanf("%d",&arr[i]);
    }

    for(i = 0; i < n ; i++){
        sum = sum + arr[i];
    }

    avg = (float) sum / n;

    printf("Avrage of array element is : %f ",avg);
}