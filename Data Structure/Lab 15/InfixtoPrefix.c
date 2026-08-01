// Write a program to convert infix notation to prefix notation using stack.

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define N 100

char S[N];
int top = -1; 

int IPF(char ch) {
    if (ch == '+' || ch == '-') {
        return 1;
    }
    if (ch == '*' || ch == '/') {
        return 3;
    }
    if (ch == '^') {
        return 6;
    }
    if (ch == ')') {
        return 0;
    }
    if (ch == '(') {
        return 9;
    }
    return -1;
}

int SPF(char ch) {
    if (ch == '+' || ch == '-') {
        return 2;
    }
    if (ch == '*' || ch == '/') {
        return 4;
    }
    if (ch == '^') {
        return 5;
    }
    if (ch == ')') {
        return 0;
    }
    if (ch == '(') {
        return 0;
    }
    return 0;
}

void PUSH(char x) {
    if (top < N - 1) {
        S[++top] = x;
    } else {
        printf("\nStack Overflow!\n");
    }
}

char POP() {
    if (top >= 0) {
        return S[top--];
    }
    return '\0';
}

void reverseString(char *str) {
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++) {
        char temp = str[i];
        str[i] = str[len - 1 - i];
        str[len - 1 - i] = temp;
    }
}

void Conversion(const char *input) {
    char INFIX[N];
    char POLISH[N] = "\0";
    int p_index = 0;
    
    strcpy(INFIX, input);

    reverseString(INFIX);

    int len = strlen(INFIX);
    for (int i = 0; i < len; i++) {
        if (INFIX[i] == '(') {
            INFIX[i] = ')';
        } else if (INFIX[i] == ')') {
            INFIX[i] = '(';
        }
    }
    
    top = -1; 
    int index = 0;
    
    while (INFIX[index] != '\0') {
        char Next = INFIX[index];
        
        if (isalnum(Next)) {
            POLISH[p_index++] = Next;
            POLISH[p_index] = '\0';
        } else if (Next == '(') {
            PUSH(Next);
        } else if (Next == ')') {
            while (top >= 0 && S[top] != '(') {
                POLISH[p_index++] = POP();
                POLISH[p_index] = '\0';
            }
            POP(); 
        } else { 
            while (top >= 0 && SPF(S[top]) > IPF(Next)) { 
                POLISH[p_index++] = POP();
                POLISH[p_index] = '\0';
            }
            PUSH(Next);
        }
        index++;
    }
    
    while (top >= 0) {
        POLISH[p_index++] = POP();
        POLISH[p_index] = '\0';
    }
  
    reverseString(POLISH);

    printf("Result :\n");
    printf("Infix expression  : %s\n", input);
    printf("Prefix expression : %s\n", POLISH);
    fflush(stdout); 
}

int main() {
    char exp[N];
    printf("Enter infix exp : ");
    fflush(stdout);
    
    if (scanf("%99s", exp) == 1) {
        Conversion(exp);
    }
    return 0;
}
