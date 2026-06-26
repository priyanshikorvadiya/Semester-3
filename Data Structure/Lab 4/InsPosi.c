// Write a program to insert a number in an array that is already sorted in an 
//ascending order.

#include<stdio.h>
void main(){
    int n,a[n + 1],i = 0,index,val;

    printf("Enter size of an aay(n) :");
    scanf("%d",&n);

    printf("Enter value :");
    scanf("%d",&val);

    for(i = 0; i < n ; i++){
        printf("Enter element :");
        scanf("%d",&a[i]);
    }

    index = n;
    for(i = 0 ; i < n; i++){
        if(a[i] > val){
            index = i;
            break;
        }
    }

    //Shifting an element(Right)
    for(i = n - 1 ; i >= index; i--){
        a[i + 1] = a[i];
    }

    a[index] = val;
    n++;

    for(i = 0; i < n ; i++){
        printf("%d ,",a[i]);
    }
}