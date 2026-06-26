// Write a program to delete duplicate numbers from an array. 

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
        for(j = i+ 1; j < n ;j++){
            if(a[i] == a[j]){
                
                for(int k = j; k < n - 1; k++){
                    a[k] = a[k + 1];
                }
                n--;
                j--;
            }
        }
    }

    for(i = 0; i < n ; i++){
        scanf("%d\n",a[i]);
    }

}    