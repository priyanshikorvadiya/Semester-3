//Write a program to delete a number at a given location in an array. 

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

    if(index >= n || index < 0){
        printf("Invalid Index !!");
    }
    else{
        //Shifting an element(Left)
        for(i = index ; i <= n - 1; i++){
            a[index] = a[index + 1];
        }
    }

    n--;

    for(i = 0; i < n ; i++){
        printf("%d\n,",a[i]);
    }
}