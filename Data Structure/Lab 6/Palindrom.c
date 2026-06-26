//WAP to check whether the string is Palindrome or not using Pointer. 

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void main(){

    char *str = (char *)malloc(100 * sizeof(char));
    char *revstr = (char *)malloc(100 * sizeof(char));

    printf("Enter word:");
    scanf("%s",str);

    if(str == NULL || revstr == NULL){
        printf("Allocation failed!!");
    }

    strcpy(revstr,str);
    strrev(revstr);

    if(strcmp(revstr,str) == 0){
        printf("Palindrom");
    }
    else{
        printf("Not palindrom");
    }
}