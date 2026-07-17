//Write a program to sort elements of a linked list.

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

void Sort(){

    struct Node *save;
    struct Node *save2;

    for(save = first ; save->link != NULL ; save = save->link){
        for(save2 = save->link ; save2 != NULL ; save2 = save2->link){
            if(save->info > save2->info){
                int temp = save->info;
                save->info = save2->info;
                save2->info = temp;
            }
        }
    }
}

void main(){

    insertAtFirst(2);
    insertAtFirst(7);
    insertAtFirst(0);
    insertAtFirst(4);
    insertAtFirst(8);

    display();

    Sort();

    display();
}
