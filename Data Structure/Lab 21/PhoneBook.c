// Write a program to implement phone book dictionary using Binary Search Tree 
// which provides following operations: 
//  Add new entry in phone book,  
//  Remove entry from phone book,  
//  Search phone number  
//  List all entries in ascending order of name and 
//  List all entries in descending order of name 

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct TreeNode{
    char Name[100];
    char PhoneNo[20];
    struct TreeNode* left;
    struct TreeNode* right;
};

//Function to create new node

struct TreeNode* CreateNode(char* name,char* phone){
    struct TreeNode* root = (struct TreeNode*)malloc(sizeof(struct TreeNode));

    strcpy(root->Name , name);
    strcpy(root->PhoneNo , phone);
    root->left = NULL;
    root->right = NULL;

    return root;
}

struct TreeNode* Insert(struct TreeNode *root, char* name, char* phone){
    if(root == NULL){
        return CreateNode(name , phone);
    }

    if(strcmp(root->Name, name) == 0){
        return root;
    }

    else if(strcmp(root->Name, name) > 0){
        root->left = Insert(root->left, name , phone);
    }
    
    else{
        root->right = Insert(root->right, name , phone);
    }
    return root;
}

//Additional function to find min value from given tree
struct TreeNode* Min(struct TreeNode* root){
    struct TreeNode* save = root;

    while(save != NULL && save->left != NULL){
        save = save->left;
    }
    return save;
}

struct TreeNode* Delete(struct TreeNode* root,char* name){

    if(root == NULL){
        printf("Value not found!!");
        return root;
    }

    if(strcmp(name , root->Name) < 0){
        root->left = Delete(root->left, name);
    }

    else if(strcmp(name , root->Name) > 0){
        root->right = Delete(root->right, name);
    }

    else{//root->key = key
        if(root->left == NULL){
            struct TreeNode* save = root->right;

            free(root);
            return save;
        }
        else if(root->right == NULL){
            struct TreeNode* save = root->left;

            free(root);
            return save;
        }

        struct TreeNode* temp = Min(root->right);
        strcpy(root->Name , temp->Name);
        strcpy(root->PhoneNo , temp->PhoneNo);

        root->right = Delete(root->right,temp->Name);
    }
    return root;
}

//Function to search

struct TreeNode* Search(struct TreeNode* root,char* phone){
    if(root == NULL || strcmp(root->PhoneNo, phone)){
        return root;
    }

    if((root->PhoneNo, phone) > 0){
        return Search(root->right, phone);
    }
    return Search(root->left, phone);
}

//Ascending order

void Ascending(struct TreeNode* root){
    if(root != NULL){
        Ascending(root->right);
        printf("%s |",root->Name);
        printf("%s ||",root->PhoneNo);
        Ascending(root->left);
    }
}

//Descending order

void Descending(struct TreeNode* root){
    if(root != NULL){
        Descending(root->left);
        printf("%s |",root->Name);
        printf("%s ||",root->PhoneNo);
        Descending(root->right);
    }
}

void main() {
    
    struct TreeNode* root = NULL;
    int choice;
    char name[50];
    char phone[15];

    while (1) {
        printf("\n--- Phone Book Dictionary Menu ---\n");
        printf("1. Add new entry\n");
        printf("2. Remove entry\n");
        printf("3. Search \n");
        printf("4. List entries in ascending order\n");
        printf("5. List entries in descending order\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        

        switch (choice) {
            case 1:
                printf("Enter name: ");
                scanf("%s", name);

                printf("Enter phone number: ");
                scanf("%s", phone);

                root = Insert(root, name, phone);
                break;

            case 2:
                printf("Enter name to remove: ");
                scanf("%s", name);
                root = Delete(root, name);
                break;

            case 3:
                printf("Enter name to search: ");
                scanf("%s", name);
                
                struct TreeNode *searchResult = Search(root, name);
                if(searchResult != NULL) {
                    printf("Value found in the tree.\n");
                } else {
                    printf("Value NOT found in the tree.\n");
                }
                break;

            case 4:
                printf("\n--- Phone Book Entries (A to Z) ---\n");
                Ascending(root);
                break;

            case 5:
                printf("\n--- Phone Book Entries (Z to A) ---\n");
                Descending(root);
                break;

            case 6:
                printf("Exiting program.\n");
                exit(0);

            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
}
