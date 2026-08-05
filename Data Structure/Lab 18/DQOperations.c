// Write a menu driven program to implement following operations on the 
// Doubled Ended Queue using an Array 
//  Insert at front end, Insert at rear end 
//  Delete from front end, Delete from rear end 
//  Display all elements of the queue 

#include<stdio.h>

#define N 6

int Q[N];
int F = -1;
int R = -1;

void DQINSERT_FRONT(int x){

    if(F == 0){
        printf("DQueue Overflow at Front!!");
        return;
    }

    if(F == -1){
        F = 0;
        R = 0;
    }
    else{
        F = F - 1;
    }
    Q[F] = x;
}

void DQINSERT_REAR(int x){
    if(R == N - 1){
        printf("DQueue Overflow at Rear!!");
        return;
    }

    if(F == -1){
        F = 0;
        R = 0;
    }
    else{
        R = R + 1;
    }

    Q[R] = x;
}

int DQDELETE_FRONT(){

    if(F == -1){
        printf("DQueue Underflow at Front!");
        return -1;
    }

    int Y = Q[F];

    if(F == R){
        F = -1;
        R = -1;
    }
    else{
        F = F + 1;
    }
    return Y;
}

int DQDELETE_REAR(){

    if(R == -1){
        printf("DQueue Underflow at Rear!");
        return -1;
    }

    int Y = Q[R];

    if(F == R){
        F = -1;
        R = -1;
    }
    else{
        R = R - 1;
    }

    return Y;
}

void DQDISPLAY(){
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
        printf("1-Enqueue an element at front of DQueue.\n");
        printf("2-Enqueue an element at rear of DQueue.\n");
        printf("3-Dequeue an element at front of DQueue.\n");
        printf("4-Dequeue an element at rear of DQueue.\n");
        printf("5-Display DQueue.\n");

        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value:");
                scanf("%d",&val);
                DQINSERT_FRONT(val);
                break;
            case 2:
                printf("Enter value:");
                scanf("%d",&val);
                DQINSERT_REAR(val);
                break;
            case 3:
                DQDELETE_FRONT();
                break;
            case 4:
                DQDELETE_REAR();
                break;
            case 5:
                DQDISPLAY();
                break;
            default:
                printf("Invalid choice.\n");
        }
    }
}
