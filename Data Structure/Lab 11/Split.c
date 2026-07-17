//WAP to split a circular linked list into two halves. 

#include<stdio.h>
#include<stdlib.h>

struct Node{
    int info;
    struct Node* link;
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

void Display(struct Node* first){
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

struct Node* SplitList(){

    if(first == NULL || first->link == first){
        printf("Spliting not possible!!");
        return NULL;
    }

    struct Node *slow = first;
    struct Node *fast = first;

    while(fast->link != first && fast->link->link != first){
        slow = slow->link;
        fast = fast->link->link;
    }

    struct Node *first2 = slow->link;
    slow->link = first;

    last->link = first2;

    printf("First Half :");
    Display(first);

    printf("Second Half :");
    Display(first2);
}

void main(){

    InsertAtFirst(9);
    InsertAtFirst(8);
    InsertAtFirst(7);
    InsertAtFirst(6);

    SplitList();
}