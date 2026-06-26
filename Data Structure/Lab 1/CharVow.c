#include<stdio.h>
void main(){
    char c;

    printf("Enter character :");
    scanf("%c",c);

    if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U'){
        printf("Given character is Vowel");
    }
    else{
        printf("Given character is consonant");
    }
}