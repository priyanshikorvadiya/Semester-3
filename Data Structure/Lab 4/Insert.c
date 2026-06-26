//Write a program to insert a number at a given location in an array. 

#include<stdio.h>
void main(){
    int n,a[n],i = 0,index,val;

    printf("Enter size of an aay(n) :");
    scanf("%d",&n);

    printf("Enter index and value :");
    scanf("%d",&index);
    scanf("%d",&val);

    for(i = 0; i < n ; i++){
        printf("Enter element :");
        scanf("%d",&a[i]);
    }

    //Shifting an element(Right)
    for(i = n - 1 ; i >= index; i--){
        a[index + 1] = a[index];
    }

    a[index] = val;
    n++;

    for(i = 0; i < n ; i++){
        printf("%d ,",a[i]);
    }
}