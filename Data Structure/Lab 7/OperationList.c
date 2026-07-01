//  Write a menu driven program to implement following operations on the singly 
// linked list.  
//  Insert a node at the front of the linked list. 
//  Display all nodes. 
//  Delete a first node of the linked list. 
//  Insert a node at the end of the linked list. 
//  Delete a last node of the linked list. 
//  Delete a node from specified position. 
//  Count the no. of nodes in the linked list. 

#include<stdio.h>
#include<stdlib.h>

struct Node {
    int info;
    struct Node* link;
};

struct Node* first = NULL;

void main() {
    int choice = 0, val, pos;

    while (1) {
        printf("\n--- Singly Linked List Menu ---\n");
        printf("1-Insert at front.\n");
        printf("2-Display all nodes.\n");
        printf("3-Delete first node.\n");
        printf("4-Insert at end.\n");
        printf("5-Delete last node.\n");
        printf("6-Delete from specified position.\n");
        printf("7-Count total nodes.\n");
        printf("8-Exit\n");

        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert at front: ");
                scanf("%d", &val);
                first = insertFront(first, val);
                break;
            case 2:
                displayList(first);
                break;
            case 3:
                first = deleteFront(first);
                break;
            case 4:
                printf("Enter value to insert at end: ");
                scanf("%d", &val);
                first = insertEnd(first, val);
                break;
            case 5:
                first = deleteEnd(first);
                break;
            case 6:
                printf("Enter position to delete (1-based index): ");
                scanf("%d", &pos);
                first = deletePosition(first, pos);
                break;
            case 7:
                printf("Total number of nodes: %d\n", countNodes(first));
                break;
            case 8:
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }
}

struct Node* insertFront(struct Node *first, int val) {

    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node)); 

     if (newNode == NULL) {
        printf("Memory Allocation Failed!\n");
        return first;
    }
    newNode->info = val;
    newNode->link = first;
    first = newNode; 
    return first; 
}

void displayList(struct Node *first) {
    if (first == NULL) {
        printf("List is Empty!\n");
        return;
    }
    struct Node *save = first;
    while (save != NULL) {
        printf("%d -> ", save->info);
        save = save->link;
    }
    printf("NULL\n");
}

struct Node* deleteFront(struct Node *first) {
    if (first == NULL) {
        printf("List is empty.\n");
        return NULL;
    }
    struct Node *temp = first;
    first = first->link;
    free(temp);
    return first;
}

struct Node* insertEnd(struct Node *first, int val) {
    
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node)); 
    if (newNode == NULL) {
        printf("Memory Allocation Failed!\n");
        return first;
    }
    
    newNode->info = val;
    newNode->link = NULL;

    if (first == NULL) {
        first = newNode;
    } else {
        struct Node *save = first;
        while (save->link != NULL) {
            save = save->link;
        }
        save->link = newNode;
    }
    return first;
}

struct Node* deleteEnd(struct Node *first) {
    if (first == NULL) {
        printf("List is empty.\n");
        return NULL;
    }
    if (first->link == NULL) {
        free(first);
        return NULL;
    }
    
    struct Node *pred = NULL;
    struct Node *save = first;
    while (save->link != NULL) {
        pred = save;
        save = save->link;
    }
    free(save);
    pred->link = NULL;
    return first;
}

struct Node* deletePosition(struct Node *first, int pos) {
    if (first == NULL) {
        printf("List is Empty.\n");
        return NULL;
    }
    
    // Added safety for invalid/negative position entries
    if (pos < 1) {
        printf("Invalid position.\n");
        return first;
    }

    struct Node *save = first;

    if (pos == 1) {
        first = save->link;
        free(save);
        return first;
    }

    struct Node *pred = NULL;
    int i = 1;
    while (i < pos && save != NULL) {
        pred = save;
        save = save->link;
        i++;
    }

    // This checks if the user entered a number higher than total nodes
    if (save == NULL) {
        printf("Position out of range.\n");
        return first;
    }

    pred->link = save->link;
    free(save);
    return first;
}

int countNodes(struct Node *first) {
    struct Node *save = first;
    int count = 0;
    while (save != NULL) {
        count++;
        save = save->link;
    }
    return count;
}
