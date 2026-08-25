//Write a program to construct a binary tree from given Postorder and Preorder 
//traversal sequence.

#include<stdio.h>
#include<stdlib.h>

struct TreeNode{
    int data;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode * root = NULL;

struct TreeNode * CreateNode(int data){
    struct TreeNode * newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));

    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
}

struct TreeNode* ConstructBinaryTree(int pre[], int post[], int *preindex, int l, int h, int size) {
  
    if (*preindex >= size || l > h) {
        return NULL;
    }

    struct TreeNode* node = CreateNode(pre[*preindex]);
    (*preindex)++;

    if (l == h || *preindex >= size) {
        return node;
    }

    int i;
    for (i = l; i <= h; i++) {
        if (post[i] == pre[*preindex]) {
            break;
        }
    }

    if (i <= h) {
        node->left = ConstructBinaryTree(pre, post, preindex, l, i, size);
        node->right = ConstructBinaryTree(pre, post, preindex, i + 1, h - 1, size);
    }

    return node;
}

struct TreeNode* ConstructFinalTree(int pre[], int post[], int size) {
    int preindex = 0;
    return ConstructBinaryTree(pre, post, &preindex, 0, size - 1, size);
}

void Inorder(struct TreeNode* root){
    if(root != NULL){
        Inorder(root->left);
        printf("%d ",root->data);
        Inorder(root->right);
    }
}

void main (){
    int pre[] = {1, 2, 4, 5, 3, 6, 7};
    int post[] = {4, 5, 2, 6, 7, 3, 1};

    int size = sizeof(pre)/sizeof(pre[0]);

    root = ConstructFinalTree(pre, post, size);

    Inorder(root);

    printf("\n");
}