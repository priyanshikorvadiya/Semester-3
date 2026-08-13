//  You have an array A of integers of size N, an array B (initially empty) and a stack 
// S (initially empty). You are allowed to do the following operations: 
 
//  Take the first element of array A and push it into S and remove it from A. 
//  Take the top element from stack S, append it to the end of array B and 
// remove it from S. 
 
// You have to tell if it possible to move all the elements of array A to array B using 
// the above operations such that finally the array B is sorted in ascending order. 
 
// Input Format : 
//  First line will contain T, number of testcases. Then the testcases follow. 
//  First line of each testcase contains a single integer N. 
//  Second line of each testcase contains N distinct integers : A1,A2...AN. 
 
// Output Format : 
// For each testcase, if it possible to move all the elements of array A to array B 
// using the above operations such that finally, the array B is sorted in ascending 
// order, print "YES" (without quotes), else print "NO" (without quotes).


#include<stdio.h>
#include<stdlib.h>  

int Compare(const void *a, const void *b){
    return (*(int *)a - *(int *)b);
}

void Solve(){
    int n;

    printf("Enter number of integers:");
    scanf("%d",&n);

    int *A = (int *)malloc(sizeof(int) * n);
    int *sorted_A = (int *)malloc(sizeof(int) * n);
    int *S = (int *)malloc(sizeof(int) * n);

    printf("Enter elements :");
    for(int i = 0 ; i < n ; i++){
        scanf("%d",&A[i]);
        sorted_A[i] = A[i];
    }

    qsort(sorted_A , n , sizeof(int) , Compare);

    int top = -1;
    int expected_idx = 0;

    for(int i = 0 ; i < n ; i++){
        S[++top] = A[i];

        while(top >= 0 && S[top] == sorted_A[expected_idx]){
            top--;
            expected_idx++;
        }
    }

    if(top == -1){
        printf("Yes\n");
    }
    else{
        printf("No\n");
    }

    free(A);
    free(sorted_A);
    free(S);
}

void main(){
    int T;

    printf("Enter T:");
    scanf("%d",&T);

        while(T--){
            Solve();
        }
}
