//WAP to sort the N names in an alphabetical order. 

#include<stdio.h>
#include<string.h>
void main(){
    int n;
    char name[100][50],temp[50];

    printf("Enter number of words :");
    scanf("%d",&n);

    for(int i = 0; i < n; i++){
        scanf("%s",name[i]);
    }

    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n - 1 - i ; j++){

            if(strcmp(name[j],name[j + 1]) > 0){
                strcpy(temp , name[j]);
                strcpy(name[j] , name[j + 1]);
                strcpy(name[j + 1] , temp);
            }
        }
    }

    for(int i = 0; i < n; i++){
        printf("%s",name[i]);
    }
}