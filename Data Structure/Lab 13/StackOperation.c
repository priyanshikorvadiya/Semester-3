// Write a menu driven program to implement following operations on the Stack 
// using an Array 
//  PUSH, POP, DISPLAY 
//  PEEP, CHANGE

#include<stdio.h>
#include<stdlib.h>

#define n 5
int Stack[n],top = -1;

void PUSH(int x){
    if(top == n - 1){
        printf("Stack overflow!");
        return;
    }
    else{
        Stack[++top] = x;
    }
}

int POP(){
    if(top == -1){
        printf("Stack underflow!");
        return -1;
    }
    else{
        return Stack[top--];
    }
}

void DISPLAY(){
    if(top == -1){
        printf("Stack underflow!");
        return;
    }
    else{
        for(int i = top ; i >= 0 ; i--){
            printf("%d",Stack[i]);
        }
        printf("\n");
    }
}

int PEEP(int i){
    if(top - i + 1 < 0 || i <= 0){
        printf("Invalid Index");
        return -1;
    }
    else{
        return Stack[top - i + 1];
    }
}

void CHANGE(int i , int x){
    if(top - i + 1 < 0 || i <= 0){
        printf("Invalid index!");
        return;
    }
    else{
        Stack[top - i + 1] = x;
    }
}

void main() {
    int choice = 0, val, pos,i;

    while (1) {
        printf("\n--- Stack Operation Menu ---\n");
        printf("1-Push an element.\n");
        printf("2-Pop an element.\n");
        printf("3-Display stack.\n");
        printf("4-Peep an element.\n");
        printf("5-Change an element.\n");
        printf("6-Exit\n");

        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value:");
                scanf("%d",&val);
                PUSH(val);
                break;
            case 2:
                POP();
                break;
            case 3:
                DISPLAY();
                break;
            case 4:
                printf("Enter index: ");
                scanf("%d", &i);
                PEEP(i);
                break;
            case 5:
                printf("Enter index: ");
                scanf("%d", &i);
                printf("Enter value: ");
                scanf("%d", &val);
                CHANGE(i,val);
                break;
            case 6:
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }
}
