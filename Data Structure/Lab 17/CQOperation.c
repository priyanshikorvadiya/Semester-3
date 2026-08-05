//  Write a menu driven program to implement following operations on a circular 
// queue using an Array 
//  Insert 
//  Delete 
//  Display all elements of the queue

#include<stdio.h>
#include<stdlib.h>

#define N 10

int R = -1,F = -1;
int CQ[N];

void CQInsert(int x){
    if(((R + 1) % N) == F){
        printf("Queue overflow!");
        return;
    }
    
    if(F == -1){
        F = 0;
        R = 0;
    }
    else{
        R = (R + 1) % N;
    }
    CQ[R] = x;
}

int CQDelete(){
    if(F == -1 ){
        printf("Queue underflow!!");
        return -1;
    }
    else{
        int Y = CQ[F];

        if(F == R){
            F = -1;
            R = -1;
        }
        else{
            F = (F + 1) % N;
        }
        return Y;
    }
}

void DISPLAY(){
    if(F == -1){
        printf("Queue underfloe!");
        return;
    }
    int i = F;

    while(1){
        printf("%d",CQ[i]);
        if(i == R){
            break;
        }
        i = (i + 1) % N;
    }
    printf("\n");
}

void main() {
    int choice = 0, val, pos,i;

    while (1) {
        printf("\n--- Circular Queue Operation Menu ---\n");
        printf("1-Enqueue an element.\n");
        printf("2-Dequeue an element.\n");
        printf("3-Display queue.\n");

        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value:");
                scanf("%d",&val);
                CQInsert(val);
                break;
            case 2:
                CQDelete();
                break;
            case 3:
                DISPLAY();
                break;
            default:
                printf("Invalid choice.\n");
        }
    }
}