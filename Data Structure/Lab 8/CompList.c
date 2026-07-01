// WAP to check whether 2 singly linked lists are same or not. 

#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int info;
    struct Node *link;
};

struct Node *First1;
struct Node *First2;

struct Node *insertatFirst(struct Node *first,int x){

    struct Node *newNode = (struct Node*)malloc(sizeof (struct Node));
    newNode -> info = x;
    newNode -> link = first; 

    first = newNode;

    return first;
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

void Compare(){

    struct Node *save1 = First1;
    struct Node *save2 = First2;

    int issame = 0;

    while(save1 != NULL && save2 != NULL){
        if(save1 -> info != save2 -> info){
            issame = 1;
            break;
        }
            save1 = save1 -> link;
            save2 = save2 -> link;
    }

    if(save1 == NULL && save2 == NULL && issame == 0){
        printf("Given Linked Lists are same.");
    }
    else{
        printf("Given Linked Lists are not same!");
    }
}

void main(){

   First1 = insertatFirst(First1, 9);
   First1 = insertatFirst(First1, 8);
   First1 = insertatFirst(First1, 7);
   First1 = insertatFirst(First1, 6);

   First2 = insertatFirst(First2, 9);
   First2 = insertatFirst(First2, 8);
   First2 = insertatFirst(First2, 7);
   First2 = insertatFirst(First2, 6);

    display(First1);
    display(First2);

    Compare();

}
