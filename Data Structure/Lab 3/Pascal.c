//WAP to print Pascal triangle.

#include<stdio.h>
void main(){
    int n,a[n][n];

    printf("Enter n :");
    scanf("%d",&n);

    for(int i = 0; i < n; i++){
        for(int k = 0 ; k < n - i; k++){
            printf(" ");
        }
        for(int j = 0; j <= i; j++){
            
            if(j == 0 || j == i){
                a[i][j] = 1;
            }
            else{
                a[i][j] = a[i - 1][j] + a[i - 1][j - 1];
            }
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }
}