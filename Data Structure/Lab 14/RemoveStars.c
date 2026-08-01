// Removing starts from a string Problem 
// You are given a string s, which contains stars *. In one operation, you can: 
// Choose a star in s. Remove the closest non-star character to its left, as well as 
// remove the star itself. Return the string after all stars have been removed. 
 
// Note :  
//  The input will be generated such that the operation is always possible. 
//  It can be shown that the resulting string will always be unique.

#include<stdio.h>
#include<string.h>

#define n 100

int top = -1,i = 0;
char S[n];
char str[n];

void PUSH(char x){
    if(top == n - 1){
        printf("Stack overflow!");
        return;
    }
    else{
        S[++top] = x;
    }
}

char POP(){
    if(top == -1){
        printf("Stack Underflow!");
        return '\0';
    }
    else{
        return S[top--];
    }
}

void DISPLAY(){
    if(top == -1){
        printf("Stack underflow!");
        return;
    }
    else{
        for(int i = 0; i <= top ; i++){
            printf("%c",S[i]);
        }
        printf("\n");
    }
}

void Remove(){
    
    int len = strlen(str);

    for(int i = 0 ; i < len ; i++){
        if(str[i] == '*'){
            POP();
        }
        else{
            PUSH(str[i]);
        }
    }
}

void main(){
    printf("Enter string :");
    scanf("%s",str);

    Remove();

    printf("Output string :");
    DISPLAY();
}