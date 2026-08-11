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

    tree1 = Insert(tree1, 3);
    tree1 = Insert(tree1, 2);
    tree1 = Insert(tree1, 1);
    tree1 = Insert(tree1, 4);

    struct TreeNode* tree2 = NULL;

    tree2 = Insert(tree2, 3);
    tree2 = Insert(tree2, 2);
    tree2 = Insert(tree2, 1);
    tree2 = Insert(tree2, 4);

    res = IsSame(tree1 , tree2);

    if(res == true){
        printf("Given trees are same.");
    }
    else{
        printf("Given trees are not same.");
    }

}