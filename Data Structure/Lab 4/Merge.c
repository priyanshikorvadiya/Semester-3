//Write a program to merge two unsorted arrays. 

#include<stdio.h>
void main (){
    int n1,n2,a1[n1],a2[n2];
    int n,A[n];

    printf("Enter size for Array 1:");
    scanf("%d",&n1);

    printf("Enter size for Array 2:");
    scanf("%d",&n2);

    for(int i = 0 ; i < n1 ;i++){
        scanf("%d",&a1[i]);
    }

    for(int i = 0 ; i < n2 ;i++){
        scanf("%d",&a2[i]);
    }

    for(int i = 0 ; i < n1 ;i++){
        A[i] = a1[i];
    }
    for(int i = 0 ; i < n2 - 1 ;i++){
        A[n1 + i] = a2[i];
    }

    n = n1 + n2;

    for(int i = 0 ; i < n ;i++){
        printf("%d",A[i]);
    }
}