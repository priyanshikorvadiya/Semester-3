// Read n numbers in an array then read two different numbers, replace 1st 
//number with 2nd number in an array and print its index and final array.

#include<stdio.h>
void main(){
    int n,arr[n],i = 0,n1,n2,index =0;

    printf("Enter size of an array(n) :");
    scanf("%d",&n);

    printf("Enter n1:");
    scanf("%d",&n1);

    printf("Enter n2:");
    scanf("%d",&n2);

    for(i = 0; i < n ; i++){
        printf("Enter element :");
        scanf("%d",&arr[i]);
    }

    for(i = 0 ; i < n; i++){
        if(n1 == arr[i]){
            arr[i] = n2;
            index = i; 
        }
    }

    for(i = 0; i < n ; i++){
        printf("%d ,",arr[i]);
    }
}