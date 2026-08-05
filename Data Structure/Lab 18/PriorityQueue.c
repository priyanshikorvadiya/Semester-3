// WAP to implement Priority Queue.

#include<stdio.h>
#include<stdlib.h>

#define N 7

struct PriorityQueue {
    int data;
    int priority;
};

struct PriorityQueue pq[N];
int PI = 0;

void INSERT(int x,int p){

    if(PI == N){
        printf("Priority Queue Overflow!!");
        return;
    }

    pq[PI].data = x;
    pq[PI].priority = p;
    PI++;
}

void DELETE(){
    if(PI == 0){
        printf("Priority queue underflow!");
        return;
    }

    int highestPI = 0;

    for(int i = 0 ; i < PI ; i++){
        if(pq[i].priority > pq[highestPI].priority){
            highestPI = i;
        }
    }

    int Y = pq[highestPI].data;
    int Ypriority = pq[highestPI].priority;

    printf("Dequeued element : [Value : %d (Priority : %d)]  ",Y,Ypriority);
    printf("\n");

    for(int i = highestPI; i < PI; i++){
        pq[i] = pq[i + 1];
    }
    PI--;
}

void DISPLAY(){

    if(PI == 0){
        printf("Priority Queue Underflow!!");
        return;
    }

    for(int i = 0 ; i < PI; i++){
        printf("[Value : %d(Priority : %d)] ",pq[i].data,pq[i].priority);
    }

    printf("\n");
}

void main() {
    int choice = 0,prio, val, pos,i;

    while (1) {
        printf("\n--- Queue Operation Menu ---\n");
        printf("1-Enqueue an element in priority queue.\n");
        printf("2-Dequeue an element in priority queue.\n");
        printf("3-Display priority queue.\n");

        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value:");
                scanf("%d",&val);
                printf("Enter priority:");
                scanf("%d",&prio);
                INSERT(val,prio);
                break;
            case 2:
                DELETE();
                break;
            case 3:
                DISPLAY();
                break;
            default:
                printf("Invalid choice.\n");
        }
    }
}
