//WAP to perform given operation in the linked list. There exist a Linked List. Add 
//a node that contains the GCD of those two nodes between every pair adjacent 
//node of Linked List. 

//Input : 18 ----> 6 ----> 10 ----> 3
//Output : 18 --> 6 --> 6 --> 2 --> 10 --> 1 --> 3

#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int info;
    struct Node *link;
};

struct Node *first = NULL;

void insertAtFirst(int x){

    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));

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

int min(int a, int b){
    if(a < b){
        return a;
    }
    return b;
}

int find_gcd(int a, int b){

    for(int i = min(a,b) ; i >= 1 ; i--){
        if(a % i == 0 && b % i == 0){
            return i;
        }
    }
    return 1;
}

void GCD(){
    if(first == NULL || first->link == NULL){
        return;
    }

    struct Node *save = first;

    while(save->link != NULL){

        struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
        
        newNode->info = find_gcd(save->info,save->link->info);
        newNode->link = save->link;
        save->link = newNode;

        //to direct jump to third
        save = save->link->link;
    }
}

void main(){

    insertAtFirst(3);
    insertAtFirst(10);
    insertAtFirst(6);
    insertAtFirst(18);

    display();

    GCD();

    display();
}
 