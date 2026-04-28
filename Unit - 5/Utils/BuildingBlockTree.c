#include<stdlib.h>
#include"BuildingBlockTree.h"

TreeNode* createTreeNode(int x){
    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
    if(newNode != NULL){
        newNode->data = x;
        newNode->left = newNode->right = NULL;
    }
    return newNode;
}