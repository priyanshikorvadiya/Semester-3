// Write a program to create a graph & implement the adjacency list 
// representation of the graph 
//  Apply DFS and BFS on the given graph.

#include<stdio.h>
#include<stdlib.h>

#define MAX 20

struct Node{
    int info;
    struct Node *link;
};

struct Node * F = NULL;
struct Node * R = NULL;

void ENQUEUE(int x){
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));

    if(newNode == NULL){
        printf("Memory Allocation Failed!");
        return;
    }

    newNode->info = x;
    newNode->link = NULL;

    if(R == NULL){
        F = R = newNode;
    }
    else{
        R->link = newNode;
        R = newNode;
    }
}

int DEQUEUE(){
    if(F == NULL){
        printf("Queue underflow!!");
        return 0;
    }

    struct Node *temp = F;
    int val = temp->info; 

    F = F->link;

    if(F == NULL){
        R = NULL;
    }
    free(temp);
    return val; 
}

struct Node* adjList[MAX];
int v;

void addEdge(int src, int dest){
    //Add dest to src
    struct Node* newNode = (struct Node *)malloc(sizeof(struct Node));

    newNode->info = dest;
    newNode->link = adjList[src];

    adjList[src] = newNode;

    newNode = (struct Node*)malloc(sizeof(struct Node));

    newNode->info = src;
    newNode->link = adjList[dest];

    adjList[dest] = newNode;
}

void DFS(int v, int visited[]){
    visited[v] = 1;
    printf("%d ", v); 

    struct Node *save = adjList[v];

    while(save != NULL){
        if(visited[save->info] == 0){
            DFS(save->info, visited);
        }
        save = save->link; 
    }
}

void BFS(int start){
    int visited[MAX] = {0};

    visited[start] = 1;
    ENQUEUE(start);

    while(F != NULL){
        int v = DEQUEUE();
        printf("%d ", v);

        struct Node *save = adjList[v];

        while (save != NULL)
        {
            if(visited[save->info] == 0){
                visited[save->info] = 1;
                ENQUEUE(save->info);
            }
            save = save->link;
        }
    }
}

void Display(int i){
    struct Node *save = adjList[i];

    while(save != NULL){
        printf("%d ->",save->info); 
        save = save->link;
    }

    printf("NULL\n");
}

void main(){ 

    for(int i = 0; i < MAX; i++) {
        adjList[i] = NULL;
    }

    addEdge(0, 1);
    addEdge(0, 2);
    addEdge(0, 3);
    addEdge(1, 2);
    addEdge(2, 3);

    printf("Adjacency List:\n");
    for(int i = 0; i < 4; i++){ 
        Display(i);
    }

    int visited[MAX] = {0}; 
    printf("\nDFS Traversal:\n");
    DFS(0, visited);

    printf("\nBFS Traversal:\n");
    BFS(0);
    printf("\n");

}
