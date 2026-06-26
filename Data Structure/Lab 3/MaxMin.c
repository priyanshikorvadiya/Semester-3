// Write a program to find position of the smallest number & the largest number 
//from given n numbers.

#include<stdio.h>
void main(){

    int n,a[n],i = 0,j = 0;
    int max = a[0],maxindex = 0;
    int min = a[0],minindex = 0;

    printf("Enter size of an array(n) :");
    scanf("%d",&n);

    for(i = 0; i < n ; i++){
        printf("Enter element :");
        scanf("%d",&a[i]);
    }

    for(i = 0; i < n;i++){
        if(max < a[i]){
            max = a[i];
            maxindex = i;
        }
    }

    for(j = 0; j < n;j++){
        if(min > a[j]){
            min = a[j];
            minindex = j;
        }
    }

    printf("Index of largest element is on : %d\n",maxindex);
    printf("Index of smallest element is on : %d\n",minindex);
}