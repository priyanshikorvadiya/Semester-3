//Write a program to remove the duplicates nodes from given sorted Linked List. 
//Input: 1 → 1 → 6 → 13 → 13 → 13 → 27 → 27 
// Output: 1 → 6 → 13 → 27

#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int info;
    struct Node *link;
};

struct Node *First;

struct Node *insertatFirst(int x){

    struct Node *newNode = (struct Node*)malloc(sizeof (struct Node));
    newNode -> info = x;
    newNode -> link = First; 

    First = newNode;

    return First;
}

void display(struct Node *first){

    if(first == NULL){
        printf("Empty List1");
        return;
    }

    struct Node *save = first;

    while(save != NULL){
        printf("%d ->",save->info);
        save = save -> link;
    }
    printf("NULL\n");
}

void removeDuplicate(){

    if(First == NULL){
        printf("List is empty!");
        return;
    }

    struct Node *save = First;

    while(save != NULL && save->link != NULL){
        if(save->info == save->link->info){
            struct Node *temp = save->link;
            save->link = save->link->link;
            free(temp);
        }
        else{
            save = save->link;
        }
    }

}

void main(){

    insertatFirst(27);
    insertatFirst(27);
    insertatFirst(13);
    insertatFirst(13);
    insertatFirst(13);
    insertatFirst(6);
    insertatFirst(1);
    insertatFirst(1);

    display(First);

    removeDuplicate();
    
    display(First);

}