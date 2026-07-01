//Write a program to implement a node structure for singly linked list. Read the 
//data in a node, print the node. 

#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int info;
    struct Node* link;
};

void main(){

    struct Node* node = (struct Node*)malloc(sizeof  (struct Node*));

    if(node == NULL){
        printf("Memory Allocation Failed!");
        return;
    }

    printf("Enter data of node:");
    scanf("%d",&(node -> info));

    node -> link = NULL;

    printf("Node data : %d",node -> info);

    free(node);

}