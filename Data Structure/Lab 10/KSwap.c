//WAP to swap Kth node from beginning with Kth node from end in a singly linked 
//list.

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

int count(){

    if(first == NULL){
        printf("Empty list!");
        return 0;
    }

    struct Node *save = first;
    int count = 0;

    while(save != NULL){
        count++;
        save = save->link;
    }
    return count;
}

void KSwap(int k){

    int n = count();

    if(k > n || k <= 0 || 2 * k - 1 == n){
        printf("Invalid K");
        return;
    }

    struct Node *prev = NULL;
    struct Node *save = first;
    
    int count = 1;

    while (count < k)
    {
        count++;
        prev = save;
        save = save->link;
    }

    count = 1;

    struct Node *prev2 = NULL;
    struct Node *save2 = first;

    while(count < (n - k + 1)){
        count++;
        prev2 = save2;
        save2 = save2->link;
    }

    if(prev != NULL){
        prev->link = save2;
    }
    else{
        first = save2;
    }

    if(prev2 != NULL){
        prev2->link = save;
    }
    else{
        first = save;
    }

    struct Node *temp = save->link;
    save->link = save2->link;
    save2->link = temp;
    
}

void main(){

    insertAtFirst(6);
    insertAtFirst(5);
    insertAtFirst(4);
    insertAtFirst(3);
    insertAtFirst(2);
    insertAtFirst(1);

    display();

    int k;

    printf("Enter k:");
    scanf("%d",&k);

    KSwap(k);

    display();

}