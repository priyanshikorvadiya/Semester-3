//  Write a menu driven program to implement following operations on the doubly 
// linked list. 
//  Insert a node at the front of the linked list. 
//  Delete a node from specified position. 
//  Insert a node at the end of the linked list. (Home Work) 
//  Display all nodes. (Home Work) 

#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int info;
    struct Node *lptr;
    struct Node *rptr;
};

struct Node *first = NULL;

void InsertAtFirst(int x){
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node*));
    
    if(first == NULL){
        newNode->lptr = NULL;
        newNode->info = x;
        newNode->rptr = NULL;

        first = newNode;
    }

    else{
        newNode->rptr = first;
        newNode->info = x;
        first->lptr = newNode;
        first= newNode;
    }
}

void DeleteAtFirst(){
    struct Node *temp;

    if(first == NULL){
        printf("Empty LIst!");
        return;
    }

    if(first->rptr == NULL){
        temp = first;
        first = NULL;
        free(temp);
    }
    else{
        temp = first;
        first->rptr->lptr = NULL;
        first = first->rptr;

        free(temp);
    }
}

void DeleteAtLast(){
    struct Node *temp;

    if(first == NULL){
        printf("Empty List !");
        return;
    }

    struct Node *save = first;

    if(first->rptr == NULL){
        temp = first;
        first = NULL;
        free(temp);
    }
    else{
        while(save->rptr->rptr != NULL){
            save = save->rptr;
        }

        temp = save->rptr;
        save->rptr = NULL;
        free(temp);
    }
}

int Count(){
    
    if(first == NULL){
        printf("Empty List !");
        return 0;
    }

    struct Node *save = first;
    int count = 0;

    while (save != NULL)
    {
        count++;
        save = save->rptr;
    }
    return count;
}

void DeleteKthPosition(int k){
    int n = Count();
    struct Node *save = first;
    struct Node *temp;

    if(k < 0 || k >= n){
        printf("Invalid position!!");
        return;
    }
    else if(k == 0){
        DeleteAtFirst();
        return;
    }
    else if(k == n - 1){
        DeleteAtLast();
        return;
    }
    else{

        for(int i = 0 ; i < k ; i++){
            save = save->rptr;
        }
        temp = save;
        save->rptr = save->rptr->lptr;
        save->rptr->lptr = save;
        free(temp);
    }
}

void InsertAtLast(int x){
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node*));
    
    if(first == NULL){
        newNode->info = x;
        newNode->lptr = NULL;
        newNode->rptr = NULL;
        first = newNode;
    }

    struct Node *save = first;

    while(save->rptr != NULL){
        save = save->rptr;
    }

    newNode->info = x;
    newNode->lptr = save;
    newNode->rptr = NULL;

    save->rptr = newNode;
}

void Display(){
    
    if(first == NULL){
        printf("Empty List!!");
        return;
    }

    struct Node *save = first;

    while(save != NULL){
        printf("%d ->",save->info);
        save = save->rptr;
    }
    printf("NULL\n");
}

void main(){
  
    int choice,val,k;

    while(1){
        printf("Enter your choice (1-5)\n");
        printf("1-Insert a node at the front of the linked list.\n");
        printf("2-Delete a node from specified position.\n");
        printf("3-Insert a node at the end of the linked list.\n");
        printf("4-Display all nodes.\n");
        printf("5-Exit\n");
        scanf("%d",&choice);

        switch (choice)
        {
        case 1:
            printf("Enter value to insert :");
            scanf("%d",&val);
            InsertAtFirst(val);
            break;

        case 2:
            printf("Enter position where you want to delete:");
            scanf("%d",&k);
            DeleteKthPosition(k);
            break;

        case 3:
            printf("Enter value to insert :");
            scanf("%d",&val);
            InsertAtLast(val);
            break;

        case 4:
            Display();
            break;

        case 5:
            printf("Exiting program.\n");
            exit(0);
        
        default:
            printf("Invalid choice");
        }
    }
}