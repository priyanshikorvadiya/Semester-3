//WAP to implement stack using singly linked list.

struct Node
{
    int info;
    struct Node *link;
};

#include<stdio.h>
#include<stdlib.h>

struct Node *top = NULL;

void PUSH(int x){
    struct Node * newNode = (struct Node*)malloc(sizeof(struct Node));

    if(!newNode){
        printf("Memory Allocation Failed !!");
        return;
    }
    else{
        newNode->info = x;
        newNode->link = top;
        top = newNode;
    }   
}

void POP(){
    if(top == NULL){
        printf("Stack Underflow!!");
        return;
    }

    struct Node *temp = top;
    printf("%d\n",temp->info);
    top = top->link;
    free(temp);
}

void DISPLAY(){
    if(top == NULL){
        printf("Stack Underflow!!");
        return;
    }
    else{
        struct Node * save = top;

        while(save != NULL){
            printf("%d ->",save->info);
            save = save->link;
        }
        printf("NULL\n");
    }
}

void main(){
    int choice = 0, val, pos,i;

    while (1) {
        printf("\n--- Stack Operation Menu ---\n");
        printf("1-Push an element.\n");
        printf("2-Pop an element.\n");
        printf("3-Display stack.\n");
        printf("4-Exit\n");

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
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }
}