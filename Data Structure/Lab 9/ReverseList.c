//WAP to reverse a linked list.

#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int info;
    struct Node *link;
};

struct Node *first;

void insertAtFirst(int x){
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node*));

    if(newNode == NULL){
        printf("Memory allocation failed!List is Empty!!");
        return;
    }

    newNode->info = x;
    newNode->link = first;

    first = newNode;
}

void display(){
    struct Node *save = first;

    if(first == NULL){
        printf("Empty List!!");
        return;
    }

    while(save != NULL){
        printf("%d->",save->info);
        save = save->link;
    }
    printf("NULL");
}

void reverseList(){
    struct Node *prev = NULL;
    struct Node *save = first;
    struct Node *next = NULL;

    while(save != NULL){
        next = save->link;
        save->link = prev;

        prev = save;
        save = next;

    }
    first = prev;
}

void main(){

    insertAtFirst(9);
    insertAtFirst(8);
    insertAtFirst(7);
    insertAtFirst(6);

    display();

    reverseList();

    display();
}
