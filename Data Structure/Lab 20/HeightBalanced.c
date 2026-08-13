//  Given a binary tree, determine if it is height-balanced (A height-balanced binary 
// tree is a binary tree in which the depth of the two subtrees of every node never 
// differs by more than one). 

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<math.h>

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
}

struct TreeNode* Insert(struct TreeNode *root){
    int data;

    printf("Enter data(-1 for no node) :");
    scanf("%d",&data);

    if(data == -1){
        return NULL;
    }

    struct TreeNode * newNode = CreateNode(data);

    printf("Enter data for left branch of tree:");
    newNode->left = Insert(newNode->left);

    printf("Enter data for right branch of tree:");
    newNode->right = Insert(newNode->right);

    return newNode;
}

int max(int n1 , int n2){
    if(n1 > n2){
        return n1;
    }
    return n2;

}

int findHeight(struct TreeNode* root){

    if(root == NULL){
        return 0;
    }

    int lefth = findHeight(root->left);
    int righth = findHeight(root->right);

    return(max(lefth,righth)) + 1;
}

bool IsHeightbalanced(struct TreeNode* root){
    if(root == NULL){
        return true;
    }

    int h1 = findHeight(root->left);
    int h2 = findHeight(root->right);

    if(abs(h1 - h2) > 1){
        return false;
    }

    bool isLeftbalanced = IsHeightbalanced(root->left);
    bool isRightbalanced = IsHeightbalanced(root->right);

    return isLeftbalanced && isRightbalanced;

}

void main(){
    bool res;

    struct TreeNode* tree1 = NULL;

    tree1 = Insert(tree1);

    res = IsHeightbalanced(tree1);

    if(res == true){
        printf("Given trees is height balanced.");
    }
    else{
        printf("Given trees is not height balanced.");
    }

}