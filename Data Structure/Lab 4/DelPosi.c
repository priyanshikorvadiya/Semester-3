// Write a program to delete a number from an array that is already sorted in an 
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
        if(a[i] == val){
            index = i;
            break;
        }
    }

    if(index < n){
        for(i = index ; i < n - 1; i++){
            a[i] = a[i + 1];
        }
        n--;

        for(i = 0; i < n ; i++){
            printf("%d\n ,",a[i]);
        }
    }

    else{
        printf("Element not Found");
    }
}