// Write a program to simulate music player application using suitable data 
// structure. There is no estimation about number of music files to be managed by 
// the music player. Your program should support all the basic music player 
// operations to play and manage the playlist. 

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Node{
    char info[100];
    struct Node *lptr;
    struct Node *rptr;
};

struct Node *first = NULL;

void InsertAtFirst(char x[]){
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    
    if(first == NULL){
        newNode->lptr = NULL;
        strcpy(newNode->info,x);
        newNode->rptr = NULL;

        first = newNode;
    }

    else{
        newNode->rptr = first;
        strcpy(newNode->info,x);
        newNode->lptr = NULL;
        first->lptr = newNode;
        first= newNode;
    }
}

void Display(){
    
    if(first == NULL){
        printf("Empty List!!");
        return;
    }

    struct Node *save = first;

    while(save != NULL){
        printf("%s ->",save->info);
        save = save->rptr;  
    }
    printf("NULL\n");
}

void PlayPrevious(){
    struct Node *save = first;

    if(first == NULL){
        printf("Empty List!!");
        return;
    }

    if(save != NULL){
        save = save->lptr;
        printf("Playing previous : %s\n",save->info);
    }
    else{
        printf("No songs available.");
    }
}

void PlayNext(){
    struct Node *save = first;

    if(first == NULL){
        printf("Empty List!!");
        return;
    }

    if(save != NULL){
        save = save->rptr;
        printf("Playing next : %s\n",save->info);
    }
    else{
        printf("No songs available.");
    }
}

void main(){
    InsertAtFirst("Preet re");
    InsertAtFirst("Bairan");
    InsertAtFirst("Prem ki lila");
    InsertAtFirst("Ishq hai");

    Display();

    PlayNext();

    PlayPrevious();
}