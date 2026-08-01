// Valid Parenthesis Problem 
// Chef has a string which contains only the characters '{', '}', '[', ']', '(' and ')'.  
// Now Chef wants to know if the given string is balanced or not.  
// If is balanced then print 1, otherwise print 0.  
// A balanced parenthesis string is defined as follows: 
//  The empty string is balanced 
//  If P is balanced then (P), {P}, [P] is also balanced 
//  if P and Q are balanced PQ is also balanced 
//  "([])", "({})[()]" are balanced parenthesis strings  
//  "([{]})", "())" are not balanced. 
 
// Input Format:  
// The first line of the input contains a single integer T denoting the number of 
// test cases. The description of T test cases follows. The first and only line of 
// each test case contains a single string 
 
// Output Format:  
// For each test case, print a single line containing the answer.

#include<stdio.h>
#include<string.h>

#define n 100
int top = -1;
char S[n];

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

int CheckParenthesis(char c[]){
    int i = 0;

    while (c[i] != '\0')
    {
            char checkChar;

    if(c[i] == '(' || c[i] == '{' || c[i] == '['){
        PUSH(c[i]);
    }
    else if(c[i] == ')' || c[i] == '}' || c[i] == ']'){
        if(top == -1){
            return 0;
        }
        checkChar = POP();

        if((c[i] == ')' && checkChar != '(') || (c[i] == '}' && checkChar != '{') || (c[i] == ']' && checkChar =='[')){
            return 0;
        }
    }
    i++;
    }

    if(top == -1){
        return 1;
    }
    else{
        return 0;
    }
}
    

void main(){
    char str[100];

    printf("Enter string :");
    scanf("%s",str);

    top = -1;

    printf("%d\n",CheckParenthesis(str));
}