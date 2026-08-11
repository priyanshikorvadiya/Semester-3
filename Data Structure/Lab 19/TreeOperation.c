//  Write a menu driven program to implement Binary Search Tree (BST) & perform 
// following operations:  
//  Insert a node 
//  Delete a node 
//  Search a node 
//  Preorder Traversal 
//  Postorder Traversal 
//  Inorder Traversal

#include<stdio.h>
#include<stdlib.h>

struct TreeNode{
    int key;
    struct TreeNode *left;
    struct TreeNode *right;
};

//Function to create new node

struct TreeNode* CreateNode(int x){
    struct TreeNode* root = (struct TreeNode*)malloc(sizeof(struct TreeNode));

    root->key = x;
    root->left = NULL;
    root->right = NULL;

    return root;
}

struct TreeNode* Insert(struct TreeNode *root, int val){
    if(root == NULL){
        return CreateNode(val);
    }

    if(root->key == val){
        return root;
    }

    else if(root->key < val){
        root->right = Insert(root->right, val);
    }
    
    else{
        root->left = Insert(root->left, val);
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

struct TreeNode* Delete(struct TreeNode* root,int key){

    if(root == NULL){
        printf("Value not found!!");
        return root;
    }

    if(key < root->key){
        root->left = Delete(root->left, key);
    }

    else if(key > root->key){
        root->right = Delete(root->right, key);
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
        root->key = temp->key;

        root->right = Delete(root->right,temp->key);
    }
    return root;
}

struct TreeNode* Search(struct TreeNode* root,int key){
    if(root == NULL || root->key == key){
        return root;
    }

    if(root->key < key){
        return Search(root->right,key);
    }
    return Search(root->left,key);
}

void Inorder(struct TreeNode* root){
    if(root != NULL){
        Inorder(root->left);
        printf("%d ",root->key);
        Inorder(root->right);
    }
}

void Preorder(struct TreeNode* root){
    if(root != NULL){
        printf("%d ",root->key);
        Preorder(root->left);
        Preorder(root->right);
    }
}

void Postorder(struct TreeNode* root){
    if(root != NULL){
        Postorder(root->left);
        Postorder(root->right);
        printf("%d ",root->key);
    }
}

void main() {
    struct TreeNode* root = NULL;
    int choice, val;
    struct TreeNode* searchResult = NULL;

    while(1) {
        printf("\n------- BST MENU -------");
        printf("\n1. Insert a node");
        printf("\n2. Delete a node");
        printf("\n3. Search a node");
        printf("\n4. Preorder Traversal");
        printf("\n5. Inorder Traversal");
        printf("\n6. Postorder Traversal");
        printf("\nEnter your choice (1-7): ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &val);
                root = Insert(root, val);
                printf("Node inserted successfully.\n");
                break;

            case 2:
                printf("Enter value to delete: ");
                scanf("%d", &val);
                root = Delete(root, val);
                break;

            case 3:
                printf("Enter value to search: ");
                scanf("%d", &val);
                searchResult = Search(root, val);
                if(searchResult != NULL) {
                    printf("Value %d found in the tree.\n", val);
                } else {
                    printf("Value %d NOT found in the tree.\n", val);
                }
                break;

            case 4:
                printf("Preorder Traversal: ");
                Preorder(root);
                printf("\n");
                break;

            case 5:
                printf("Inorder Traversal: ");
                Inorder(root);
                printf("\n");
                break;

            case 6:
                printf("Postorder Traversal: ");
                Postorder(root);
                printf("\n");
                break;

            default:
                printf("Invalid choice! Please select between 1 and 7.\n");
        }
    }
}