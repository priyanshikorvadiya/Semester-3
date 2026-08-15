// Write a program to implement queue using singly linked list. 

#include<stdio.h>
#include<stdlib.h>

struct Node{
    int info;
    struct Node *link;
};

struct Node * F = NULL;
struct Node * R = NULL;

void ENQUEUE(int x){
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));

    if(newNode == NULL){
        printf("Memory Allocation Failed!");
        return;
    }

    newNode->info = x;
    newNode->link = NULL;

    if(R == NULL){
        F = R = newNode;
    }
    else{
        R->link = newNode;
        R = newNode;
    }
}

void DEQUEUE(){
    if(F == NULL){
        printf("Queue underflow!!");
        return;
    }

    struct Node *temp = F;
    printf("%d\n",F);

    F = F->link;

    if(F == NULL){
        R = NULL;
    }
    free(temp);
}

void DISPLAY(){
    if(F == NULL){
        printf("Queue underflow!!");
        return;
    }

    struct Node *save = F;

    while(save != NULL){
        printf("%d ->",save->info);
        save = save->link;
    }
    printf("NULL\n");
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
