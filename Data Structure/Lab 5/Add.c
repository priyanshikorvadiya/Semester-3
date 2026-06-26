// Read two 2x2 matrices and perform addition of matrices into third matrix and 
//print it .

#include<stdio.h>
void main(){
    int a[2][2],b[2][2];
    int sum[2][2];

    printf("Enter elements of 1st matrix :");
    for(int i = 0 ; i < 2 ;i++){
        for(int j = 0 ; j < 2 ; j++){
            scanf("%d",&a[i][j]);
        }
    }

    printf("Enter elements of 2nd matrix :");
    for(int i = 0 ; i < 2 ;i++){
        for(int j = 0 ; j < 2 ; j++){
            scanf("%d",&b[i][j]);
        }
    }

    for(int i = 0 ; i < 2 ;i++){
        for(int j = 0 ; j < 2 ; j++){
            sum[i][j] = a[i][j] + b[i][j];
        }
    }

    printf("Multipliction of both matrix :");
    for(int i = 0 ; i < 2 ;i++){
        for(int j = 0 ; j < 2 ; j++){
            printf("%d",sum[i][j]);
        }
    }
}