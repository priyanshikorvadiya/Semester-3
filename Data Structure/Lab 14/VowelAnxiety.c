//  Vowel Anxiety Problem 
// Utkarsh has recently started taking English-language classes to improve his 
// reading and writing skills. However, he is still struggling to learn English. His 
// teacher gave him the following problem to improve his vowel-identification 
// skills:  
 
// There is a string S of length N consisting of lowercase English letters only.  
// Utkarsh has to start from the first letter of the string. 
// Each time he encounters a vowel; he has to reverse the entire substring that 
// came before the vowel. 
// Utkarsh needs help verifying his answer. Can you print the final string after 
// performing all the operations for him? 
 
// Input Format: 
//  First line will contain T, number of test cases. Then T test cases follow. 
//  The first line of each test case contains N, the length of the string. 
//  The second line contains S, the string itself. 
 
// Output Format: 
// For each test case, output in a single line the final string after traversing S from 
// left to right and performing the necessary reversals. 

#include<stdio.h>
#include<stdlib.h>
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

void reverse(){
    for(int i = 0 ; i <= top/2 ; i++){
        char temp = S[i];
        S[i] = S[top - i];
        S[top - i] = temp;
    }
}

void vowelCheck(char c[i]){

    while (c[i] != '\0') {

    
        if (c[i] == 'a' || c[i] == 'e' || c[i] == 'i' || c[i] == 'o' || c[i] == 'u' ||
            c[i] == 'A' || c[i] == 'E' || c[i] == 'I' || c[i] == 'O' || c[i] == 'U') {
            reverse();
        }
        PUSH(c[i]);
        i++;
    }
}

void main(){
    printf("Enter string :");
    scanf("%s",str);

    vowelCheck(str);

    printf("Output string :");
    DISPLAY();
}
