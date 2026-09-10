// WAP to find the smallest and largest elements in the Binary Search Tree. 

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

int FindMin(struct TreeNode* root){
    struct TreeNode * save = root;

    while(save->left != NULL){
        save = save->left;
    }
    return save->key;
}

int FindMax(struct TreeNode* root){
    struct TreeNode * save = root;

    while(save->right != NULL){
        save = save->right;
    }
    return save->key;
}

void main(){

    struct TreeNode* tree = NULL;
    tree = Insert(tree, 8);
    tree = Insert(tree, 6);
    tree = Insert(tree, 5);
    tree = Insert(tree, 4);
    tree = Insert(tree, 3);
    tree = Insert(tree, 2);

    int min = FindMin(tree);
    int max = FindMax(tree);

    printf("Smallest value is : %d\n",min);
    printf("Largest value is : %d",max);
}