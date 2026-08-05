//  Write a menu driven program to implement following operations on the Queue 
// using an Array 
//  ENQUEUE 
//  DEQUEUE 
//  DISPLAY

#include<stdio.h>
#include<stdlib.h>

#define N 10

int R = -1,F = -1;
int Q[N];

void ENQUEUE(int x){
    if(R >= N - 1){
        printf("Queue overflow!");
        return;
    }
    else{
        if(F == -1){
            F = 0;
        }
        R++;
        Q[R] = x; 
    }
}

int DEQUEUE(){
    if(F == -1 ){
        printf("Queue underflow!!");
        return -1;
    }
    else{
        int Y = Q[F];

        if(F == R){
            F = -1;
            R = -1;
        }
        else{
            F++;
        }
        return Y;
    }
}

void DISPLAY(){
    if(F == -1){
        printf("Queue underfloe!");
        return;
    }
    for(int i = F ; i <= R; i++){
        printf("%d",Q[i]);
    }
    printf("\n");
}

void main() {
    int choice = 0, val, pos,i;

    while (1) {
        printf("\n--- Queue Operation Menu ---\n");
        printf("1-Enqueue an element.\n");
        printf("2-Dequeue an element.\n");
        printf("3-Display queue.\n");

        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value:");
                scanf("%d",&val);
                ENQUEUE(val);
                break;
            case 2:
                DEQUEUE();
                break;
            case 3:
                DISPLAY();
                break;
            default:
                printf("Invalid choice.\n");
        }
    }
}
