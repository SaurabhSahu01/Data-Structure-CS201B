#include<stdio.h>
#include"BuildTree.h"

TreeNode* buildTreeFromArray(int numberOfNodes, int nodes[numberOfNodes]){
    // empty tree condition
    if(numberOfNodes == 0 || nodes[0] == -1){
        return NULL;
    }

    Queue q;
    init(&q);
    TreeNode* root = createTreeNode(nodes[0]); 
    enqueue(&q, root);

    int i = 1;

    while(!isEmpty(&q) && i < numberOfNodes){
        TreeNode* curr = dequeue(&q);

        // initialise the left child
        if(i < numberOfNodes){
            if(nodes[i] != -1){
                curr->left = createTreeNode(nodes[i]);
                enqueue(&q, curr->left);
            }
            else{
                curr->left = NULL;
            }
            i++;
        }
        // initialise the right child
        if(i < numberOfNodes){
            if(nodes[i] != -1){
                curr->right = createTreeNode(nodes[i]);
                enqueue(&q, curr->right);
            }
            else{
                curr->right = NULL;
            }
            i++;
        }
    }
    return root; 
}