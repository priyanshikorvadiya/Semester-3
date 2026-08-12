// Write a program to check whether the given two trees are same or not. 

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

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

bool IsSame(struct TreeNode* r1, struct TreeNode* r2){
    if(r1 == NULL && r2 == NULL){
        return true;
    }
    else if (r1 == NULL || r2 == NULL){
        return false;
    }
    else{
        return (r1->key == r2->key) && IsSame(r1->left,r2->left) && IsSame(r1->right,r2->right);
    }
}

void main(){
    bool res;

    struct TreeNode* tree1 = NULL;

    tree1 = Insert(tree1);

    struct TreeNode* tree2 = NULL;

    tree2 = Insert(tree2);

    res = IsSame(tree1 , tree2);

    if(res == true){
        printf("Given trees are same.");
    }
    else{
        printf("Given trees are not same.");
    }

}