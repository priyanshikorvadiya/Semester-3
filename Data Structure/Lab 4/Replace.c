// WAP to replace lowercase characters by uppercase & vice-versa in a user 
//specified string. 

#include<stdio.h>
#include<string.h>
void main(){
    char S[100];

    printf("Enter String :");
    scanf("%s",S[100]);

    for(int i = 0; i < 100; i++){
        if('a' <= S[i] && 'z' >= S[i]){
            S[i] = S[i] - 32;
        }
        else if('A' <= S[i] && 'z' >= S[i]){
            S[i] = S[i] + 32;
        }
    }

    printf("%d",S[100]);
}