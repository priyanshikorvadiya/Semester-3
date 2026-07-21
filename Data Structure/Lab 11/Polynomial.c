// Write a program to perform addition of two polynomial equations using 
// appropriate data structure.

#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int info;
    int power;   
    struct Node * link;
};

struct Node *first1 = NULL;
struct Node *first2 = NULL;
struct Node *result = NULL;

struct Node * InsertAtFirst(int x,int y, struct Node * first){
    struct Node * newNode = (struct Node*)malloc(sizeof(struct Node));

        newNode->info = x;
        newNode->power = y;
        newNode->link = first;
        first = newNode;
    return first;
}

void PolyAdd(){
    struct Node *temp1 = first1;
    struct Node *temp2 = first2;
    struct Node *revres = NULL;
    
    while(temp1 != NULL && temp2 != NULL){

        if(temp1->power > temp2->power){
            revres = InsertAtFirst(temp1->info,temp1->power,revres);
            temp1 = temp1->link;
        }
        else if(temp2->power > temp1->power){
            revres = InsertAtFirst(temp2->info,temp2->power,revres);
            temp2 = temp2->link;
        }

        else{
            revres = InsertAtFirst(temp1->info + temp2->info,temp1->power,revres);

            temp1 = temp1->link;
            temp2 = temp2->link;
        }
    }

    while(temp1 != NULL){
        revres = InsertAtFirst(temp1->info,temp1->power,revres);
        temp1 = temp1->link;
    }

    while(temp2 != NULL){
        revres = InsertAtFirst(temp2->info,temp2->power,revres);
        temp2 = temp2->link;
    }

    //Output is in reverse order because we have used insertatfirst
    //Below process will convert it in proper order

    struct Node *save = revres;

    while(save != NULL){
        result = InsertAtFirst(save->info,save->power,result);
        save = save->link;
    }
}

void Display(struct Node *first){
    if(first == NULL){
        printf("Empty List !!");
        return;
    }

    struct Node *save = first;

    while (save->link != NULL)
    {
        printf("%d x^ %d",save->info,save->power);
        save = save->link;

        if(save != NULL && save->info >= 0){
            printf("+");
        }
        else{
            printf(" ");
        }
    }

    printf("%d x^ %d",save->info,save->power);
}

void main(){

    first1 = InsertAtFirst(2,0,first1);
    first1 = InsertAtFirst(4,1,first1);
    first1 = InsertAtFirst(3,2,first1);

    printf("Polynomial 1 :\n");
    Display(first1);

    first2 = InsertAtFirst(6,0,first2);
    first2 = InsertAtFirst(3,1,first2);

    printf("Polynomial 2 :\n");
    Display(first2);

    printf("Result :\n");
    PolyAdd();
    Display(result);
}