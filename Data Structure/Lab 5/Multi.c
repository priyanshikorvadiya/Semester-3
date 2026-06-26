//Read two matrices, first 3x2 and second 2x3, perform multiplication operation 
//and store result in third matrix and print it

#include<stdio.h>
void main(){
    int a[3][2],b[2][3];
    int mul[3][3];

    printf("Enter elements of 1st matrix :");
    for(int i = 0 ; i < 3 ;i++){
        for(int j = 0 ; j < 2 ; j++){
            scanf("%d",&a[i][j]);
        }
    }

    printf("Enter elements of 2nd matrix :");
    for(int i = 0 ; i < 2 ;i++){
        for(int j = 0 ; j < 3 ; j++){
            scanf("%d",&b[i][j]);
        }
    }

    for(int i = 0 ; i < 2 ;i++){
        for(int j = 0 ; j < 2 ; j++){
            mul[i][j] = 0;
            for(int k = 0 ; k < 2;k++){
                mul[i][j] += a[i][j] * b[i][j];
            }
        }
    }

    printf("Multiplication of both matrix :");
    for(int i = 0 ; i < 3 ;i++){
        for(int j = 0 ; j < 3 ; j++){
            printf("%d",mul[i][j]);
        }
    }
}