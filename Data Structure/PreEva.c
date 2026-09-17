// Write a program for evaluation of prefix Expression using Stack.

#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<math.h>

#define MAX 100
int stack[MAX];
int top = -1;

void push(int x){
    if(top >= MAX - 1){
        return;
    }
    stack[++top] = x;
}

int pop(){
    if(top < 0){
        printf("Stack underflow!!");
        return -1;
    }
    return stack[top--];
}

int Evaluation(char exp[]){
    int i = 0;
    char ch;
    int op1,op2;

    while(exp[i] != '\0'){
        ch = exp[i];

        if(isdigit(ch)){
            push(ch - '0');
        }
        else{
            op1 = pop();
            op2 = pop();

            switch (ch)
            {
            case '+':
                push(op1 + op2);
                break;
            case '-':
                push(op1 - op2);
                break;
            case '*':
                push(op1 * op2);
                break;
            case '/':
                push(op1 / op2);
                break;
            case '^':
                push((int)pow(op2,op1));
                break;
            }
        }
        i++;
    }
        return pop();
}

void main(){
    char exp[100];

    printf("Enter prefix exp :");
    scanf("%s",exp);
    strrev(exp);
    printf("Result is : %d\n",Evaluation(exp));
}
