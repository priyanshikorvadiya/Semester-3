// Write a program to swap two consecutive nodes in the linked list. Don’t change 
//the values of nodes, implement by changing the link of the nodes. 
// Input: 1 → 2 → 3 → 4 → 5 → 6 → 7 → 8 
// Output: 2 → 1 → 4 → 3 → 6 → 5 → 8 → 7 

#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int info;
    struct Node *link;
};

struct Node *first = NULL;

void insertAtFirst(int x){

    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node*));

    newNode->info = x;
    newNode->link = first;

    first = newNode;
}

void display(){
    struct Node *save = first;

    if(first == NULL){
        printf("List is Empty!");
        return;
    }

    while(save != NULL){
        printf("%d->",save->info);
        save = save->link;
    }
    printf("NULL");
}

void Swap(){
    struct Node *save = first;
    struct Node *second;
    struct Node *third;

    first = save->link;//to give reference to second node in list

    while(save != NULL && save->link != NULL){

        third = save->link->link;
        second = save->link;
        second->link = save;

        if(third != NULL && third->link != NULL){
            save->link = third->link;
        }
        else{
            save->link = third;
        }
        save = third;
    }
}

void main(){

    insertAtFirst(8);
    insertAtFirst(7);
    insertAtFirst(6);
    insertAtFirst(5);
    insertAtFirst(4);
    insertAtFirst(3);
    insertAtFirst(2);
    insertAtFirst(1);

    display();

    Swap();

    display();
}