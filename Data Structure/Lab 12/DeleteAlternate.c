// WAP to delete alternate nodes of a doubly linked list.

#include<stdio.h>
#include<stdlib.h>

struct Node{
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
        newNode->lptr = NULL;
        first->lptr = newNode;
        first= newNode;
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

void Deletion(){
    int n = Count();

    if(first == NULL){
        printf("Empty List!!");
        return;
    }
    else if(first->rptr == NULL){
        printf("Deletion not possible!");
        return;
    }
    else{
        struct Node *save = first;
        struct Node *temp = NULL;

        while(save != NULL && save->rptr != NULL){
            temp = save->rptr;
            save->rptr = save->rptr->rptr;

            if(save->rptr != NULL){
                save->rptr->lptr = save;
            }

            free(temp);

            save = save->rptr;
        }
    }
}

void main(){

    InsertAtFirst(9);
    InsertAtFirst(8);
    InsertAtFirst(7);
    InsertAtFirst(6);
    InsertAtFirst(5);
    InsertAtFirst(4);

    Display();

    Deletion();

    Display();
}