// Write a program to find whether the array contains a duplicate number or not.

#include<stdio.h>
void main(){
    int n,a[n],i = 0,j = 0;

    printf("Enter size of an array(n) :");
    scanf("%d",&n);

    for(i = 0; i < n ; i++){
        printf("Enter element :");
        scanf("%d",&a[i]);
    }

    for(i = 0; i < n; i++){
        for(j = i+ 1; j < n + 1;j++){
            if(a[j] == a[j + 1]){
                printf("Duplicate");
                return;
            }
        }
    }
}