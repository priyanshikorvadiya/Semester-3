// Write a program to convert infix notation to postfix notation using stack.

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define N 100

char S[N];
int top = 0; 

int IPF(char ch) {
    if (ch == '+' || ch == '-'){ 
        return 1;
    }
    if (ch == '*' || ch == '/'){ 
        return 3;
    }
    if (ch == '^'){              
        return 6;
    }
    if (isalnum(ch)){            
        return 7;
    }
    if (ch == '('){              
        return 9;
    }
    if (ch == ')'){
        return 0;
    }        
    return -1;
}

int SPF(char ch) {
    if (ch == '+' || ch == '-'){ 
        return 2;
    }
    if (ch == '*' || ch == '/'){ 
        return 4;
    }
    if (ch == '^'){              
        return 5;
    }
    if (isalnum(ch)){            
        return 1;
    }
    if (ch == '('){              
        return 0;
    }
    return 0;
}

int RANK(char ch) {
    if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^') {
        return -1;
    }
    if (isalnum(ch)) {
        return 1;
    }
    return 0;
}

void PUSH(char x) {
    if (top < N - 1) {
        S[++top] = x;
    } else {
        printf("Stack Overflow!\n");
    }
}

char POP() {
    if (top > 0) {
        return S[top--];
    }
    return '\0';
}

void Conversion(const char *input) {
    char INFIX[N];
    int p_index = 0;
    
    strcpy(INFIX, input);
    int len = strlen(INFIX);
    INFIX[len] = ')';
    INFIX[len + 1] = '\0';
    
    top = 0; 
    PUSH('(');
    
    char POLISH[N] = "\0";
    int rank = 0;
    int index = 0;
    char Next = INFIX[index++];
    
    while (Next != '\0') {
        if (top < 1) {
            printf("Stack Underflow!\n");
            return;
        }
        
        if (isalnum(Next)) {
            POLISH[p_index++] = Next;
            POLISH[p_index] = '\0';
            
            rank = rank + RANK(Next);
            if (rank < 1) {
                printf("Rank can't be less than 1!! Current Rank: %d\n", rank);
                return;
            }
        } 
      
        else {
            while (SPF(S[top]) > IPF(Next)) {
                char temp = POP();
                POLISH[p_index++] = temp;
                POLISH[p_index] = '\0';
                
                rank = rank + RANK(temp);
                if (rank < 1) {
                    printf("Rank can't be less than 1!! Current Rank: %d\n", rank);
                    return;
                }
            }
            
            if (SPF(S[top]) != IPF(Next)) {
                PUSH(Next);
            } else {
                POP(); 
            }
        }
        
        Next = INFIX[index++];
    }


    if (top != 0 || rank != 1) {
        printf("ERROR : Final Evaluation is Invalid: Top = %d, Rank = %d\n", top, rank);
    } else {
        printf("Infix exp   : %s\n", input);
        printf("Postfix exp : %s\n", POLISH);
    }
}

void main() {
    char exp[N];
    printf("Enter infix exp : ");
    if (scanf("%99s", exp) == 1) {
        Conversion(exp);
    }
}
