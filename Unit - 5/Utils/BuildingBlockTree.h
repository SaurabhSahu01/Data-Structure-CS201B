#ifndef BUILDINGBLOCKTREE_H
#define BUILDINGBLOCKTREE_H

typedef struct TreeNode{
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
}TreeNode;
TreeNode* createTreeNode(int);

#endif