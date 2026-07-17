// Write a menu driven program to implement following operations on the circular 
// linked list. 
//  Insert a node at the front of the linked list. 
//  Delete a node from specified position. 
//  Insert a node at the end of the linked list. 
//  Display all nodes.

#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int info;
    struct Node * link;
};

struct Node *first = NULL;
struct Node *last = NULL;

void InsertAtFirst(int x){
    struct Node * newNode = (struct Node*)malloc(sizeof(struct Node*));

    if(first == NULL){
        newNode->info = x;
        first = newNode;
        last = newNode;
        newNode->link = first;
    }
    else{
    
        newNode->info = x;
        newNode->link = first;

        first = newNode;

        last->link = first;
    }
}

void InsertAtLast(int x){

    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node*));
    if(first == NULL){
        printf("Empty List !!");
        return;
    }
    else{
        newNode->info = x;
        newNode->link = first;
        last->link = newNode;

        last = newNode;
    }
}

int count(){
    int count = 0;

    if(first == NULL){
        printf("Empty List!!");
        return 0;
    }

    struct Node * save = first;

    while(save->link != first){
        count++;
        save = save->link;
    }

    return count;
}

void DeleteAtFirst(){
    if(first == NULL){
        printf("Empty List!!");
        return;
    }

    struct Node *temp = first;
    
    if(first->link == first){
        free(first);
        first = NULL;
        return;
    }

    struct Node *last = first;
    while (last->link != first)
    {
        last = last->link;
    }
    
    first = first->link;
    last->link = first;
    free(temp);
}

void DeleteAtLast(){

    if(first == NULL){
        printf("Empty List!!");
        return;
    }

    if(first->link == first){
        free(first);
        first = NULL;
        return;
    }

    struct Node *last = first;
    struct Node *prev = NULL;

    while(last->link != first){
        prev = last;
        last = last->link;
    }

    prev->link = first;
    free(last);
}

void DeleteAtKthPosi(int k){
    int n = count();

    //Zero indexing
    if(k < 0 || k >= n ){
        printf("Invalid position.");
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
        struct Node * save = first;

        for(int i = 0 ; i < k ; i++){
            save = save->link;
        }
        struct Node * temp = save->link;

        save->link = save->link->link;

        free(temp);
    }
}

void Display(){
    if(first == NULL){
        printf("Empty List !!");
        return;
    }

    struct Node *save = first;

    while(save->link != first){
        printf("%d ->",save->info);
        save = save->link;
    }
    printf("%d ->",save->info);
    printf("first");
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
            DeleteAtKthPosi(k);
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