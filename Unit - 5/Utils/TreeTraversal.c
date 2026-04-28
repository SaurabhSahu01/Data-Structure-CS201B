#include<stdio.h>
#include"TreeTraversal.h"

void dfs(TreeNode* root){
    if(root == NULL){
        return;
    }
    printf("%d ", root->data);
    dfs(root->left);
    dfs(root->right);
    return;
}
