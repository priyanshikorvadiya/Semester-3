//WAP to copy a linked list.

#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int info;
    struct Node * link;
};

struct Node *first1;
struct Node *first2;

void insertAtFirst(int x){

    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node*));

    newNode->info = x;
    newNode->link = first1;

    first1 = newNode;
}

void display(struct Node *first){
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

void insertAtLast(int x){
    struct Node *newNode = NULL;
    struct Node *save = first2;

    while(save->link != NULL){
        save = save->link;
    }
    save->link = newNode;
    newNode->link = NULL;
}

void CopyList(struct Node *first){
    struct Node *save1 = first;

    while (save1 != NULL)
    {
        insertAtLast(save1 -> info);
        save1 = save1->link;
    }
    
}

void main(){
    insertAtFirst(1);
    insertAtFirst(2);
    insertAtFirst(3);
    insertAtFirst(4);

    CopyList(first1);
    display(first1);

}
